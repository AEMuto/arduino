
int pinArray[7] = {42,43,44,45,46,47,48};

int segments[10][7] = {
//    a, b, c, d, e, f, g
    { 1, 1, 1, 1, 1, 1, 0 }, // 0
    { 0, 1, 1, 0, 0, 0, 0 }, // 1
    { 1, 1, 0, 1, 1, 0, 1 }, // 2
    { 1, 1, 1, 1, 0, 0, 1 }, // 3
    { 0, 1, 1, 0, 0, 1, 1 }, // 4
    { 1, 0, 1, 1, 0, 1, 1 }, // 5
    { 1, 0, 1, 1, 1, 1, 1 }, // 6
    { 1, 1, 1, 0, 0, 0, 0 }, // 7
    { 1, 1, 1, 1, 1, 1, 1 }, // 8
    { 1, 1, 1, 1, 0, 1, 1 }  // 9
};

int bitSegments[10] = {
    B01111110, // 0
    B00110000, // 1
    B01101101, // 2
    B01111001, // 3
    B00110011, // 4
    B01011011, // 5
    B01011111, // 6
    B01110000, // 7
    B01111111, // 8
    B01111011  // 9
};

void setup(){
    Serial.begin(9600);
    for (int i = 0; i < 7; i++)
        pinMode(pinArray[i], OUTPUT);
}

void loop(){
    for (int i = 0; i < 10; i++) {
        // Bi-Dimensional array version
        // for (int j = 0; j < 7; j++) {
        //     digitalWrite(pinStart+j, segments[i][j] == 1 ? HIGH : LOW);
        //     Serial.print(segments[i][j]);
        // }
        // bit array version
        for (int j = 6; j >= 0; j--) {
            int value = bitRead(bitSegments[i], j);
            digitalWrite(pinArray[6-j], value == 1 ? HIGH : LOW);
            Serial.print(value);
        }
        Serial.println();
        delay(1000);
    }
}