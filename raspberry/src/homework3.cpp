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

uint8_t Red_Color[3] = {100, 0, 0};
uint8_t Green_Color[3] = {0, 100, 0};
uint8_t Blue_Color[3] = {0, 0, 100};
uint8_t Color_Index = 0;
int8_t Color_Pwm = 0;

void SetUp(){
    wiringPiSetupPhys();
    pinMode(R_PIN, OUTPUT);
    pinMode(G_PIN, OUTPUT);
    pinMode(B_PIN, OUTPUT);

    softPwmCreate(R_PIN, 0, 100);
    softPwmCreate(G_PIN, 0, 100);
    softPwmCreate(B_PIN, 0, 100);
}

void Show_Color(uint8_t brightness, uint8_t Color_Idx);
void select_color(void);
void brightened(void);
void faded(void);


int main(){
    SetUp();

    wiringPiISR(BUTTON_1, INT_EDGE_RISING, &select_color);
    wiringPiISR(BUTTON_2, INT_EDGE_RISING, &brightened);
    wiringPiISR(BUTTON_3, INT_EDGE_RISING, &faded);

    while(true){

    }
    return 0;
}

void Show_Color(uint8_t brightness, uint8_t Color_Idx){
    softPwmWrite(R_PIN, Red_Color[Color_Idx]*brightness/10);
    softPwmWrite(G_PIN, Green_Color[Color_Idx]*brightness/10);
    softPwmWrite(B_PIN, Blue_Color[Color_Idx]*brightness/10);
}

void select_color(void){
    Color_Index ++;
    if(Color_Index >= 3){Color_Index = 0;}
    Show_Color(Color_Pwm, Color_Index);
}

void brightened(void){
    Color_Pwm ++;
    if(Color_Pwm > 10){Color_Pwm = 10;}
    Show_Color(Color_Pwm, Color_Index);
}

void faded(void){
    Color_Pwm --;
    if(Color_Pwm < 0){Color_Pwm = 0;}
    Show_Color(Color_Pwm, Color_Index);
}
