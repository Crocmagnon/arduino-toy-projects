//
// Created by Gabriel Augendre on 27/04/2021.
//

#include <lib.h>
#include <Arduino.h>

void waitForButton() {
    while (digitalRead(BUTTON) == HIGH) {}
}

void beep(int n) {
    for (int i = 0; i < n; i++) {
        tone(BUZZER, BUZZ_FREQUENCY, BUZZ_DURATION);
        delay(BUZZ_DURATION * 2);
    }
}

void beep() {
    beep(1);
}
