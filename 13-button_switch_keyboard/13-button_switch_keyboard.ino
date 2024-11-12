#include <MyKeyPad.h>

int rowArray[] = { 22, 24, 26, 28 };
int colArray[] = { 30, 32, 34 };

MyKeyPad myOwnKeyPad(rowArray, colArray);

void setup() {
    Serial.begin(9600);
    myOwnKeyPad.setDebounceTime(500);
}

void loop() {
    char key = myOwnKeyPad.readKey();
    if (key != KEY_NOT_PRESSED) {
        Serial.println(key);
    }
}