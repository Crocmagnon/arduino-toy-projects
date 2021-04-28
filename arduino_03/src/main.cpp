#include <Arduino.h>

#define BASE_TEMP_SAMPLE_COUNT 10
#define BASE_TEMP_SAMPLE_DELAY 100
#define BIGGEST_PIN 5
#define SMALLEST_PIN 3

const byte sensorPin = PIN_A1;
float baseTemp = 0;

float getTemperature();

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.begin(9600);
    for (int pinNumber = SMALLEST_PIN; pinNumber < BIGGEST_PIN + 1; pinNumber++) {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
    float sum = 0;
    for (int i = 0; i < BASE_TEMP_SAMPLE_COUNT; i++) {
        sum += getTemperature();
        delay(BASE_TEMP_SAMPLE_DELAY);
    }
    baseTemp = sum / BASE_TEMP_SAMPLE_COUNT;
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
    float temp = getTemperature();
    byte pinLimit = SMALLEST_PIN;
    if (temp > baseTemp + 4) {
        pinLimit = SMALLEST_PIN + 3;
    } else if (temp > baseTemp + 2) {
        pinLimit = SMALLEST_PIN + 2;
    } else if (temp > baseTemp + 0.5) {
        pinLimit = SMALLEST_PIN + 1;
    }
    for (byte pin = SMALLEST_PIN; pin < pinLimit; pin++) {
        digitalWrite(pin, HIGH);
    }
    for (byte pin = pinLimit; pin < BIGGEST_PIN + 1; pin++) {
        digitalWrite(pin, LOW);
    }
    delay(100);
}

float getTemperature() {
    const int sensorVal = analogRead(sensorPin);
//    Serial.print("Valeur capteur: ");
//    Serial.print(sensorVal);
    float voltage = sensorVal / 1024.0 * 5.0;
//    Serial.print(", voltage: ");
//    Serial.print(voltage);
    float temperature = (voltage - .5) * 100;
//    Serial.print(", temperature: ");
//    Serial.println(temperature);
    return temperature;
}