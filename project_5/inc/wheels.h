#pragma once

void init_wheels();

void wheels_process();

unsigned char straight(unsigned char calib[], unsigned int duration_in_ms);

unsigned char cw_circle(unsigned char calib[], unsigned int duration_in_ms);

unsigned char ccw_circle(unsigned char calib[], unsigned int duration_in_ms);

unsigned char cw_turn(unsigned char calib[], unsigned int duration_in_ms);

unsigned char ccw_turn(unsigned char calib[], unsigned int  duration_in_ms);

