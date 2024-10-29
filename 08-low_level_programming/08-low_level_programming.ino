void setup(){
    // L register (42 to 49)
    DDRL =  0b00011100;
    PORTL = 0b00011100; 
    Serial.begin(9600);
}

void loop(){
    Serial.println(PINL, BIN);
    delay(2000);
}