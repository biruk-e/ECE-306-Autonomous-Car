#include  "inc\functions.h"
#include  "msp430.h"
#include  "inc\macros.h"
#include  "inc\globals.h"
#include  "inc\ports.h"

void Init_LEDs(void){
//------------------------------------------------------------------------------
// LED Configurations
//------------------------------------------------------------------------------
// Turns on both LEDs
  P1OUT &= ~RED_LED;
  P6OUT &= ~GRN_LED;
//------------------------------------------------------------------------------
}

