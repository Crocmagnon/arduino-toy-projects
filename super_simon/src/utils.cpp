//
// Created by Gabriel Augendre on 29/04/2021.
//

#include <Arduino.h>
#include "main.h"
#include "utils.h"


void activate(byte index) {
    for (const byte led : LEDS) {
        if (led != index) {
            digitalWrite(led, LOW);
        }
    }
    digitalWrite(LEDS[index], HIGH);
    buzz(index);
}

void buzz(byte index, unsigned long duration) {
    tone(BUZZER, TONES[index], duration);
}

bool buttonIsPressed(byte index) {
    return digitalRead(BUTTONS[index]) == LOW;
}

void deactivateAll() {
    noTone(BUZZER);
    for (const byte led : LEDS) {
        digitalWrite(led, LOW);
    }
}
