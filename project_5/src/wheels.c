#include "inc/wheels.h"
#include "inc/globals.h"
#include "inc/motors.h"
#include "inc/macros.h"
#include "msp430.h"


// from globals.h
unsigned int wheels_counter = 0;
unsigned char straight_calib[2] = {11, 18};
unsigned char cw_circle_calib[2] = {16, 7};
unsigned char ccw_circle_calib[2] = {3, 16};
unsigned char cw_turn_calib[2] = {17, 3};
unsigned char ccw_turn_calib[2] = {1, 19};
unsigned int movement_ticks = 0;

/*
void wheels_process() {
    // TODO: Keep track of time and update wheels_c
    if (time_changed) {
    wheels_counter++;
    movement_ticks++;
    }
    if (wheels_counter >= 20) wheels_counter = 0;
}
*/

/*

switch(current_shape) {
        case 'S':
            straight(straight_calib, 500);
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
    
*/

unsigned char straight(unsigned char calib[], unsigned int duration_in_ms) {
    // TODO: make the car go straight for a given duration

    unsigned int duration_in_ticks = ( (duration_in_ms * 10UL) + 63UL) / 64UL; // using unsigned long for calc to prevent overflow with large delays
    unsigned char left_duty = calib[0];
    unsigned char right_duty = calib[1];

    if (movement_ticks < duration_in_ticks) {
        if (wheels_counter < left_duty) {
            left_motor_forward();
        } else {
            left_motor_off();
        }
        if (wheels_counter < right_duty) {
            right_motor_forward();
        } else {
            right_motor_off();
        }
        return NOT_DONE;
    } else {
        both_motors_off();
        return DONE;
    }
}

unsigned char cw_circle(unsigned char calib[], unsigned int duration_in_ms) {
    // TODO: make the car go in a clockwise circle for a given duration
    unsigned int duration_in_ticks = ( (duration_in_ms * 10UL) + 63UL) / 64UL; // using unsigned long for calc to prevent overflow with large delays
    unsigned char left_duty = calib[0];
    unsigned char right_duty = calib[1];

    if (movement_ticks < duration_in_ticks) {
        if (wheels_counter < left_duty) {
            left_motor_forward();
        } else {
            left_motor_off();
        }
        if (wheels_counter < right_duty) {
            right_motor_forward();
        } else {
            right_motor_off();
        }
        return NOT_DONE;
    } else {
        both_motors_off();
        return DONE;
    }
}

unsigned char ccw_circle(unsigned char calib[], unsigned int duration_in_ms) {
    // TODO: make the car go in a counter clockwise circle for a given duration
    unsigned int duration_in_ticks = ( (duration_in_ms * 10UL) + 63UL) / 64UL; // using unsigned long for calc to prevent overflow with large delays
    unsigned char left_duty = calib[0];
    unsigned char right_duty = calib[1];

    if (movement_ticks < duration_in_ticks) {
        if (wheels_counter < left_duty) {
            left_motor_forward();
        } else {
            left_motor_off();
        }
        if (wheels_counter < right_duty) {
            right_motor_forward();
        } else {
            right_motor_off();
        }
        return NOT_DONE;
    } else {
        both_motors_off();
        return DONE;
    }
}

unsigned char cw_turn(unsigned char calib[], unsigned int duration_in_ms) {
    // TODO: make the car turn clockwise for a given duration
    unsigned int duration_in_ticks = ( (duration_in_ms * 10UL) + 63UL) / 64UL; // using unsigned long for calc to prevent overflow with large delays
    unsigned char left_duty = calib[0];
    unsigned char right_duty = calib[1];

    if (movement_ticks < duration_in_ticks) {
        if (wheels_counter < left_duty) {
            left_motor_forward();
        } else {
            left_motor_off();
        }
        if (wheels_counter < right_duty) {
            right_motor_forward();
        } else {
            right_motor_off();
        }
        return NOT_DONE;
    } else {
        both_motors_off();
        return DONE;
    }
}

unsigned char ccw_turn(unsigned char calib[], unsigned int duration_in_ms) {
    // TODO: make the car turn clockwise for a given duration
    unsigned int duration_in_ticks = ( (duration_in_ms * 10UL) + 63UL) / 64UL; // using unsigned long for calc to prevent overflow with large delays
    unsigned char left_duty = calib[0];
    unsigned char right_duty = calib[1];

    if (movement_ticks < duration_in_ticks) {
        if (wheels_counter < left_duty) {
            left_motor_forward();
        } else {
            left_motor_off();
        }
        if (wheels_counter < right_duty) {
            right_motor_forward();
        } else {
            right_motor_off();
        }
        return NOT_DONE;
    } else {
        both_motors_off();
        return DONE;
    }
}


