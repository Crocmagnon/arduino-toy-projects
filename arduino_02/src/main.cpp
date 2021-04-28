#include <Arduino.h>
#define BUTTON 2
#define GREEN 3
#define RED1 4
#define RED2 5

void setup() {
    pinMode(BUTTON, INPUT_PULLUP);
    pinMode(GREEN, OUTPUT);
    pinMode(RED1, OUTPUT);
    pinMode(RED2, OUTPUT);
}

void loop() {
    if (digitalRead(BUTTON) == LOW) {  // button is pressed
        digitalWrite(GREEN, LOW);
        digitalWrite(RED1, HIGH);
        digitalWrite(RED2, LOW);
        delay(250);
        digitalWrite(RED1, LOW);
        digitalWrite(RED2, HIGH);
    }
    else {
        digitalWrite(GREEN, HIGH);
        digitalWrite(RED1, LOW);
        digitalWrite(RED2, LOW);
    }
}