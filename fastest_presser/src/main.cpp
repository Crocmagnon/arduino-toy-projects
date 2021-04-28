#include <Arduino.h>
#include <LiquidCrystal.h>
#include <main.h>

LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    randomSeed(analogRead(0));
    lcd.begin(16, 2);
}

void loop() {
    displayCountdown();
    delay(1000);
    byte randomWait = random(6, 32);
    lcd.clear();
    for (byte i = 0; i < randomWait; i++) {
        if (i == 16) {
            lcd.setCursor(0, 1);
        }
        lcd.print(".");
        delay(500);
    }
    lcd.clear();
    lcd.print("Maintenant !");
    // TODO add code to determine winner, maybe use interrupts?
    delay(2000);
    lcd.clear();
}

void displayCountdown() {
    lcd.setCursor(0, 0);
    lcd.print("Prets ?");
    lcd.setCursor(0, 1);
    displayDigit("3");
    delay(600);
    displayDigit("2");
    delay(600);
    displayDigit("1");
}

void displayDigit(const char *digit) {
    lcd.print(digit);
    for (byte i = 0; i < 3; i++) {
        delay(200);
        lcd.print(".");
    }
    lcd.print(" ");
}
