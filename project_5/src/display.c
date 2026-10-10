//------------------------------------------------------------------------------
//  Name:           display.h
//  Description:    This source file contains the function implementations for updating the display.
//  Author:         Biruk Kebede
//  Date:           Oct 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#include  "inc\functions.h"
#include  "msp430.h"
#include  "inc\macros.h"
#include  "inc\globals.h"
#include "inc\display.h"
#include <string.h>
#include "inc/ports.h"

void Init_Display() {
  display_edit_buffer("  BLINK!  ", "          ", "          ", "          ");
}

void display_process(void){
  if(update_display){
    update_display = 0;
    if(display_changed){
      display_changed = TRUE;
      Display_Update(0,0,0,0);
    }
  }
}

void display_edit_buffer(char* line_1, char* line_2, char* line_3, char* line_4) {
  strcpy(display_line[0], line_1);
  strcpy(display_line[1], line_2);
  strcpy(display_line[2], line_3);
  strcpy(display_line[3], line_4);
  display_changed = TRUE;
}

volatile unsigned long last_update_display_time = 0;
void display_update() {
  if (elapsed_ms - last_update_display_time >= 200) {
    update_display = 1;
    last_update_display_time = elapsed_ms;
  }
}
