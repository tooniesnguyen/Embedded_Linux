#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <cstdint>
#include <cstdlib>
#include "utils.h"

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
unsigned int counter, counter_pre;
bool State_Success = false;

void SetUp(void){
    wiringPiSetupPhys();
    pinMode(R_PIN, OUTPUT);
    pinMode(G_PIN, OUTPUT);
    pinMode(B_PIN, OUTPUT);

    softPwmCreate(R_PIN, 0, 100);
    softPwmCreate(G_PIN, 0, 100);
    softPwmCreate(B_PIN, 0, 100);
}

void Show_Color(uint8_t brightness, uint8_t Color_Idx);
void check_bt1(void);
void check_bt2(void);
void check_bt3(void);
void check_success(void);
void check_failed(void);

int main(){
    SetUp();
    

    wiringPiISR(BUTTON_1, INT_EDGE_RISING, &check_bt1);
    wiringPiISR(BUTTON_2, INT_EDGE_RISING, &check_bt2);
    wiringPiISR(BUTTON_3, INT_EDGE_RISING, &check_bt3);

    while(true){
    
    cout << "The game start \n";
    Color_Index = rand_num(0,2);
    counter_pre = millis();
    Show_Color(100, Color_Index);

    
    delay(3000);
    if (!State_Success){
        check_failed();}

    }
    return 0;


}

void Show_Color(uint8_t brightness, uint8_t Color_Idx){
    softPwmWrite(R_PIN, Red_Color[Color_Idx]*brightness/10);
    softPwmWrite(G_PIN, Green_Color[Color_Idx]*brightness/10);
    softPwmWrite(B_PIN, Blue_Color[Color_Idx]*brightness/10);
}

void check_success(void){
    State_Success = true;
    cout << "Click Successful \n";
    Show_Color(0, 0);
    delay(500);
    Show_Color(50, 0);
    delay(300);
    Show_Color(50, 1);
    delay(300);
    Show_Color(50, 2);
    delay(400);
    Show_Color(0, 0);
}

void check_failed(void){
    cout<< "You failed \n";
    Show_Color(0, 0);
}

void check_bt1(void){
    counter = millis();
    if (counter - counter_pre <= 500 && Color_Index == 0){
        check_success();
    }
    else if (counter - counter_pre <= 500 && Color_Index != 0){
        cout << "Try againt !\n";
    }
    else{check_failed();}
}

void check_bt2(void){
    counter = millis();
    if (counter - counter_pre<= 500 && Color_Index == 1){
        check_success();
    }
    else if (counter - counter_pre <= 500 && Color_Index != 1){
        cout << "Try againt !\n";
    }
    else{check_failed();}
}

void check_bt3(void){
    counter = millis();
    if (counter - counter_pre  <= 500 && Color_Index == 2){
        check_success();
    }
    else if (counter - counter_pre <= 500 && Color_Index != 2){
        cout << "Try againt !\n";
    }
    else{check_failed();}
}