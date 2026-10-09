//------------------------------------------------------------------------------
//  Name:           globals.h
//  Description:    
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
extern volatile unsigned int update_display_count;

// globals for time
extern volatile unsigned long elapsed_ms;

// globals for switches
extern unsigned char sw1_pressed;
extern unsigned char sw1_not_pressed;
extern unsigned char sw1_level; // used in state machine to see the state of sw1
extern unsigned int sw1_debounce_count;
extern unsigned int sw1_release_count;

extern unsigned char sw2_pressed;
extern unsigned char sw2_not_pressed;
extern unsigned char sw2_level; // used in state machine to see the state of sw2
extern unsigned int sw2_debounce_count;
extern unsigned int sw2_release_count;

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
