#ifndef MYKEYPAD_H
#define MYKEYPAD_H
#include <Arduino.h>
#define KEY_NOT_PRESSED '-'
#define KEY_1 '1'
#define KEY_2 '2'
#define KEY_3 '3'
#define KEY_4 '4'
#define KEY_5 '5'
#define KEY_6 '6'
#define KEY_7 '7'
#define KEY_8 '8'
#define KEY_9 '9'
#define KEY_0 '0'
#define KEY_STAR '*'
#define KEY_HASH '#'

class MyKeyPad {
    public:
        MyKeyPad(int rowPins[], int colPins[]); // constructor
        void setDebounceTime(unsigned int debounceTime); // set the debounce time
        char readKey(); // return the key pressed
    private:
        unsigned int debounceTime;
        long lastValue; // last value from the millis() function
        int row[4];
        int col[3];
};
#endif