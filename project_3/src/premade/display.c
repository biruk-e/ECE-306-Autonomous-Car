#include  "inc\premade\functions.h"
#include  "msp430.h"
#include  "inc\macros.h"
#include  "inc\globals.h"

void Display_Process(void){
  if(update_display){
    update_display = 0;
    if(display_changed){
      display_changed = 0;
      Display_Update(0,0,0,0);
    }
  }
}
