//------------------------------------------------------------------------------
//  Name:           ports.c
//  Description:    This source file contains the functions used to write to the registers of
//                  of the MSP430 to initialize the ports and pins upon startup.
//  Author:         Biruk Kebede
//  Date:           Sep 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#include  <msp430.h>
#include  "inc\ports.h"

void Init_Ports(void) {
    Init_Port1();
    Init_Port2();
    Init_Port3();
    Init_Port4();
    Init_Port5();
    Init_Port6();

    // Release GPIO pins from high-impedance mode only after all pins
    // have been configured to their intended initial states.
    PM5CTL0 &= ~LOCKLPM5;   
    
}

void Init_Port1(void) {
    // Default P1 Configurations
    P1OUT  = 0x00; // Sets all pins in P1 to LOW (this only propagates to the pins if P1DIR is set to output)
    P1DIR  = 0x00; // Sets all pins in P1 to INPUT direction
    P1REN  = 0x00; // Disables all P1 PUPD resistors
    P1SEL0 = 0x00; // Sets SEL0 to 0 for all pins in P1 (GPIO)
    P1SEL1 = 0x00; // Sets SEL1 to 0 for all pins in P1 (GPIO)

    // RED_LED Configuration: P1.0
    P1SEL0  &= ~RED_LED;    // Clear P1SEL0.0 -- Select GPIO mode
    P1SEL1  &= ~RED_LED;    // Clear P1SEL1.0 -- Select GPIO mode
    P1REN   &= ~RED_LED;    // Clear P1REN.0 -- Disable PUPD resistor
    P1OUT   &= ~RED_LED;    // Clear P1OUT.0 -- RED_LED initially LOW
    P1DIR   |= RED_LED;     // Set P1DIR.0 -- Configure P1.0 as ouput
}

void Init_Port2(void) {
    // Default P2 Configurations
    P2OUT  = 0x00; // Sets all pins in P2 to LOW (this only propagates to the pins if P2DIR is set to output)
    P2DIR  = 0x00; // Sets all pins in P2 to INPUT direction
    P2REN  = 0x00; // Disables all P2 PUPD resistors
    P2SEL0 = 0x00; // Sets SEL0 to 0 for all pins in P2 (GPIO)
    P2SEL1 = 0x00; // Sets SEL1 to 0 for all pins in P2 (GPIO)

    /*
    // RESET_LCD Configuration: P2.0
    P2SEL0  &= ~RESET_LCD;  // Clear P2SEL0.0 -- Select GPIO mode
    P2SEL1  &= ~RESET_LCD;  // Clear P2SEL1.0 -- Select GPIO mode
    P2REN   &= ~RESET_LCD;  // Clear P2REN.0 -- Disable PUPD resistor
    P2OUT   &= ~RESET_LCD;  // Clear P2OUT.0 -- Hold RESET_LCD LOW initially
    P2DIR   |= RESET_LCD;   // Set P2DIR.0 -- Configure P2.0 as output
    */
    
    // SW2 Configuration: P2.3
    P2SEL0  &= ~SW2;  // Clear P2SEL0.3 -- Select GPIO mode
    P2SEL1  &= ~SW2;  // Clear P2SEL1.3 -- Select GPIO mode
    P2OUT   |= SW2;   // Set P2OUT.3 -- Select pull-up resistor
    P2REN   |= SW2;   // Set P2REN.3 -- Enable PUPD resistor
    P2DIR   &= ~SW2;  // Clear P2DIR.3 -- Configure P2.3 as input

    // LFX crystal configuration 1: P2.6
    P2SEL0 &= ~LFXIN;
    P2SEL1 |= LFXIN;

    // LFX crystal configuration 2: P2.7
    P2SEL0 &= ~LFXOUT;
    P2SEL1 |=  LFXOUT;
}

void Init_Port3(void) {
    // Default P3 Configurations
    P3OUT  = 0x00; // Sets all pins in P3 to LOW (this only propagates to the pins if P3DIR is set to output)
    P3DIR  = 0x00; // Sets all pins in P3 to INPUT direction
    P3REN  = 0x00; // Disables all P3 PUPD resistors
    P3SEL0 = 0x00; // Sets SEL0 to 0 for all pins in P3 (GPIO)
    P3SEL1 = 0x00; // Sets SEL1 to 0 for all pins in P3 (GPIO)
}

