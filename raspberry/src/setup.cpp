#include "setup.h"

uint8_t Red_Color[3] = {100, 0, 0};
uint8_t Green_Color[3] = {0, 100, 0};
uint8_t Blue_Color[3] = {0, 0, 100};

void SetUp(void){
    wiringPiSetupPhys();
    pinMode(R_PIN, OUTPUT);
    pinMode(G_PIN, OUTPUT);
    pinMode(B_PIN, OUTPUT);

    softPwmCreate(R_PIN, 0, 100);
    softPwmCreate(G_PIN, 0, 100);
    softPwmCreate(B_PIN, 0, 100);
}
