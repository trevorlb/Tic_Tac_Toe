#ifndef __HARDWARE_H__
#include <Arduino.h>

class Hardware{
    public:
        Hardware();
        Hardware(int, int, int);
        
        bool button1Pressed();
        bool button2Pressed();
        bool button3Pressed();
        int getSlideVal();

    private:
        int BUTTON1;
        int BUTTON2;
        int BUTTON3;
        int SLIDE;
};

#endif
