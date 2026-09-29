#include "inc/globals.h"
#include "inc/macros.h"
#include "inc/motors.h"
#include "inc/wheels.h"
#include "inc/shapes.h"
#include <string.h>

unsigned char current_shape = 'S';
unsigned char shape_index = 0;
unsigned char shapes[4] = {'S', 'C', 'F', 'T'};
unsigned char current_state = WAIT;
unsigned int pause_ticks = 0;

void shapes_state_machine() {
    if (current_state != WAIT && (sw1_pressed || sw2_pressed)) {
        sw1_pressed = FALSE;
        sw2_pressed = FALSE;
        both_motors_off();
        current_state = SHAPE_DONE;
    }
    
    switch(current_shape) {
        case 'S':
            straight_state_machine();
            break;
        case 'C':
            circle_state_machine();  
            break;
        case 'F':
            figure_8_state_machine();    
            break;
        case 'T':
            triangle_state_machine();    
            break;
        default:
            break;
    }
}

void straight_state_machine() {
    switch(current_state) {
        static unsigned char straight_message_shown = FALSE;
        case WAIT:

            if (!straight_message_shown) {
                strcpy(display_line[0], "STRAIGHT  ");
                strcpy(display_line[1], "SW1: START");
                strcpy(display_line[2], "SW2: NEXT ");
                strcpy(display_line[3], "          ");
                display_changed = TRUE;  
                straight_message_shown = TRUE;
            }
                
            if (sw1_pressed) {
                sw1_pressed = FALSE;
                current_state = START;
                straight_message_shown = FALSE;
                if (sw2_pressed) {
                    sw2_pressed = FALSE;
                }
            }
            if (sw2_pressed) {
                sw2_pressed = FALSE;
                shape_index++;
                if (shape_index >= 4) {
                    shape_index = 0;
                }
                current_shape = shapes[shape_index];
                straight_message_shown = FALSE;
                if (sw1_pressed) {
                    sw1_pressed = FALSE;
                }
            }
            break;
        case START:

            if (!straight_message_shown) {
                strcpy(display_line[0], "STRAIGHT  ");
                strcpy(display_line[1], "STARTING");
                strcpy(display_line[2], "IN 3 SEC");
                strcpy(display_line[3], "WAIT...  ");
                display_changed = TRUE;  
                straight_message_shown = TRUE;
                pause_ticks = 0;
            }

            if (pause_ticks >= PAUSE_TIME) {
                current_state = RUNNING;
                straight_message_shown = FALSE;
                movement_ticks = 0;
                wheels_counter = 0;
            }

            if (time_changed) {
                pause_ticks++; 
            }
            
            break;
        case RUNNING:

            if (!straight_message_shown) {
                strcpy(display_line[0], "STRAIGHT  ");
                strcpy(display_line[1], "          ");
                strcpy(display_line[2], "RUNNING   ");
                strcpy(display_line[3], "          ");
                display_changed = TRUE;  
                straight_message_shown = TRUE;
            }

            unsigned char status;
            status = straight(straight_calib, 5000);
            if (status == DONE) {
                current_state = SHAPE_DONE;
            }            

            break;
        case SHAPE_DONE:
            straight_message_shown = FALSE;
            current_state = WAIT;
            break;
        default:
            break;
    }       
}

