//------------------------------------------------------------------------------
//  Name:           motors.c
//  Description:    This source file contains all of the function implementations needed
//                  to control the motors.
//  Author:         Biruk Kebede
//  Date:           Sep 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#include  <msp430.h>
#include  "inc\ports.h"
#include  "inc\motors.h"

void both_motors_off() {
    P6OUT &= ~(R_FORWARD | R_REVERSE | L_FORWARD | L_REVERSE); // Turn all wheels off
}

void right_motor_forward() {
    P6OUT &= ~R_REVERSE;                // Turn off reverse path
    P6OUT |= R_FORWARD;                 // Turn on forward path
}

void right_motor_backward() {
    P6OUT &= ~R_FORWARD;                // Turn off forward path
    P6OUT |= R_REVERSE;                 // Turn on reverse path
}

void right_motor_off() {
    P6OUT &= ~(R_FORWARD | R_REVERSE); // Turn right wheel off
}

void left_motor_forward() {
    P6OUT &= ~L_REVERSE;                // Turn off reverse path
    P6OUT |= L_FORWARD;                 // Turn on forward path
}

void left_motor_backward() {
    P6OUT &= ~L_FORWARD;                // Turn off forward path
    P6OUT |= L_REVERSE;                 // Turn on reverse path
}

void left_motor_off() {
    P6OUT &= ~(L_FORWARD | L_REVERSE);  // Turn left wheel off
}
