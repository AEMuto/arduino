#include "MyKeyPad.h"
#include <Arduino.h>
// Constructor
MyKeyPad::MyKeyPad(int rowPins[], int colPins[]) {
    for (int i = 0; i < 4; i++) {
        row[i] = rowPins[i];
        pinMode(row[i], OUTPUT);
    }
    for (int i = 0; i < 3; i++) {
        col[i] = colPins[i];
        pinMode(col[i], INPUT_PULLUP);
    }
    debounceTime = 300;
}

// Debounce method
void MyKeyPad::setDebounceTime(unsigned int time) {
    this->debounceTime = time;
}

// Read the key pressed
char MyKeyPad::readKey() {
    
    char key = KEY_NOT_PRESSED;

    for (int r = 0; r < 4; r++) {

        digitalWrite(row[r], LOW);

        for (int c = 0; c < 3; c++) {

            if((digitalRead(col[c]) == LOW) && (millis() - lastValue) >= debounceTime) {
                if((c == 2) && (r == 3)) key = KEY_1;
                if((c == 1) && (r == 3)) key = KEY_2;
                if((c == 0) && (r == 3)) key = KEY_3;
                if((c == 2) && (r == 2)) key = KEY_4;
                if((c == 1) && (r == 2)) key = KEY_5;
                if((c == 0) && (r == 2)) key = KEY_6;
                if((c == 2) && (r == 1)) key = KEY_7;
                if((c == 1) && (r == 1)) key = KEY_8;
                if((c == 0) && (r == 1)) key = KEY_9;
                if((c == 2) && (r == 0)) key = KEY_STAR;
                if((c == 1) && (r == 0)) key = KEY_0;
                if((c == 0) && (r == 0)) key = KEY_HASH;
                lastValue = millis();
            }
        }

        digitalWrite(row[r], HIGH);
    }

    return key;
}