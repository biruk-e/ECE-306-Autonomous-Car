//------------------------------------------------------------------------------
//  Name:           timers.h
//  Description:    This header file contains the function prototypes for configuring timer peripherals.
//  Author:         Biruk Kebede
//  Date:           Sep 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#pragma once

/**
* @brief Calls each timer initialzation function one by one.
 */
void Init_Timers();

/**
* @brief Configures and initalizes Timer B0.
 */
void Init_Timer_B0();

/**
* @brief Configures and initializes Timer B2.
 */
void Init_Timer_B2();

/**
* @brief Configures and initalizes Timer B0.
 */
void Init_Timer_B3();
