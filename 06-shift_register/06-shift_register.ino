int shiftPin = 8;   // SH_CP
int storagePin = 9; // ST_CP
int dataPin = 10;   // DS
// int dataArr[] = {0, 0, 1, 0, 1, 1, 0, 0};
byte value = 0;

// Réinitialisation de toutes les broches -> niveau LOW
void resetPins()
{
  digitalWrite(shiftPin, LOW);
  digitalWrite(storagePin, LOW);
  digitalWrite(dataPin, LOW);
}

// void putPins(int data[])
// {
//   for(int i = 0; i < 8; i++) {
//     resetPins();
//     digitalWrite(dataPin, data[i]); delay(20);
//     digitalWrite(shiftPin, HIGH); delay(20);
//   }
// }

void setup()
{
  pinMode(shiftPin, OUTPUT);
  pinMode(storagePin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  // resetPins();
  // putPins(dataArr);
  // digitalWrite(storagePin, HIGH); // ST_CP
}

void loop()
{
  digitalWrite(storagePin, LOW); // ST_CP
  shiftOut(dataPin, shiftPin, MSBFIRST, value++);
  digitalWrite(storagePin, HIGH); // ST_CP
  delay(250);
}