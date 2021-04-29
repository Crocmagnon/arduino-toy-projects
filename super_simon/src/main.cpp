#include <Arduino.h>
#include <LiquidCrystal.h>
#include "main.h"
#include "utils.h"


LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    lcd.begin(LCD_COLS, LCD_ROWS);
    pinMode(BUZZER, OUTPUT);
    for (byte i = 0; i < 4; i++) {
        const byte led = LEDS[i];
        pinMode(led, OUTPUT);
        pinMode(BUTTONS[i], INPUT_PULLUP);
        activate(i);
        delay(300);
    }
    digitalWrite(LED_BUILTIN, LOW);
    deactivateAll();
}

void loop() {
    if (buttonIsPressed(GREEN)) {
        activate(GREEN);
    }
    else if (buttonIsPressed(YELLOW)) {
        activate(YELLOW);
    }
    else if (buttonIsPressed(BLUE)) {
        activate(BLUE);
    }
    else if (buttonIsPressed(RED)) {
        activate(RED);
    }
    else {
        deactivateAll();
    }
}
