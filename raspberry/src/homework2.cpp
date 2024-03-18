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
#define BUTTON_4 22


void SetUp(){
    wiringPiSetupPhys();
    pinMode(R_PIN, OUTPUT);
    pinMode(G_PIN, OUTPUT);
    pinMode(B_PIN, OUTPUT);

    softPwmCreate(R_PIN, 0, 100);
    softPwmCreate(G_PIN, 0, 100);
    softPwmCreate(B_PIN, 0, 100);
}

void bight_color(uint8_t brightness){
    softPwmWrite(R_PIN, brightness);
    softPwmWrite(G_PIN, brightness);
    softPwmWrite(B_PIN, brightness);
}

void brigh_lv1(void){
    bight_color(25);
}

void brigh_lv2(void){
    bight_color(50);
}

void brigh_lv3(void){
    bight_color(75);
}

void brigh_lv4(void){
    bight_color(100);
}

int main(){
    SetUp();

    wiringPiISR(BUTTON_1, INT_EDGE_RISING, &brigh_lv1);
    wiringPiISR(BUTTON_2, INT_EDGE_RISING, &brigh_lv2);
    wiringPiISR(BUTTON_3, INT_EDGE_RISING, &brigh_lv3);
    wiringPiISR(BUTTON_4, INT_EDGE_RISING, &brigh_lv4);

    while(true){

    }
    return 0;
}
