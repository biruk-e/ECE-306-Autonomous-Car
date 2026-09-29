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
#include  "inc\premade\functions.h"
#include  "inc\premade\LCD.h"
#include  "inc\ports.h"
#include  "inc\macros.h"
#include  "inc\init.h"
#include  "inc\globals.h"
#include  "inc\motors.h"
#include  "inc\switches.h"
#include  "inc\wheels.h"
#include  "inc\time.h"
#include  "inc\shapes.h"

void main(void){

  WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

  Init_Ports();                        // Initialize Ports
  Init_Clocks();                       // Initialize Clock System
  Init_Conditions();                   // Initialize Variables and Initial Conditions
  Init_Timers();                       // Initialize Timers
  Init_LCD();                          // Initialize LCD

  // Place the contents of what you want on the display, in between the quotes
  // Limited to 10 characters per line
  strcpy(display_line[0], "   NCSU   ");
  strcpy(display_line[1], " WOLFPACK ");
  strcpy(display_line[2], "  ECE306  ");
  strcpy(display_line[3], " EMBEDDED ");
  display_changed = TRUE;
//  Display_Update(0,0,0,0);

//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
  while(ALWAYS) {                      // Can the Operating system run
    Display_Process();                 // Update Display
    time_process();
    wheels_process();
    switches_process();
    shapes_state_machine();

    /*
    if (sw1_pressed) {
       if (!straight_running) {
        straight_running = TRUE;
        wheels_counter = 0;
        movement_ticks = 0;
      } else {
        sw1_pressed = FALSE;
      }
    }
    if (straight_running) {
      unsigned char status;
      status = straight(straight_calib, 5000);
      if (status == DONE) {
        straight_running = FALSE;
      }
    }
    */
    
    P3OUT ^= TEST_PROBE;               // Change State of TEST_PROBE OFF

  }
}
