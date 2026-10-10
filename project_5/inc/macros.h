//------------------------------------------------------------------------------
//  Name:           macros.h
//  Description:    
//  Author:         Biruk Kebede
//  Date:           Sep 2026
//  IDE:            CCS
//------------------------------------------------------------------------------
#pragma once

#define ALWAYS                  (1)
#define RESET_STATE             (0)
#define TRUE                    (0x01)
#define FALSE                   (0x00)

// GPIO related macros
#define GPIO_HIGH               (0x01)
#define GPIO_LOW                (0x00)

// Switches related macros
#define SWITCH_DEBOUNCE_TIME    (2000)

// Wheels related macros
#define DONE                    (0x01)
#define NOT_DONE                (0x00)

// Shape related macros
#define WAIT                    (0x00)
#define START                   (0x01)
#define RUNNING                 (0x02)
#define SHAPE_DONE              (0x03)
#define PAUSE_TIME              (((3000UL * 10UL) + 63UL) / 64UL)
#define TRIANGLE_LEG_TIME       (1000)
#define TRIANGLE_CW_TURN_TIME   (610)
#define TRIANGLE_CCW_TURN_TIME  (600)
#define ONE_CW_CIRCLE_TIME      (3300)
#define ONE_CCW_CIRCLE_TIME     (3400)

// Timer related macros
#define TB0CCR0_PERIOD          (125 - 1) // Achieves a 1 ms tick time from SMCLK together with ID__8 and TBIDEX__8    
#define TB3CCR0_PERIOD          (100)
#define TB2CCR0_PERIOD          (50000)   // Achieves a 200 ms tick time from SMCLK together with ID__8 and TBIDEX__8
