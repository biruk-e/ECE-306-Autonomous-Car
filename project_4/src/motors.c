#include  "inc\premade\functions.h"
#include  "msp430.h"
#include  "inc\macros.h"
#include  "inc\globals.h"
#include  "inc\ports.h"
#include  "inc\motors.h"

void both_motors_off() {
    P6OUT &= ~(R_FORWARD | R_REVERSE | L_FORWARD | L_REVERSE); // Turn all wheels off
}

void right_motor_forward() {
    if (P6OUT & R_REVERSE) {            // If right wheel is in reverse mode
        return;                         // Return immediately to prevent magic smoke
    }
    
    P6OUT |= R_FORWARD;                 // Turn on forward path
}

void right_motor_backward() {
    if (P6OUT & R_FORWARD) {            // If right wheel is in forward mode
        return;                         // Return immediately to prevent magic smoke
    }

    P6OUT |= R_REVERSE;                 // Turn on reverse path
}

void right_motor_off() {
    P6OUT &= ~(R_FORWARD | R_REVERSE); // Turn right wheel off
}

void left_motor_forward() {
    if (P6OUT & L_REVERSE) {            // If left wheel is in reverse mode
        return;                         // Return immediately to prevent magic smoke
    }

    P6OUT |= L_FORWARD;                 // Turn on forward path
}

void left_motor_backward() {
    if (P6OUT & L_FORWARD) {            // If left wheel is in forward mode
        return;                         // Return immediately to prevent magic smoke
    }

    P6OUT |= L_REVERSE;                 // Turn on reverse path
}

void left_motor_off() {
    P6OUT &= ~(L_FORWARD | L_REVERSE);  // Turn left wheel off
}
