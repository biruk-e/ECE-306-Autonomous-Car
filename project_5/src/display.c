//------------------------------------------------------------------------------
//  Name:           display.h
//  Description:    This source file contains the function implementation needed for updating the display.
//  Author:         Biruk Kebede
//  Date:           Sep 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#include  "inc\functions.h"
#include  "msp430.h"
#include  "inc\macros.h"
#include  "inc\globals.h"
#include "inc\display.h"
#include <string.h>

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
