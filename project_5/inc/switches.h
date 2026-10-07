#pragma once

/**
@brief Initializes switch 1 related global variables to appropriate starting values
 */
void init_sw1();

/**
@brief Initializes switch 2 related global variables to appropriate starting values
 */
void init_sw2();

/**
@brief Initializes all switch related global variables to appropriate starting values
 */
 void init_switches();

/**
@brief Handles reading switch 1 presses with debouncing
 */
void sw1_process();

/**
@brief Handles reading switch 2 presses with debouncing
 */
 void sw2_process();

/**
@brief Handles reading all switch presses with debouncing
 */
 void switches_process();
