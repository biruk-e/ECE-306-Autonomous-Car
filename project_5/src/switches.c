#include "inc/globals.h"
#include "inc/macros.h"
#include "msp430.h"
#include "inc/ports.h"
#include "inc/switches.h"

// from globals.h
unsigned char sw1_pressed = FALSE;
unsigned char sw1_not_pressed = TRUE;
unsigned char sw1_level = GPIO_HIGH;
unsigned int sw1_debounce_count = 0;
unsigned int sw1_release_count = 0;

unsigned char sw2_pressed = FALSE;
unsigned char sw2_not_pressed = TRUE;
unsigned char sw2_level = GPIO_HIGH;
unsigned int sw2_debounce_count = 0;
unsigned int sw2_release_count = 0;

void sw1_process() {
    if (sw1_not_pressed && (sw1_level == GPIO_HIGH)) {
        if (!(P4IN & SW1)) {
            sw1_not_pressed = FALSE;
            sw1_level = GPIO_LOW;
            sw1_debounce_count = 0;
            sw1_release_count = 0;
            sw1_pressed = TRUE;
        }
        return;
    }
    if (sw1_debounce_count < SWITCH_DEBOUNCE_TIME) {
        sw1_debounce_count++;
        return;
    } else {
        if (P4IN & SW1) { // if sw1 pin is HIGH
            if (++sw1_release_count < SWITCH_DEBOUNCE_TIME) {
                return;
            } else {
                sw1_not_pressed = TRUE;
                sw1_level = GPIO_HIGH;
            }
        } else {
            sw1_release_count = 0;
        }
    }
}

void sw2_process() {
    if (sw2_not_pressed && (sw2_level == GPIO_HIGH)) {
        if (!(P2IN & SW2)) {
            sw2_not_pressed = FALSE;
            sw2_level = GPIO_LOW;
            sw2_debounce_count = 0;
            sw2_release_count = 0;
            sw2_pressed = TRUE;
        }
        return;
    }
    if (sw2_debounce_count < SWITCH_DEBOUNCE_TIME) {
        sw2_debounce_count++;
        return;
    } else {
        if (P2IN & SW2) { // if sw2 pin is HIGH
            if (++sw2_release_count < SWITCH_DEBOUNCE_TIME) {
                return;
            } else {
                sw2_not_pressed = TRUE;
                sw2_level = GPIO_HIGH;
            }
        } else {
            sw2_release_count = 0;
        }
    }
}

/*
void switches_process() {
    if (time_changed) {
        sw1_process();
        sw2_process();
    }
    
}

*/


