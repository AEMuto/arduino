// light_sequencer.ino

int ledPin[] = {7, 8, 9, 10, 11, 12, 13};
int waitTime = 500;

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 0; i++)
    {
        pinMode(ledPin[i], OUTPUT);
    }
}

void loop()
{
    for (int i = 0; i < 7; i++)
    {
        Serial.println(i);
        digitalWrite(ledPin[i], HIGH);
        delay(waitTime);
        digitalWrite(ledPin[i], LOW);
    }
}