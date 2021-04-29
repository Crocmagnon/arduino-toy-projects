#include <Arduino.h>
#include <LiquidCrystal.h>
#include <main.h>

#define LCD_COLS 16
#define LCD_ROWS 2

#define PLAYER_A 2
#define PLAYER_B 3
#define TIE 0

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
unsigned int scoreA = 0;
unsigned int scoreB = 0;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    pinMode(PLAYER_A, INPUT_PULLUP);
    pinMode(PLAYER_B, INPUT_PULLUP);
    randomSeed(analogRead(0));
    lcd.begin(LCD_COLS, LCD_ROWS);
}

void loop() {
    waitForReady();
    displayCountdown();
    delay(1000);
    byte randomWait = random(6, 32);
    lcd.clear();
    for (byte i = 0; i < randomWait; i++) {
        if (i == LCD_COLS) {
            lcdSecondLine();
        }
        lcd.print(".");
        delay(500);
    }
    lcd.clear();
    lcd.print("Maintenant !");

    const byte winner = computeWinner();
    lcd.clear();
    if (winner == PLAYER_A) {
        lcd.print("Bravo joueur A !");
        scoreA += 1;
    }
    else if (winner == PLAYER_B) {
        lcd.print("Bravo joueur B !");
        scoreB += 1;
    }
    else {
        lcd.print("Egalite");
    }
    delay(4000);
    printScore();
}

void displayCountdown() {
    lcd.clear();
    lcd.print("Prets ?");
    lcdSecondLine();
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

byte computeWinner() {
    int playerA = digitalRead(PLAYER_A);
    int playerB = digitalRead(PLAYER_B);
    while (playerA == HIGH && playerB == HIGH) {
        // Wait for a button press
        playerA = digitalRead(PLAYER_A);
        playerB = digitalRead(PLAYER_B);
        delay(1);
    }
    if (playerA == LOW && playerB == HIGH) {
        return PLAYER_A;
    }
    if (playerA == HIGH && playerB == LOW) {
        return PLAYER_B;
    }
    else {
        return TIE;
    }
}

void lcdSecondLine() {
    lcd.setCursor(0, 1);
}

void printScore() {
    lcd.clear();
    lcd.print("A: ");
    lcd.print(scoreA);
    lcdSecondLine();
    lcd.print("B: ");
    lcd.print(scoreB);
    delay(2000);
}

void waitForReady() {
    lcd.clear();
    lcd.print("A: Commencer");
    lcdSecondLine();
    lcd.print("B: Scores");

    int playerA = digitalRead(PLAYER_A);
    int playerB = digitalRead(PLAYER_B);
    while (playerA == HIGH && playerB == HIGH) {
        // Wait for a button press
        playerA = digitalRead(PLAYER_A);
        playerB = digitalRead(PLAYER_B);
        delay(1);
    }

    if (playerB == LOW) {
        printScore();
        waitForReady();
    }
}
