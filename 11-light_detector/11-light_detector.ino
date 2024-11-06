
int pins[] = {38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
int analogPin = A0;

void controlLEDs(int value){
    int bargraphValue = map(value, 0, 1023, 0, 9);
    for (int i = 0; i < 10; i++)
        digitalWrite(pins[i], i <= bargraphValue ? HIGH : LOW);
}

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 10; i++) pinMode(pins[i], OUTPUT);
    pinMode(analogPin, INPUT);
}

void loop()
{
    int valueLDR = analogRead(analogPin);
    Serial.println(valueLDR);
    controlLEDs(valueLDR);
    delay(10);
}