//------------------------------------------------------------------------------
//  Name:           switches.h
//  Description:    This header file contains the function prototypes for reading switch presses.
//  Author:         Biruk Kebede
//  Date:           Oct 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#pragma once

/**
* @brief Disables switch interrupts and initializes switches before reenabling switch interrupts.
 */
void Init_Switches();

/**
* @brief Runs in main while loop to read state of switches and handle debounce.
 */
void switches_process();

/**
* @brief Called within switches_process and handles reading state of switch 1 and handling it's debouncing.
 */
void sw1_process();

/**
* @brief Called within switches_process and handles reading state of switch 2 and handling it's debouncing.
 */
void sw2_process();
