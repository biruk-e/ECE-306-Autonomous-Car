//------------------------------------------------------------------------------
//  Name:           display.h
//  Description:    This header file contains the function prototypes for updating the display.
//  Author:         Biruk Kebede
//  Date:           Oct 2026
//  IDE:            CCS
//------------------------------------------------------------------------------
#pragma once

/**
* @brief Initializes display buffer.
*/
void Init_Display(void);

/**
 * @brief Runs in while(1) loop and handles refreshing the display.
 */
void display_process(void);

/**
 * @brief Buffers 4 10-line messages to be written on display and sets display_changed flag.
 * @param line_1 A pointer to a character array storing line 1.
 * @param line_2 A pointer to a character array storing line 2.
 * @param line_3 A pointer to a character array storing line 3.
 * @param line_4 A pointer to a character array storing line_4.
 */
void display_edit_buffer(char* line_1, char* line_2, char* line_3, char* line_4);

void display_update(void);
