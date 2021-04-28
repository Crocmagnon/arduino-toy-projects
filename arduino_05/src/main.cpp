#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 3

Servo servo;
const byte potPin = PIN_A1;

void setup() {
    servo.attach(SERVO_PIN);
}

void loop() {
    int potVal = analogRead(potPin);
    int angle = map(potVal, 0, 1023, 0, 179);
    servo.write(angle);
    delay(15);
}
