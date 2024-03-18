#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <cstdint>
#include <cstdlib>

using namespace std;

#define R_Led   11
#define G_Led   12
#define B_Led   13


uint8_t Red_Color[3] = {100, 0, 0};
uint8_t Green_Color[3] = {0, 100, 0};
uint8_t Blue_Color[3] = {0, 0, 100};
uint8_t Color_Order = 0;


void setUp(){
    wiringPiSetupPhys();
    pinMode(R_Led, OUTPUT);
    pinMode(G_Led, OUTPUT);
    pinMode(B_Led, OUTPUT);

    softPwmCreate(R_Led, 0, 100);
    softPwmCreate(G_Led, 0, 100);
    softPwmCreate(B_Led, 0, 100);
}

void Show_Color(uint8_t brightness, uint8_t Color_Indx){
    softPwmWrite(R_Led, Red_Color[Color_Indx]*brightness/10);
    softPwmWrite(G_Led, Green_Color[Color_Indx]*brightness/10);
    softPwmWrite(B_Led, Blue_Color[Color_Indx]*brightness/10);
}

void Lightup(void){
    for (int i = 0; i<=10; i++){
        Show_Color(i, Color_Order);
        delay(100);
    }
}

void Faded(void){
    for (int i = 10; i>= 0; i--){
        Show_Color(i, Color_Order);
        delay(100);
    }
}


int main(){
    setUp();


    while(true){
        Lightup();
        Faded();
        Color_Order += 1;
        if (Color_Order >=3){Color_Order = 1;}
    }


    return 0;
}