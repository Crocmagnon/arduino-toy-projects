//
// Created by Gabriel Augendre on 29/04/2021.
//

#ifndef SUPER_SIMON_MAIN_H
#define SUPER_SIMON_MAIN_H

#define LCD_COLS 16
#define LCD_ROWS 2

#define BUZZER 11

#define BUTTON_GREEN 2
#define BUTTON_YELLOW 10
#define BUTTON_BLUE 12
#define BUTTON_RED 3

#define LED_GREEN A5
#define LED_YELLOW A4
#define LED_BLUE A3
#define LED_RED A2

#define TONE_GREEN 165
#define TONE_YELLOW 277
#define TONE_BLUE 329
#define TONE_RED 440

// Indices in the constants tables
#define GREEN 0
#define YELLOW 1
#define BLUE 2
#define RED 3

const uint8_t LEDS[] = {LED_GREEN, LED_YELLOW, LED_BLUE, LED_RED};
const uint8_t BUTTONS[] = {BUTTON_GREEN, BUTTON_YELLOW, BUTTON_BLUE, BUTTON_RED};
const uint16_t TONES[] = {TONE_GREEN, TONE_YELLOW, TONE_BLUE, TONE_RED};

#endif //SUPER_SIMON_MAIN_H