void Init_Port4(void) {
    // Default P4 Configurations
    P4OUT  = 0x00; // Sets all pins in P4 to LOW (this only propagates to the pins if P4DIR is set to output)
    P4DIR  = 0x00; // Sets all pins in P4 to INPUT direction
    P4REN  = 0x00; // Disables all P4 PUPD resistors
    P4SEL0 = 0x00; // Sets SEL0 to 0 for all pins in P4 (GPIO)
    P4SEL1 = 0x00; // Sets SEL1 to 0 for all pins in P4 (GPIO)

    // DAC_CNTL1 Configuration: P4.0 
    // [IMPORTANT NOTE: LCD.obj uses this pin as RESET_LCD, so it must be configured as GPIO output]
    P4SEL0 &= ~DAC_CNTL1;    // Clear P4SEL0.0 -- Select GPIO mode
    P4SEL1 &= ~DAC_CNTL1;    // Clear P4SEL1.0 -- Select GPIO mode
    P4REN  &= ~DAC_CNTL1;    // Disable PUPD resistor
    P4OUT  &= ~DAC_CNTL1;    // Clear P4OUT.0 -- DAC_CNTL1 initially low
    P4DIR  |= DAC_CNTL1;     // Set P4DIR.0 -- Configure P4.0 as output

    // SW1 Configuration: P4.1
    P4SEL0  &= ~SW1;  // Clear P4SEL0.1 -- Select GPIO mode
    P4SEL1  &= ~SW1;  // Clear P4SEL1.1 -- Select GPIO mode
    P4OUT   |= SW1;   // Set P4OUT.1 -- Select pull-up resistor
    P4REN   |= SW1;   // Set P4REN.1 -- Enable PUPD resistor
    P4DIR   &= ~SW1;  // Clear P4DIR.1 -- Configure P4.1 as input

    // UCB1_CS_LCD Configuration: P4.4
    P4SEL0 &= ~UCB1_CS_LCD;  // Clear P4SEL0.4 -- Select GPIO mode
    P4SEL1 &= ~UCB1_CS_LCD;  // Clear P4SEL1.4 -- Select GPIO mode
    P4OUT  |= UCB1_CS_LCD;   // Set P4OUT.4 -- UCB1_CS_LCD initially high/inactive
    P4REN  &= ~UCB1_CS_LCD;  // Clear P4REN.4 -- Disable internal pull resistor
    P4DIR  |= UCB1_CS_LCD;   // Set P4DIR.4 -- Configure P4.4 as output

    // UCB1CLK Configuration: P4.5
    P4SEL0  |= UCB1CLK;     // Set P4SEL0.5 -- Select UCB1CLK mode
    P4SEL1  &= ~UCB1CLK;    // Clear P4SEL1.5 -- Select UCB1CLK mode
    P4OUT   &= ~UCB1CLK;    // Clear P4OUT.5 -- UCB1CLK initially low
    P4REN   &= ~UCB1CLK;    // Clear P4REN.5 -- Disable PUPD resistor
    P4DIR   |= UCB1CLK;     // Set P4DIR.5 -- Configure P4.5 as output

    // UCB1SIMO Configuration: P4.6
    P4SEL0  |= UCB1SIMO;     // Set P4SEL0.6 -- Select UCB1SIMO mode
    P4SEL1  &= ~UCB1SIMO;    // Clear P4SEL1.6 -- Select UCB1SIMO mode
    P4OUT   &= ~UCB1SIMO;    // Clear P4OUT.6 -- UCB1SIMO initially low
    P4REN   &= ~UCB1SIMO;    // Clear P4REN.6 -- Disable PUPD resistor
    P4DIR   |= UCB1SIMO;     // Set P4DIR.6 -- Configure P4.6 as output    

    // UCB1SOMI Configuration: P4.7
    P4SEL0  |= UCB1SOMI;     // Set P4SEL0.7 -- Select UCB1SOMI mode
    P4SEL1  &= ~UCB1SOMI;    // Clear P4SEL1.7 -- Select UCB1SOMI mode
    P4OUT   &= ~UCB1SOMI;    // Clear P4OUT.7 -- UCB1SOMI initially low
    P4REN   &= ~UCB1SOMI;    // Clear P4REN.7 -- Disable PUPD resistor
    P4DIR   &= ~UCB1SOMI;    // Clear P4DIR.7 -- Configure P4.7 as input    
}

