#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <cstdint>
#include <cstdlib>

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

void showColor(uint8_t ds, uint8_t r, uint8_t g, uint8_t b){
    softPwmWrite(R, r * ds / 100);
    softPwmWrite(G, g * ds / 100);
    softPwmWrite(B, b * ds / 100);
    std::cout << "Giá trị: do_sang " << static_cast<int>(ds) << " R " << static_cast<int>(r) << " G " << static_cast<int>(g * ds) << " B " << static_cast<int>(b * ds) << std::endl;
}

int rand_num(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main(){
    setUp();

    int ds, r, g, b;

    while(true) {
        std::cout << "Nhap ds R G B:\n";
        std::cin >> ds >> r >> g >> b;
        showColor(ds, r, g, b);
        int value_return = rand_num(-2, 2);
        std::cout << "Gia tri random " << value_return << std::endl;  
    }

    return 0;
}

