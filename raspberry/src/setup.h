#ifndef SETUP_H
#define SETUP_H
// Dùng ifndef để đảm bảo chỉ load file này 1 lần không lặp lại

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <cstdint>
#include <cstdlib>
using namespace std;

#define R_PIN   11
#define G_PIN   12
#define B_PIN   13

#define BUTTON_1 15
#define BUTTON_2 16
#define BUTTON_3 18

extern uint8_t Red_Color[3];
extern uint8_t Green_Color[3];
extern uint8_t Blue_Color[3];

void SetUp(void);


#endif