void Init_Port5(void) {
    // Default P5 Configurations
    P5OUT  = 0x00; // Sets all pins in P5 to LOW (this only propagates to the pins if P5DIR is set to output)
    P5DIR  = 0x00; // Sets all pins in P5 to INPUT direction
    P5REN  = 0x00; // Disables all P5 PUPD resistors
    P5SEL0 = 0x00; // Sets SEL0 to 0 for all pins in P5 (GPIO)
    P5SEL1 = 0x00; // Sets SEL1 to 0 for all pins in P5 (GPIO)
}

void Init_Port6(void) {
    // Default P6 Configurations
    P6OUT  = 0x00; // Sets all pins in P6 to LOW (this only propagates to the pins if P6DIR is set to output)
    P6DIR  = 0x00; // Sets all pins in P6 to INPUT direction
    P6REN  = 0x00; // Disables all P6 PUPD resistors
    P6SEL0 = 0x00; // Sets SEL0 to 0 for all pins in P6 (GPIO)
    P6SEL1 = 0x00; // Sets SEL1 to 0 for all pins in P6 (GPIO)

    // LCD_BACKLITE Configuration: P6.0
    P6SEL0  &= ~LCD_BACKLITE;   // Clear P6SEL0.0 -- Select GPIO mode
    P6SEL1  &= ~LCD_BACKLITE;   // Clear P6SEL1.0 -- Select GPIO mode
    P6OUT   |= LCD_BACKLITE;    // Set P6OUT.0 -- LCD_BACKLITE initially HIGH
    P6REN   &= ~LCD_BACKLITE;   // Clear P6REN.0 -- Disable PUPD resistor
    P6DIR   |= LCD_BACKLITE;    // Set P6DIR.0 -- Configure P6.0 as output
    
    // R_FORWARD Configuration: P6.1
    P6SEL0 |= R_FORWARD;    // Set P6SEL0.1 -- Select TB3.2 function
    P6SEL1 &= ~R_FORWARD;   // Clear P6SEL1.1 -- Select TB3.2 function
    P6OUT  &= ~R_FORWARD;   // Clear P6OUT.1 -- R_FORWARD initially LOW
    P6REN  &= ~R_FORWARD;   // Clear P6REN.1 -- Disable PUPD resistor
    P6DIR  |= R_FORWARD;    // Set P6DIR.1 -- Configure P6.1 as output
    
    // R_REVERSE Configuration: P6.2
    P6SEL0 |= R_REVERSE;    // Set P6SEL0.2 -- Select TB3.3 function
    P6SEL1 &= ~R_REVERSE;   // Clear P6SEL1.2 -- Select TB3.3 function
    P6OUT  &= ~R_REVERSE;   // Clear P6OUT.2 -- R_REVERSE initially LOW
    P6REN  &= ~R_REVERSE;   // Clear P6REN.2 -- Disable PUPD resistor
    P6DIR  |= R_REVERSE;    // Set P6DIR.2 -- Configure P6.2 as output

    // L_FORWARD Configuration: P6.3
    P6SEL0 |= L_FORWARD;    // Clear P6SEL0.3 -- Select TB3.4 function
    P6SEL1 &= ~L_FORWARD;   // Clear P6SEL1.3 -- Select TB3.4 function
    P6OUT  &= ~L_FORWARD;   // Clear P6OUT.3 -- L_FORWARD initially LOW
    P6REN  &= ~L_FORWARD;   // Clear P6REN.3 -- Disable PUPD resistor
    P6DIR  |= L_FORWARD;    // Set P6DIR.3 -- Configure P6.3 as output

    // L_REVERSE Configuration: P6.4
    P6SEL0 |= L_REVERSE;    // Set P6SEL0.4 -- Select TB3.5 function
    P6SEL1 &= ~L_REVERSE;   // Clear P6SEL1.4 -- Select TB3.5 function
    P6OUT  &= ~L_REVERSE;   // Clear P6OUT.4 -- L_REVERSE initially LOW
    P6REN  &= ~L_REVERSE;   // Clear P6REN.4 -- Disable PUPD resistor
    P6DIR  |= L_REVERSE;    // Set P6DIR.4 -- Configure P6.4 as output

    // GRN_LED Configuration: P6.6
    P6SEL0  &= ~GRN_LED;    // Clear P6SEL0.6 -- Select GPIO mode
    P6SEL1  &= ~GRN_LED;    // Clear P6SEL1.6 -- Select GPIO mode
    P6OUT   |= GRN_LED;     // Set P6OUT.6 -- GRN_LED initially HIGH
    P6REN   &= ~GRN_LED;    // Clear P6REN.6 -- Disable PUPD resistor
    P6DIR   |= GRN_LED;     // Set P6DIR.6 -- Configure P6.6 as output
}
