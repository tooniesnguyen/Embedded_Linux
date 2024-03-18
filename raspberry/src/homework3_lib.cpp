#include "setup.h"

using namespace std;

uint8_t Color_Index = 0;
int8_t Color_Pwm = 0;

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


