#define DELAY0 5000
#define DELAY1 1000
#define DELAY2 2000
#define DELAY3 3000

int walk_greenPin = 45;
int walk_redPin = 46;

int car_greenPin = 47;
int car_orangePin = 48;
int car_redPin = 53;

int buttonPin = 8;
int buttonState = LOW;

// void toggle(int pin){
//     if (digitalRead(pin) == HIGH) {
//         digitalWrite(pin, LOW);
//     } else {
//         digitalWrite(pin, HIGH);
//     }
// }

// |         | Piéton |       | Auto  |        |       | Bin        | Dec |
// | ------- | ------ | ----- | ----- | ------ | ----- | ---------- | --- |
// | LED     | Verte  | Rouge | Verte | Orange | Rouge |            |     |
// | Poids   | 16     | 8     | 4     | 2      | 1     |            |     |
// | Phase 1 | 0      | 1     | 1     | 0      | 0     | 0b00001100 | 12  |
// | Phase 2 | 0      | 1     | 0     | 1      | 0     | 0b00001010 | 10  |
// | Phase 3 | 0      | 1     | 0     | 0      | 1     | 0b00001001 | 9   |
// | Phase 4 | 1      | 0     | 0     | 0      | 1     | 0b00010001 | 17  |
// | Phase 5 | 0      | 1     | 0     | 0      | 1     | 0b00001010 | 9   |
// | Phase 6 | 0      | 1     | 0     | 1      | 1     | 0b00001011 | 11  |
void putLeds(int lightValue, int pause){
    digitalWrite(car_redPin,    (lightValue&1)  == 1  ? HIGH : LOW);
    digitalWrite(car_orangePin, (lightValue&2)  == 2  ? HIGH : LOW);
    digitalWrite(car_greenPin,  (lightValue&4)  == 4  ? HIGH : LOW);
    digitalWrite(walk_redPin,   (lightValue&8)  == 8  ? HIGH : LOW);
    digitalWrite(walk_greenPin, (lightValue&16) == 16 ? HIGH : LOW);
    delay(pause);
}

void lightChange(){
    
    // Linear Method
    // digitalWrite(car_greenPin, LOW);
    // digitalWrite(car_orangePin, HIGH); delay(DELAY3);
    // digitalWrite(car_orangePin, LOW);
    // digitalWrite(car_redPin, HIGH); delay(DELAY1);
    // digitalWrite(walk_redPin, LOW);
    // digitalWrite(walk_greenPin, HIGH); delay(DELAY0);
    // digitalWrite(walk_greenPin, LOW);
    // digitalWrite(walk_redPin, HIGH); delay(DELAY1);
    // digitalWrite(car_orangePin, HIGH); delay(DELAY2);
    // digitalWrite(car_orangePin, LOW);
    // digitalWrite(car_redPin, LOW);
    // digitalWrite(car_greenPin, HIGH);

    // PORTL Method (if using an Arduino Mega and the PORTL register - 42 to 49)
    // 49	PL0	0b00000001
    // 48	PL1	0b00000010
    // 47	PL2	0b00000100
    // 46	PL3	0b00001000
    // 45	PL4	0b00010000
    // 44	PL5	0b00100000
    // 43	PL6	0b01000000
    // 42	PL7	0b10000000
    // PORTL = 10; delay(DELAY2); // 0b00001010 pin 48 and 46 (car orange and walk red)
    // PORTL = 9;  delay(DELAY1); // 0b00001001 pin 49 and 46 (car red and walk red)
    // PORTL = 17; delay(DELAY0); // 0b00010001 pin 49 and 45 (car red and walk green)
    // PORTL = 9;  delay(DELAY1); // 0b00001001 pin 49 and 46 (car red and walk red)
    // PORTL = 11; delay(DELAY2); // 0b00001011 pin 49, 48 and 46 (car red, car orange and walk red)
    // PORTL = 12;                // 0b00001100 pin 47 and 46 (car green and walk red)

    // Book Method with putLeds function,
    // Bonne méthode parce que indépendant de la configuration des pins
    // Càd que si on change les pins, on n'a pas besoin de changer la fonction
    putLeds(10, DELAY2);
    putLeds(9, DELAY1);
    putLeds(17, DELAY0);
    putLeds(9, DELAY1);
    putLeds(11, DELAY2);
    putLeds(12, 0);
}

void setup(){
    Serial.begin(9600);
    pinMode(walk_greenPin, OUTPUT);
    pinMode(walk_redPin, OUTPUT);
    pinMode(car_redPin, OUTPUT);
    pinMode(car_orangePin, OUTPUT);
    pinMode(car_greenPin, OUTPUT);
    pinMode(buttonPin, INPUT);

    // PORTL = 0b00001100; // 12
    digitalWrite(car_greenPin, HIGH);
    digitalWrite(walk_redPin, HIGH);
};

void loop(){
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        Serial.println("Button pressed");
        lightChange();
    }
};