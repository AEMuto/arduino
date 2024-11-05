/***********************/
/* THE ELECTRONIC DICE */
/***********************/

#define WAIT_TIME 20 // Wait time in milliseconds

// int pips[6][7] = {
//     {0, 0, 0, 1, 0, 0, 0}, // 1
//     {1, 0, 0, 0, 0, 0, 1}, // 2
//     {1, 0, 0, 1, 0, 0, 1}, // 3
//     {1, 0, 1, 0, 1, 0, 1}, // 4
//     {1, 0, 1, 1, 1, 0, 1}, // 5
//     {1, 1, 1, 0, 1, 1, 1}  // 6
// };

// int pins[] = {42, 43, 44, 45, 46, 47, 48}; // Pins of port L
// int pinOffset = 42; // Offset of the pins
// int buttonPin = 13; // Button pin

// void displayPips(int value){
//     for(int i = 0; i < 7; i++)
//         digitalWrite(pinOffset + i, pips[value - 1][i] == 1 ? HIGH : LOW);
//     delay(WAIT_TIME);
// }

// void setup(){
//     for(int i = 0; i < 7; i++)
//         pinMode(pins[i], OUTPUT);
//     pinMode(buttonPin, INPUT);
// }

// void loop(){
//     if (digitalRead(buttonPin) == HIGH)
//         displayPips(random(1,7));
// }


/*****************************/
/* THE ELECTRONIC DICE (ALT) */
/*****************************/
int groupA = 42; // led 4
int groupB = 43; // led 1&7
int groupC = 44; // led 3&5
int groupD = 45; // led 2&6

int pinButton = 13;

void lightLed(int value){
    PORTL = 0b00000000;
    if (value %  2 != 0)
        digitalWrite(groupA, HIGH);
    if (value != 1)
        digitalWrite(groupB, HIGH);
    if (value >  3)
        digitalWrite(groupC, HIGH);
    if (value == 6)
        digitalWrite(groupD, HIGH);
    delay(WAIT_TIME);
}

void setup(){
    DDRL  = 0b11111111;
    PORTL = 0b00000000;
    pinMode(pinButton, INPUT);
}
void loop(){
    if (digitalRead(pinButton) == HIGH)
        lightLed(random(1,7));
}


/******************/
/* Go to next pin */
/******************/

// void setup(){
//     Serial.begin(9600); // Start serial communication at 9600 bps
//     DDRL =  0b11111111; // Set all pins of port L as output (42 to 49)
//     PORTL = 0b00000000; // Set all pins of port L as low
//     pinMode(13, INPUT); // Set pin 13 as input
// }

// int increment = 7;

// void loop(){
//     if(digitalRead(13) == HIGH){ // If pin 13 is high
//         (increment == 0) ? increment = 7 : increment; // If increment is 8, set it to 0, else keep it as it is
//         PORTL = 0b00000000; // Set port L as low
//         PORTL = 1 << increment; // Set the pin of port L as high
//         increment--; // Increment the increment variable
//         // PORTL = random(0, 256); // Set port L to a random number between 0 and 255
//         Serial.println(PORTL); // Print the number to the serial monitor
//         delay(1000); // Wait for 5 second
//         PORTL = 0b00000000; // Set port L as low
//     }
// }