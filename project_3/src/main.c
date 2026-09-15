//------------------------------------------------------------------------------
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//  Jim Carlson
//  Jan 2023
//  Built with Code Composer Version: CCS12.4.0.00007_win64
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "msp430.h"
#include  <string.h>
#include  "inc\functions.h"
#include  "inc\LCD.h"
#include  "inc\ports.h"
#include  "inc\macros.h"
#include  "inc\init.h"
#include  "inc\globals.h"
#include  "inc\carlson.h"

void main(void){

  WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

  Init_Ports();                        // Initialize Ports
  Init_Clocks();                       // Initialize Clock System
  Init_Conditions();                   // Initialize Variables and Initial Conditions
  Init_Timers();                       // Initialize Timers

  __delay_cycles(80000); // Leave LCD in RESET for 10 ms (@8MHz)

  //P2OUT |= RESET_LCD;      // Reset net as labeled in ports.h/schematic
  P4OUT |= DAC_CNTL1;      // Reset net actually used by LCD.obj

  __delay_cycles(80000); // 

  Init_LCD();                          // Initialize LCD

  //P2OUT &= ~RESET_LCD;

  // Place the contents of what you want on the display, in between the quotes
  // Limited to 10 characters per line
  strcpy(display_line[0], "   NCSU   ");
  strcpy(display_line[1], " WOLFPACK ");
  strcpy(display_line[2], "  ECE306  ");
  strcpy(display_line[3], "  GP I/O  ");
  display_changed = TRUE;
//  Display_Update(0,0,0,0);

  wheel_move = 0;
  forward = TRUE;

//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
  while(ALWAYS) {                      // Can the Operating system run
    Carlson_StateMachine();            // Run a Time Based State Machine
    Switches_Process();                // Check for switch state change
    Display_Process();                 // Update Display
    P3OUT ^= TEST_PROBE;               // Change State of TEST_PROBE OFF
  }
//------------------------------------------------------------------------------

}
