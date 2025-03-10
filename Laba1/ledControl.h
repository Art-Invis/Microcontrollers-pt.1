#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <Arduino.h>

#define BUTTON_PIN 13
#define LED_PIN_1 2
#define LED_PIN_2 14
#define LED_PIN_3 12

#define LED_COUNT 3  

const int ledPins[LED_COUNT] = {LED_PIN_1, LED_PIN_2, LED_PIN_3};

#define MIN_BLINK_DELAY 50
#define MAX_BLINK_DELAY 1000
#define BLINK_STEP 200  

volatile int blinkDelay = MAX_BLINK_DELAY;
unsigned long previousMillis = 0;
int ledIndex = 0;  

bool lastButtonState = HIGH;
bool currentButtonState;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void initPins() {
    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void blinkLeds() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= blinkDelay) {
        previousMillis = currentMillis;

        digitalWrite(ledPins[ledIndex], LOW);
        ledIndex = (ledIndex + 1) % LED_COUNT;
        digitalWrite(ledPins[ledIndex], HIGH);
    }
}

void checkButton() {
    currentButtonState = digitalRead(BUTTON_PIN);

    if (currentButtonState != lastButtonState) {
        if ((millis() - lastDebounceTime) > debounceDelay) {  
            lastDebounceTime = millis();  

            if (currentButtonState == LOW) {  
                if (blinkDelay > MIN_BLINK_DELAY) {
                    blinkDelay -= BLINK_STEP;
                } else {
                    blinkDelay = MAX_BLINK_DELAY;
                }
                Serial.print("New blink speed from button: ");
                Serial.println(blinkDelay);
            }
        }
        lastButtonState = currentButtonState;  
    }
}

#endif
