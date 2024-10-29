void setup(){
    Serial.begin(9600); // Start serial communication at 9600 bps
    DDRL =  0b11111111; // Set all pins of port L as output
    PORTL = 0b00000000; // Set all pins of port L as low
    pinMode(13, INPUT); // Set pin 13 as input
}

int increment = 7;

void loop(){
    if(digitalRead(13) == HIGH){ // If pin 13 is high
        (increment == 0) ? increment = 7 : increment; // If increment is 8, set it to 0, else keep it as it is
        PORTL = 0b00000000; // Set port L as low
        PORTL = 1 << increment; // Set the pin of port L as high
        increment--; // Increment the increment variable
        // PORTL = random(0, 256); // Set port L to a random number between 0 and 255
        Serial.println(PORTL); // Print the number to the serial monitor
        delay(1000); // Wait for 5 second
        PORTL = 0b00000000; // Set port L as low
    }
}