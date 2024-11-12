#include <MyKeyPad.h>
#include <LiquidCrystal.h>
#define RS 36 // Register select pin
#define EN 38 // Enable pin
#define D4 40 // Data pin 4
#define D5 42 // Data pin 5
#define D6 44 // Data pin 6
#define D7 46 // Data pin 7
#define COLS 16 // Number of columns
#define ROWS 2 // Number of rows

int rowArray[] = { 22, 24, 26, 28 };
int colArray[] = { 30, 32, 34 };

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
MyKeyPad myOwnKeyPad(rowArray, colArray);

char characters[ROWS][COLS] = {{},{}}; // 2D array to store characters

int index = 0;

void setup(){
    lcd.begin(COLS, ROWS);
    lcd.print("Hello friend");
    lcd.setCursor(0, 1);
    lcd.print("I am MR. ROBOT"); // 17 is max characters
    Serial.begin(9600);
    myOwnKeyPad.setDebounceTime(500);
    index = 0;
}

void loop(){
    char key = myOwnKeyPad.readKey();
    if (key != KEY_NOT_PRESSED) {
        lcd.clear();
        if (index >= COLS*ROWS) {
            index = 0; 
            lcd.clear(); 
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    characters[i][j] = ' ';
                }
            }
        }
        if (index < COLS) {
            Serial.println("First row");
            Serial.println("Index: " + String(index));
            characters[0][index] = key;
            lcd.setCursor(0, 0);
            lcd.print(characters[0]);
            Serial.println(characters[0]);
        } else {
            Serial.println("Second row");
            Serial.println("Index: " + String(index));
            characters[1][index-COLS] = key;
            lcd.setCursor(0, 0);
            lcd.print(characters[0]);
            lcd.setCursor(0, 1);
            lcd.print(characters[1]);
        }
        index++;
    }
}