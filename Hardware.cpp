#include "Hardware.h"

Hardware::Hardware(){
    BUTTON1 = 4;
    BUTTON2 = 2;
    BUTTON3 = 3;
    SLIDE = A0;
}

Hardware::Hardware(int b1, int b2, int b3){
    BUTTON1 = b1;
    BUTTON2 = b2;
BUTTON3 = b3;
    SLIDE = A0;
}

bool Hardware::button1Pressed(){
     return digitalRead(BUTTON1);
}

bool Hardware::button2Pressed(){
     return digitalRead(BUTTON2);
}

bool Hardware::button3Pressed(){
     return digitalRead(BUTTON3);
}

int Hardware::getSlideVal(){
    return map(analogRead(SLIDE), 0, 1023, 3, 0);
}

