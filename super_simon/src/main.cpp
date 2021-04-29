#include <Arduino.h>
#include <LiquidCrystal.h>

#define LCD_COLS 16
#define LCD_ROWS 2

#define BUTTON_GREEN 2
#define BUTTON_YELLOW 10
#define BUTTON_BLUE 12
#define BUTTON_RED 3

#define LED_GREEN A5
#define LED_YELLOW A4
#define LED_BLUE A3
#define LED_RED A2

#define TONE_BLUE 329
#define TONE_RED 440
#define TONE_GREEN 165
#define TONE_YELLOW 277

#define BUZZER 11

const uint8_t LEDS[] = {LED_GREEN, LED_YELLOW, LED_BLUE, LED_RED};
const uint8_t BUTTONS[] = {BUTTON_GREEN, BUTTON_YELLOW, BUTTON_BLUE, BUTTON_RED};
const uint16_t TONES[] = {TONE_GREEN, TONE_YELLOW, TONE_BLUE, TONE_RED};

LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    lcd.begin(LCD_COLS, LCD_ROWS);
    pinMode(BUZZER, OUTPUT);
    for (int i = 0; i < 4; i++) {
        const uint8_t led = LEDS[i];
        pinMode(led, OUTPUT);
        pinMode(BUTTONS[i], INPUT_PULLUP);
        digitalWrite(led, HIGH);
        tone(BUZZER, TONES[i]);
        delay(300);
    }
    noTone(BUZZER);
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
}