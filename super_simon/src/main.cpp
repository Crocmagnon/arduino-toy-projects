#include <Arduino.h>
#include <LiquidCrystal.h>
#include "main.h"
#include "utils.h"


LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
byte sequence[MAX_GAME] = {};
int8_t currentPosition = -1;
bool win = true;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    lcd.begin(LCD_COLS, LCD_ROWS);
    lcd.print("Super Simon");
    randomSeed(analogRead(A0));
    pinMode(BUZZER, OUTPUT);
    configure();
    deactivateAll();
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
}

void loop() {
    if (currentPosition + 1 >= MAX_GAME) {
        endGame(lcd, win, currentPosition);
        return;
    }

    currentPosition += 1;
    byte newItem = random(0, 4);
    sequence[currentPosition] = newItem;

    playSequence(sequence, currentPosition);
    if (!userSequence(sequence, currentPosition)) {
        win = false;
        currentPosition = MAX_GAME;
    }

    delay(2000);
}
