//------------------------------------------------------------------------------
//  Name:           timers.h
//  Description:    This header file contains the function implenetations for configuring timer peripherals.
//  Author:         Biruk Kebede
//  Date:           Sep 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#include <msp430.h>
#include "inc/timers.h"
#include "inc/macros.h"
#include "inc/globals.h"
#include "inc/ports.h"

void Init_Timers() {
    Init_Timer_B0();
    Init_Timer_B2();
    Init_Timer_B3();
}

void Init_Timer_B0(){
    TB0CTL = MC__STOP; // Halt timer
    TB0CTL |= TBCLR; // Clear TB0R, clock divider logic, and count direction
    TB0CTL |= TBSSEL__SMCLK; // Select 8 MHz SMCLK as clock input
    TB0CTL |= ID__8; // Set clock input divider to 8 (8 MHz SMCLK / 8 = 1 MHz)

    TB0EX0 |= TBIDEX__8; // Divide clock by 8 again (8 MHZ SMCLK / 8 / 8 = 125 kHz)
    
    TB0CCR0 = TB0CCR0_PERIOD; // Timer counts from 0 - 124 before restarting - achieves 1 ms tick

    TB0CCTL0 |= CCIE; // Enables interrupts for all CCRn   
    TB0CTL |= MC__UP; // Begins timer in up mode (count to CCR0, reset, repeat)
}

volatile unsigned long elapsed_ms = 0;
#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR() {
    elapsed_ms++;
    // TB0CCTL CCIFG bit is cleared automatically by hardware
}

void Init_Timer_B2(){
    TB2CTL = MC__STOP; // Halt timer
    TB2CTL |= TBCLR; // Clear TB0R, clock divider logic, and count direction
    TB2CTL |= TBSSEL__SMCLK; // Select 8 MHz SMCLK as clock input
    TB2CTL |= ID__8; // Set clock input divider to 8 (8 MHz SMCLK / 8 = 1 MHz)

    TB2EX0 |= TBIDEX__8; // Divide clock by 8 again (8 MHZ SMCLK / 8 / 8 = 125 kHz)
    
    TB2CCR0 = TB2CCR0_PERIOD;

    TB2CCTL0 |= CCIE; // Enables interrupts for all CCRn   
    TB2CTL |= MC__UP; // Begins timer in up mode (count to CCR0, reset, repeat)
}

#pragma vector = TIMER2_B0_VECTOR
__interrupt void Timer2_B0_ISR() {
    P6OUT ^= LCD_BACKLITE; // Toggle LCD Backlight
}

void Init_Timer_B3() {
    TB3CTL = MC__STOP; // Halt timer
    TB3CTL |= TBCLR; // Clear TB0R, clock divider logic, and count direction
    TB3CTL |= TBSSEL__SMCLK; // Select 8 MHz SMCLK as clock input
    TB3CTL |= ID__4; // Set clock input divider to 4 (8 MHz SMCLK / 4 = 2 MHz)

    TB3CCR0 = 100; // Convenient CCR0 period for setting duty cycles on other channels (20 kHz frequency)
    
    // Ensure that all channels initialize LOW
    TB3CCTL2 = OUTMOD_0;
    TB3CCTL3 = OUTMOD_0;
    TB3CCTL4 = OUTMOD_0;
    TB3CCTL5 = OUTMOD_0;
    
    // Set initial duty cycles on all 4 motor pins to 0
    TB3CCR2 = 0;
    TB3CCR3 = 0;
    TB3CCR4 = 0;
    TB3CCR5 = 0;

    TB3CTL |= MC__UP; // Begins timer in up mode (count to CCR0, reset, repeat)
}