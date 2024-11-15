#define pinsTotal 12

int pinStart = 22;
int pinsDigits[4] = {22,23,24,25};
int pinsSegments[8] = {26,27,28,29,30,31,32,33};

int segments[11][8] = {
//    a, b, c, d, e, f, g, dp
    { 1, 1, 1, 1, 1, 1, 0, 0 }, // 0 
    { 0, 1, 1, 0, 0, 0, 0, 0 }, // 1
    { 1, 1, 0, 1, 1, 0, 1, 0 }, // 2
    { 1, 1, 1, 1, 0, 0, 1, 0 }, // 3
    { 0, 1, 1, 0, 0, 1, 1, 0 }, // 4
    { 1, 0, 1, 1, 0, 1, 1, 0 }, // 5
    { 1, 0, 1, 1, 1, 1, 1, 0 }, // 6
    { 1, 1, 1, 0, 0, 0, 0, 0 }, // 7
    { 1, 1, 1, 1, 1, 1, 1, 0 }, // 8
    { 1, 1, 1, 1, 0, 1, 1, 0 }, // 9
    { 0, 0, 0, 0, 0, 0, 0, 1 }  // dp
};

void writeNum(int digit, int value, bool dp = false) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(pinsDigits[i], i == digit ? LOW : HIGH);
    }
    for (int j = 0; j < 7; j++) {
        digitalWrite(pinsSegments[j], segments[value][j] == 1 ? HIGH : LOW);
    }
    digitalWrite(pinsSegments[7], dp ? HIGH : LOW);
}

void setup(){
    Serial.begin(9600);
    for (int i = pinStart; i < pinStart + pinsTotal; i++)
        pinMode(i, OUTPUT);
    
}

void loop(){
    writeNum(0, 3, true);
    delay(5);
    writeNum(1, 1);
    delay(5);
    writeNum(2, 4);
    delay(5);
    writeNum(3, 2);
    delay(5);
}