void circle_state_machine() {
    switch(current_state) {
        static unsigned char circle_message_shown = FALSE;
        case WAIT:

            if (!circle_message_shown) {
                strcpy(display_line[0], "CIRCLE    ");
                strcpy(display_line[1], "SW1: START");
                strcpy(display_line[2], "SW2: NEXT ");
                strcpy(display_line[3], "          ");
                display_changed = TRUE;  
                circle_message_shown = TRUE;
            }
                
            if (sw1_pressed) {
                sw1_pressed = FALSE;
                current_state = START;
                circle_message_shown = FALSE;
                if (sw2_pressed) {
                    sw2_pressed = FALSE;
                }
            }
            if (sw2_pressed) {
                sw2_pressed = FALSE;
                shape_index++;
                if (shape_index >= 4) {
                    shape_index = 0;
                }
                current_shape = shapes[shape_index];
                circle_message_shown = FALSE;
                if (sw1_pressed) {
                    sw1_pressed = FALSE;
                }
            }
            break;
        case START:

            if (!circle_message_shown) {
                strcpy(display_line[0], "CIRCLE    ");
                strcpy(display_line[1], "STARTING  ");
                strcpy(display_line[2], "IN 3 SEC  ");
                strcpy(display_line[3], "WAIT...   ");
                display_changed = TRUE;  
                circle_message_shown = TRUE;
                pause_ticks = 0;
            }

            if (pause_ticks >= PAUSE_TIME) {
                current_state = RUNNING;
                circle_message_shown = FALSE;
                movement_ticks = 0;
                wheels_counter = 0;
            }

            if (time_changed) {
                pause_ticks++; 
            }
            
            break;
        case RUNNING:

            if (!circle_message_shown) {
                strcpy(display_line[0], "CIRCLE    ");
                strcpy(display_line[1], "          ");
                strcpy(display_line[2], "RUNNING   ");
                strcpy(display_line[3], "          ");
                display_changed = TRUE;  
                circle_message_shown = TRUE;
            }

            unsigned char status;
            status = cw_circle(cw_circle_calib, ONE_CW_CIRCLE_TIME*2);
            if (status == DONE) {
                current_state = SHAPE_DONE;
            }            

            break;
        case SHAPE_DONE:
            circle_message_shown = FALSE;
            current_state = WAIT;
            break;
        default:
            break;
    }
}

