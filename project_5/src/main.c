#include  "msp430.h"
#include  <string.h>
#include  "inc\functions.h"
#include  "inc\ports.h"
#include  "inc\macros.h"
#include  "inc\init.h"
#include  "inc\globals.h"
#include  "inc\motors.h"
#include  "inc\switches.h"
#include  "inc\wheels.h"
#include  "inc\timers.h"
#include  "inc\display.h"

void main(void){

  WDTCTL = WDTPW | WDTHOLD;            // stop watchdog timer

  Init_Ports();
  Init_Clocks();
  Init_Conditions();
  Init_Timers();
  Init_LCD();
  Init_Switches();
  Init_Display();

  while(ALWAYS) {
    display_process();
    switches_process();
    display_update();
  }
}

