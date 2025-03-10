#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>

#define WIFI_SSID "****"
#define WIFI_PASSWORD "****"

void initWiFi() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    Serial.print("ESP IP Address: ");
    Serial.println(WiFi.localIP());
}

#endif
