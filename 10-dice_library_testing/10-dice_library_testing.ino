#include <dice.h>

Dice myDice(42,43,44,45);

void setup(){}
void loop(){
    if(digitalRead(13) == HIGH) myDice.roll();
}