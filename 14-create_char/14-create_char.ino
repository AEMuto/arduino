#include <LiquidCrystal.h>;
#define RS 36 // Register select pin
#define EN 38 // Enable pin
#define D4 40 // Data pin 4
#define D5 42 // Data pin 5
#define D6 44 // Data pin 6
#define D7 46 // Data pin 7
#define COLS 16 // Number of columns
#define ROWS 2 // Number of rows

// initialize the library
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

byte customChar[8] = {
	0b00000,
	0b11011,
	0b11011,
	0b00000,
	0b00100,
	0b10001,
	0b01110,
	0b00000
};

void setup() 
{
	// create a new custom character
	lcd.createChar(0, customChar);

	// set up number of columns and rows
	lcd.begin(16, 2);

	// print the custom char to the lcd
	// why typecast? see: http://arduino.cc/forum/index.php?topic=74666.0
	lcd.write((uint8_t)0);
}

void loop()
{

}