void figure_8_state_machine() {
    switch(current_state) {
        static unsigned char f8_message_shown = FALSE;
        static unsigned char step = 1;
        case WAIT:

            if (!f8_message_shown) {
                strcpy(display_line[0], "FIGURE-8  ");
                strcpy(display_line[1], "SW1: START");
                strcpy(display_line[2], "SW2: NEXT ");
                strcpy(display_line[3], "          ");
                display_changed = TRUE;  
                f8_message_shown = TRUE;
            }
                
            if (sw1_pressed) {
                sw1_pressed = FALSE;
                current_state = START;
                f8_message_shown = FALSE;
                if (sw2_pressed) {
                    sw2_pressed = FALSE;
                }
            }
            if (sw2_pressed) {
                sw2_pressed = FALSE;
                shape_index++;
                if (shape_index >= 4) {
                    shape_index = 0;
                }
                current_shape = shapes[shape_index];
                f8_message_shown = FALSE;
                if (sw1_pressed) {
                    sw1_pressed = FALSE;
                }
            }
            break;
        case START:
            if (!f8_message_shown) {
                strcpy(display_line[0], "FIGURE-8  ");
                strcpy(display_line[1], "STARTING  ");
                strcpy(display_line[2], "IN 3 SEC  ");
                strcpy(display_line[3], "WAIT...   ");
                display_changed = TRUE;  
                f8_message_shown = TRUE;
                pause_ticks = 0;
            }

            if (pause_ticks >= PAUSE_TIME) {
                current_state = RUNNING;
                f8_message_shown = FALSE;
                movement_ticks = 0;
                wheels_counter = 0;
            }

            if (time_changed) {
                pause_ticks++; 
            }
            

            break;
        case RUNNING:

            if (!f8_message_shown) {
                strcpy(display_line[0], "FIGURE-8  ");
                strcpy(display_line[1], "          ");
                strcpy(display_line[2], "RUNNING   ");
                strcpy(display_line[3], "          ");
                display_changed = TRUE;  
                f8_message_shown = TRUE;
            }

            unsigned char status;

            if (step == 1) {
                status = cw_circle(cw_circle_calib, ONE_CW_CIRCLE_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 2) {
                status = ccw_circle(ccw_circle_calib, ONE_CCW_CIRCLE_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 3) {
                status = cw_circle(cw_circle_calib, ONE_CW_CIRCLE_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 4) {
                status = ccw_circle(ccw_circle_calib, ONE_CCW_CIRCLE_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step >= 5) {
                current_state = SHAPE_DONE;
            }     

            break;
        case SHAPE_DONE:
            step = 1;
            f8_message_shown = FALSE;
            current_state = WAIT;
            break;
        default:
            break;
    }
}

void triangle_state_machine() {
    switch(current_state) {
        static unsigned char triangle_message_shown = FALSE;
        static unsigned char step = 1;
        case WAIT:

            if (!triangle_message_shown) {
                strcpy(display_line[0], "TRIANGLE  ");
                strcpy(display_line[1], "SW1: START");
                strcpy(display_line[2], "SW2: NEXT ");
                strcpy(display_line[3], "          ");
                display_changed = TRUE;  
                triangle_message_shown = TRUE;
            }
                
            if (sw1_pressed) {
                sw1_pressed = FALSE;
                current_state = START;
                triangle_message_shown = FALSE;
                if (sw2_pressed) {
                    sw2_pressed = FALSE;
                }
            }
            if (sw2_pressed) {
                sw2_pressed = FALSE;
                shape_index++;
                if (shape_index >= 4) {
                    shape_index = 0;
                }
                current_shape = shapes[shape_index];
                triangle_message_shown = FALSE;
                if (sw1_pressed) {
                    sw1_pressed = FALSE;
                }
            }
            break;
        case START:
            if (!triangle_message_shown) {
                strcpy(display_line[0], "TRIANGLE  ");
                strcpy(display_line[1], "STARTING");
                strcpy(display_line[2], "IN 3 SEC");
                strcpy(display_line[3], "WAIT...  ");
                display_changed = TRUE;  
                triangle_message_shown = TRUE;
                pause_ticks = 0;
            }

            if (pause_ticks >= PAUSE_TIME) {
                current_state = RUNNING;
                triangle_message_shown = FALSE;
                movement_ticks = 0;
                wheels_counter = 0;
            }

            if (time_changed) {
                pause_ticks++; 
            }
            break;
        case RUNNING:
            if (!triangle_message_shown) {
                strcpy(display_line[0], "TRIANGLE  ");
                strcpy(display_line[1], "          ");
                strcpy(display_line[2], "RUNNING   ");
                strcpy(display_line[3], "          ");
                display_changed = TRUE;  
                triangle_message_shown = TRUE;
            }

            unsigned char status;

            if (step == 1) {
                status = straight(straight_calib, TRIANGLE_LEG_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 2) {
                status = cw_turn(cw_turn_calib, TRIANGLE_CW_TURN_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 3) {
                status = straight(straight_calib, TRIANGLE_LEG_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 4) {
                status = cw_turn(cw_turn_calib, TRIANGLE_CW_TURN_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 5) {
                status = straight(straight_calib, TRIANGLE_LEG_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 6) {
                status = cw_turn(cw_turn_calib, TRIANGLE_CW_TURN_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 7) {
                status = straight(straight_calib, TRIANGLE_LEG_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 8) {
                status = cw_turn(cw_turn_calib, TRIANGLE_CW_TURN_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 9) {
                status = straight(straight_calib, TRIANGLE_LEG_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 10) {
                status = cw_turn(cw_turn_calib, TRIANGLE_CW_TURN_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 11) {
                status = straight(straight_calib, TRIANGLE_LEG_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step == 12) {
                status = cw_turn(cw_turn_calib, TRIANGLE_CW_TURN_TIME);
                if (status == DONE) {
                    step++;
                    movement_ticks = 0;
                    wheels_counter = 0;
                }
            }

            if (step >= 13) {
                current_state = SHAPE_DONE;
            }

            break;
        case SHAPE_DONE:
            step = 1;
            triangle_message_shown = FALSE;
            current_state = WAIT;
            break;
        default:
            break;
    }
}
