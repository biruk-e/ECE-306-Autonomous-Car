//------------------------------------------------------------------------------
//  Name:           ports.h
//  Description:    
//  Author:         Biruk Kebede
//  Date:           Sep 2026
//  IDE:            CCS
//------------------------------------------------------------------------------

#pragma once

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

void all_wheels_off();

void right_wheel_forward();

void right_wheel_backward();

void right_wheel_off();

void left_wheel_forward();

void left_wheel_backward();

void left_wheel_off();
