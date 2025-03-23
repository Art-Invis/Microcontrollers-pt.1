#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
#include <ArduinoJson.h>
#include "config.h"
#include "led_control.h"

void setup() {
    Serial.begin(28800, SERIAL_8E1);
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(LED3_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);

    setupServer();  
}

void loop() {
    handleSerialInput();  
    handleButtonPress();  
    updateLeds();         // Логіка перемикання світлодіодів
}
