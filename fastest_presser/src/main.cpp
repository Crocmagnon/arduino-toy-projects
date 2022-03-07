#include <Arduino.h>
#include <LiquidCrystal.h>
#include <main.h>

#define LCD_COLS 16
#define LCD_ROWS 2

#define PLAYER_GREEN 2
#define PLAYER_RED 3
#define TIE 1

LiquidCrystal lcd(9, 8, 4, 5, 6, 7);
int scoreGreen = 0;
int scoreRed = 0;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    pinMode(PLAYER_GREEN, INPUT_PULLUP);
    pinMode(PLAYER_RED, INPUT_PULLUP);
    randomSeed(analogRead(0));
    lcd.begin(LCD_COLS, LCD_ROWS);
}

void loop() {
    waitForReady();
    displayCountdown();
    delay(1000);
    byte randomWait = random(6, 32);
    byte cheating = 0;
    lcd.clear();
    for (byte i = 0; i < randomWait; i++) {
        if (i == LCD_COLS) {
            lcdSecondLine();
        }
        lcd.print(".");

        cheating = isCheating();
        if (cheating) {
            break;
        }
    }
    lcd.clear();
    if (cheating) {
        lcd.print("Pas de triche !");
        lcdSecondLine();
        if (cheating == PLAYER_GREEN) {
            lcd.print("Joueur vert: -1");
            scoreGreen -= 1;
        }
        else if (cheating == PLAYER_RED) {
            lcd.print("Joueur rouge: -1");
            scoreRed -= 1;
        }
        else {
            lcd.print("Joueurs : -1");
            scoreGreen -= 1;
            scoreRed -= 1;
        }
    }
    else {
        lcd.print("Maintenant !");

        const byte winner = computeWinner();
        lcd.clear();
        if (winner == PLAYER_GREEN) {
            lcd.print("Bravo joueur");
            lcdSecondLine();
            lcd.print("vert !");
            scoreGreen += 1;
        }
        else if (winner == PLAYER_RED) {
            lcd.print("Bravo joueur");
            lcd.print("rouge !");
            scoreRed += 1;
        }
        else {
            lcd.print("Egalite");
        }
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
    int playerGreen = digitalRead(PLAYER_GREEN);
    int playerRed = digitalRead(PLAYER_RED);
    while (playerGreen == HIGH && playerRed == HIGH) {
        // Wait for a button press
        playerGreen = digitalRead(PLAYER_GREEN);
        playerRed = digitalRead(PLAYER_RED);
    }
    if (playerGreen == LOW && playerRed == HIGH) {
        return PLAYER_GREEN;
    }
    if (playerGreen == HIGH && playerRed == LOW) {
        return PLAYER_RED;
    }
    else {
        return TIE;
    }
}

byte isCheating() {
    int playerGreen = digitalRead(PLAYER_GREEN);
    int playerRed = digitalRead(PLAYER_RED);
    int timer = 0;
    int maxTimer = 500;
    while (timer < maxTimer && playerGreen == HIGH && playerRed == HIGH) {
        // Wait for a button press
        playerGreen = digitalRead(PLAYER_GREEN);
        playerRed = digitalRead(PLAYER_RED);
        timer += 10;
        delay(10);
    }
    if (playerGreen == LOW && playerRed == HIGH) {
        return PLAYER_GREEN;
    }
    else if (playerGreen == HIGH && playerRed == LOW) {
        return PLAYER_RED;
    }
    else if (playerGreen == LOW && playerRed == LOW) {
        return TIE;
    }
    else {
        return 0;
    }
}

void lcdSecondLine() {
    lcd.setCursor(0, 1);
}

void printScore() {
    lcd.clear();
    lcd.print("Vert: ");
    lcd.print(scoreGreen);
    lcdSecondLine();
    lcd.print("Rouge: ");
    lcd.print(scoreRed);
    delay(2000);
}

void waitForReady() {
    lcd.clear();
    lcd.print("Vert: Commencer");
    lcdSecondLine();
    lcd.print("Rouge: Scores");

    int playerGreen = digitalRead(PLAYER_GREEN);
    int playerRed = digitalRead(PLAYER_RED);
    while (playerGreen == HIGH && playerRed == HIGH) {
        // Wait for a button press
        playerGreen = digitalRead(PLAYER_GREEN);
        playerRed = digitalRead(PLAYER_RED);
    }

    if (playerRed == LOW) {
        printScore();
        waitForReady();
    }
}
