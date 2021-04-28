#include <Arduino.h>
#include <lib.h>

void setup() {
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    // assumes the button connects to GND when pressed
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
    waitForButton();
    beep();
    delay(1000);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    delay(3000);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
    beep(2);
    delay(5000);
    beep(3);
    delay(2000);
    digitalWrite(YELLOW, HIGH);
}
