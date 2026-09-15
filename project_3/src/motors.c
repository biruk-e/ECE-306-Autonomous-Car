#include  "inc\premade\functions.h"
#include  "msp430.h"
#include  "inc\macros.h"
#include  "inc\globals.h"
#include  "inc\ports.h"
#include  "inc\motors.h"

void right_wheel_forward() {
    P6OUT &= ~(R_FORWARD | R_REVERSE);   // Turn off both forward and reverse paths
    __delay_cycles(100);                // Short delay to prevent shoot-through
    P6OUT |= R_FORWARD;                 // Turn on forward path
}

void right_wheel_backward() {
    P6OUT &= ~(R_FORWARD | R_REVERSE);  // Turn off both forward and reverse paths
    __delay_cycles(100);                // Short delay to prevent shoot-through
    P6OUT |= R_REVERSE;                 // Turn on reverse path
}

void left_wheel_forward() {
    P6OUT &= ~(L_FORWARD | L_REVERSE);   // Turn off both forward and reverse paths
    __delay_cycles(100);                // Short delay to prevent shoot-through
    P6OUT |= L_FORWARD;                 // Turn on forward path
}

void left_wheel_backward() {
    P6OUT &= ~(L_FORWARD | L_REVERSE);  // Turn off both forward and reverse paths
    __delay_cycles(100);                // Short delay to prevent shoot-through
    P6OUT |= L_REVERSE;                 // Turn on reverse path
}