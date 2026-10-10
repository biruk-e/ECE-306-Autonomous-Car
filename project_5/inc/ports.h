//------------------------------------------------------------------------------
//  Name:           ports.h
//  Description:    This header file contains the macrosa and function prototypes for configuring the ports 
//                  on the MSP430 as well as the function declarations for initalizing ports upon startup.                    
//  Author:         Biruk Kebede
//  Date:           Sep 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#pragma once

#include  "msp430.h"

// True/false macros
#define FALSE                  (0x00)
#define TRUE                   (0x01)

// Motor control macros
#define MOTOR                  (0x00)
#define SMCLK_OFF              (0x00)
#define SMCLK_ON               (0x01)
#define PORTS                  (0x00)
#define PWM_MODE               (0x01)
#define WHEEL_OFF              (0x00)
#define WHEEL_PERIOD          (10000)
#define RIGHT_FORWARD_SPEED (TB3CCR2)
#define RIGHT_REVERSE_SPEED (TB3CCR3)
#define LEFT_FORWARD_SPEED  (TB3CCR4)
#define LEFT_REVERSE_SPEED  (TB3CCR5)
#define STEP                   (2000)
#define FORWARD                (0x00)
#define REVERSE                (0x01)


// Port 1 Pins
#define RED_LED                BIT0 // 1.0 RED LED 0
#define V_A1_SEEED             BIT1 // 1.1 A1_SEEED
#define V_DETECT_L             BIT2 // 1.2 V_DETECT_L
#define V_DETECT_R             BIT3 // 1.3 V_DETECT_R
#define V_A4_SEEED             BIT4 // 1.4 A4_SEEED
#define V_THUMB                BIT5 // 1.5 V_THUMB
#define UCA0RXD                BIT6 // 1.6 Back Channel UCA0RXD
#define UCA0TXD                BIT7 // 1.7 Back Channel UCA0TXD

// Port 2 Pins
#define RESET_LCD              BIT0 // 2.0 LCD Reset
#define CHECK_BAT              BIT1 // 2.1 CHECK_BAT
#define IR_LED                 BIT2 // 2.2 IR LED
#define SW2                    BIT3 // 2.3 SW2
#define IOT_RUN_RED            BIT4 // 2.4 IOT_RUN_RED
#define DAC_ENB                BIT5 // 2.5 DAC_ENB
#define LFXOUT                 BIT6 // 2.6 XOUTR
#define LFXIN                  BIT7 // 2.7 XINR

// Port 3 Pins
#define TEST_PROBE             BIT0 // 3.0 TEST PROBE
#define OA2O                   BIT1 // 3.1 OA2O
#define OA2N                   BIT2 // 3.2 Photodiode Circuit
#define OA2P                   BIT3 // 3.3 Photodiode Circuit
#define SMCLK_OUT              BIT4 // 3.4 SMCLK
#define DAC_CNTL               BIT5 // 3.5 DAC_CNTL
#define IOT_LINK_GRN           BIT6 // 3.6 IOT_LINK_GRN
#define IOT_EN                 BIT7 // 3.7 IOT_EN              1

// Port 4 Pins
#define DAC_CNTL1              BIT0 // 4.0 DAC_CNTL1
#define SW1                    BIT1 // 4.1 SW1
#define UCA1RXD                BIT2 // 4.2 Back Channel UCA1RXD
#define UCA1TXD                BIT3 // 4.3 Back Channel UCA1TXD
#define UCB1_CS_LCD            BIT4 // 4.4 Chip Select
#define UCB1CLK                BIT5 // 4.5 SPI mode - clock output�UCB1CLK
#define UCB1SIMO               BIT6 // 4.6 UCB1SIMO
#define UCB1SOMI               BIT7 // 4.7 UCB1SOMI

// Port 5 Pins
#define V_BAT                  BIT0 // 5.0 V_BAT
#define V_5_0                  BIT1 // 5.1 V_5_0
#define V_DAC                  BIT2 // 5.2 V_DAC
#define V_3_3                  BIT3 // 5.3 V_3_3
#define IOT_BOOT               BIT4 // 5.4 IOT_BOOT           1

// Port 6 Pins
#define LCD_BACKLITE           BIT0 // 6.0 LCD_BACKLITE
#define R_FORWARD              BIT1 // 6.1 R_FORWARD
#define R_REVERSE              BIT2 // 6.2 R_REVERSE
#define L_FORWARD              BIT3 // 6.3 L_FORWARD
#define L_REVERSE              BIT4 // 6.4 L_REVERSE
#define P6_5                   BIT5 // 6.5
#define GRN_LED                BIT6 // 6.6 GREEN LED

/**
@brief Calls all of the initialization functions for ports 1 - 6 one by one.
 */
void Init_Ports(void);

/**
@brief Initializes the pins in port 1.
 */
void Init_Port1(void);

/**
@brief Initializes the pins in port 2.
 */
void Init_Port2(void);

/**
@brief Initializes the pins in port 3.
 */
void Init_Port3(void);

/**
@brief Initializes the pins in port 4.
 */
void Init_Port4(void);

/**
@brief Initializes the pins in port 5.
 */
void Init_Port5(void);

/**
@brief Initializes the pins in port 6.
 */
void Init_Port6(void);
