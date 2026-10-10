//------------------------------------------------------------------------------
//  Name:           globals.h
//  Description:    This header file contains all the global variable declarations in this program. They are    
//                  initialized with values in their respective .c files.
//  Author:         Biruk Kebede
//  Date:           Sep 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#pragma once

// globals for display
extern char display_line[4][11];
extern char *display[4];
extern unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned char update_display;
extern volatile unsigned long last_update_display_time;
extern volatile unsigned int update_display_count;

// globals for time
extern volatile unsigned long elapsed_ms;

// globals for switches
extern volatile unsigned char sw1_pressed;
extern volatile unsigned long sw1_pressed_time;
extern volatile unsigned long sw2_pressed_time;
extern volatile unsigned char sw2_pressed_;

// globals for wheels
extern unsigned int wheels_counter;
extern unsigned char straight_calib[2];
extern unsigned char cw_circle_calib[2];
extern unsigned char ccw_circle_calib[2];
extern unsigned char cw_turn_calib[2];
extern unsigned char ccw_turn_calib[2];
extern unsigned int movement_ticks;

// globals for shapes
extern unsigned char current_shape;
extern unsigned char shape_index;
extern unsigned char shapes[4];
extern unsigned char current_state;
extern unsigned int pause_ticks;
