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

void main(void){

  WDTCTL = WDTPW | WDTHOLD;            // stop watchdog timer

  Init_Ports();
  Init_Clocks();
  Init_Conditions();
  Init_Timers();
  Init_LCD();

  while(ALWAYS) {
    display_process();
    //time_process();
    //wheels_process();
    //switches_process();
  }
}

