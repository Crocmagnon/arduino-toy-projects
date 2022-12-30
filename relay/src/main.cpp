#include <Arduino.h>
#define RELAY 8

void setup() {
    pinMode(RELAY, OUTPUT);
    digitalWrite(RELAY, LOW);
}

void loop() {
    delay(5000);
    digitalWrite(RELAY, HIGH);
    delay(1000);
    digitalWrite(RELAY, LOW);
}