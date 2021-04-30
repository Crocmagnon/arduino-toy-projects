//
// Created by Gabriel Augendre on 29/04/2021.
//

#include <LiquidCrystal.h>
#include <Arduino.h>
#include "main.h"
#include "utils.h"


const uint8_t LEDS[] = {LED_GREEN, LED_YELLOW, LED_BLUE, LED_RED};
const uint8_t BUTTONS[] = {BUTTON_GREEN, BUTTON_YELLOW, BUTTON_BLUE, BUTTON_RED};
const uint16_t TONES[] = {TONE_GREEN, TONE_YELLOW, TONE_BLUE, TONE_RED};

void configure() {
    for (byte i = 0; i < 4; i++) {
        const byte led = LEDS[i];
        pinMode(led, OUTPUT);
        pinMode(BUTTONS[i], INPUT_PULLUP);
        activate(i);
        delay(300);
    }
}

void activate(byte index) {
    for (const byte led : LEDS) {
        digitalWrite(led, LOW);
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

void playSequence(const byte sequence[], byte upTo) {
    for (byte i = 0; i <= upTo; i++) {
        activate(sequence[i]);
        delay(300);
        deactivateAll();
        delay(15);
    }
}

bool userSequence(const byte sequence[], byte upTo) {
    for (byte i = 0; i <= upTo; i++) {
        byte userButton = waitForButton();
        byte expectedButton = sequence[i];
        if (userButton == expectedButton) {
            activate(userButton);
            delay(300);
            deactivateAll();
        }
        else {
            error();
            blink(expectedButton);
            return false;
        }
    }
    return true;
}

void error() {
    tone(BUZZER, TONE_ERROR, 500);
    delay(500);
}

byte waitForButton() {
    while (true) {
        for (byte i = 0; i < 4; i++) {
            if (buttonIsPressed(i)) {
                return i;
            }
        }
    }
}

void endGame(LiquidCrystal lcd, bool win, byte score) {
    lcd.clear();
    if (win) {
        score++;  // Compensate for missing "+1" in the main loop.
        lcd.print("Bravo!");
    }
    else {
        lcd.print("Perdu :/");
    }
    lcd.setCursor(0, 1);
    lcd.print(score);
    delay(10000);
}

void blink(byte index) {
    for (byte i = 0; i < 3; i++) {
        digitalWrite(LEDS[index], HIGH);
        delay(100);
        digitalWrite(LEDS[index], LOW);
        delay(100);
    }
}
