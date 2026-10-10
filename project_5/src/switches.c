//------------------------------------------------------------------------------
//  Name:           display.h
//  Description:    This header file contains the function implenentations for reading switch presses.
//  Author:         Biruk Kebede
//  Date:           Oct 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#include "inc/globals.h"
#include "inc/macros.h"
#include "msp430.h"
#include "inc/ports.h"
#include "inc/switches.h"
#include "inc/display.h"

// from globals.h
extern volatile unsigned char sw1_pressed = 0;
extern volatile unsigned long sw1_pressed_time = 0;
extern volatile unsigned long sw2_pressed_time = 0;
extern volatile unsigned char sw2_pressed_ = 0;

void Init_Switches() {
    // Disable switch interrupts before setup
    P4IE &= ~SW1;
    P2IE &= ~SW2;

    sw1_pressed = 0;
    sw2_pressed_ = 0;

    sw1_pressed_time = 0;
    sw2_pressed_time = 0;

    // Clear any interrupts recorded during setup
    P4IFG &= ~SW1;
    P2IFG &= ~SW2;

    // Reenable switch interrupts after setup
    P4IE |= SW1;
    P2IE |= SW2;
}

void switches_process() {
    sw2_process();
    sw1_process();
}

void sw1_process() {
    if (sw1_pressed) {
        display_edit_buffer(" SWITCH 1 ", "          ", "          ", "          ");
        if (elapsed_ms - sw1_pressed_time >= SWITCH_DEBOUNCE_TIME ) {
            sw1_pressed = 0;
            TB2CCTL0 |= CCIE; // Reenable Timer B2 interrupts
            P4IFG &= ~SW1; // Clear any pending sw1 interrupts
            P4IE |= SW1; // Reenable sw1 interrupts
            
            display_edit_buffer("  BLINK!  ", "          ", "          ", "          ");
        }
    }
}

void sw2_process() {
    if (sw2_pressed_) {
        display_edit_buffer(" SWITCH 2 ", "          ", "          ", "          ");
        if (elapsed_ms - sw2_pressed_time >= SWITCH_DEBOUNCE_TIME ) {
            sw2_pressed_ = 0;
            TB2CCTL0 |= CCIE; // Reenable Timer B2 interrupts
            P2IFG &= ~SW2; // Clear any pending sw2 interrupts
            P2IE |= SW2; // Reenable sw1 interrupts
            
            display_edit_buffer("  BLINK!  ", "          ", "          ", "          ");
        }
    }
    
}

#pragma vector = PORT4_VECTOR
__interrupt void switch1_interrupt() {
    if (P4IFG & SW1) {
        sw1_pressed = 1;
        sw1_pressed_time = elapsed_ms; // Save timestamp of when sw1 was pressed
        P4IE &= ~SW1; // Disable sw1 interrupts
        P4IFG &= ~SW1; // Clear sw1 interrupt flag
        P6OUT &= ~LCD_BACKLITE;
        TB2CCTL0 &= ~CCIE;
    }
}

#pragma vector = PORT2_VECTOR
__interrupt void switch2_interrupt() {
    if (P2IFG & SW2) {
        sw2_pressed_ = 1;
        sw2_pressed_time = elapsed_ms; // Save timestamp of when sw1 was pressed
        P2IE &= ~SW2; // Disable sw1 interrupts
        P2IFG &= ~SW2; // Clear sw1 interrupt flag
        P6OUT &= ~LCD_BACKLITE;
        TB2CCTL0 &= ~CCIE;
    }
}
