#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdint.h>
#include <stdlib.h>

#define R   11
#define G   12
#define B   13
#define bt1 15
#define bt2 16
#define bt3 18
#define bt4 22




void setUp(){
    wiringPiSetupPhys();
    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(bt1, INPUT);
    pinMode(bt2, INPUT);
    pinMode(bt3, INPUT);
    pinMode(bt4, INPUT);

    softPwmCreate(R, 0, 100);
    softPwmCreate(G, 0, 100);
    softPwmCreate(B, 0, 100);
}

void showColor(uint8_t ds,uint8_t r,uint8_t g,uint8_t b){
    softPwmWrite(R, r*ds/100);
    softPwmWrite(G, g*ds/100);
    softPwmWrite(B, b*ds/100);
    printf("Giá trị: do_sang %d R %d G %d B %d\n", ds, r, g*ds, b*ds);

}

int rand_num(int min, int max) {
    return min + rand() % (max - min + 1);
}


int main(){
    setUp();

    int ds, r, g, b;


    while(1)
    {
    printf("Nhap ds R G B:\n");
    scanf("%d%d%d%d", &ds, &r, &g, &b);
    showColor(ds, r, g, b);
    int value_return = rand_num(-2,2);
    printf("Gia tri random %d\n", value_return);  
    }
    return 0;
}

