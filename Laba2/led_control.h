#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>

#define LED1_PIN 2
#define LED2_PIN 14
#define LED3_PIN 12
#define BUTTON_PIN 13

#define MIN_BLINK_DELAY 50
#define MAX_BLINK_DELAY 1000
#define BLINK_STEP 300

char COMMAND_FAST = 0x06;
char COMMAND_STOP = 0x23;

volatile int blinkDelay = MAX_BLINK_DELAY;
unsigned long previousMillis = 0;
unsigned long buttonPreviousMillis = 0;
const int buttonDebounceDelay = 300;
int state = 0;
bool commandInProgress = false;

void increaseSpeed() {
    if (blinkDelay > MIN_BLINK_DELAY) {
        blinkDelay -= BLINK_STEP;
    } else {
        blinkDelay = MAX_BLINK_DELAY;
    }
}

void stopBlinking() {
    if (!commandInProgress) {
        commandInProgress = true;
        Serial.write(COMMAND_STOP);
        commandInProgress = false;
    }
}

void handleSerialInput() {
    if (Serial.available() > 0) {
        char command = Serial.read();
        if (command == COMMAND_FAST) {
            increaseSpeed();
        } else if (command >= '0' && command <= '9') {
            state = command - '0';
        }
    }
}

void handleButtonPress() {
    if (digitalRead(BUTTON_PIN) == LOW) {
        if (millis() - buttonPreviousMillis >= buttonDebounceDelay) {
            buttonPreviousMillis = millis();
            increaseSpeed();
        }
    }
}

void updateLeds() {
    if (millis() - previousMillis >= blinkDelay) {
        previousMillis = millis();
        digitalWrite(LED1_PIN, state == 0);
        digitalWrite(LED2_PIN, state == 1);
        digitalWrite(LED3_PIN, state == 2);
        state = (state + 1) % 3;
    }
}

#endif
