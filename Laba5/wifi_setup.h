#ifndef WIFI_SETUP_H
#define WIFI_SETUP_H

#include <ESP8266WiFi.h>

const char* ssid = "****";
const char* password = "****";

void initWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ Wi-Fi connected");
}

#endif
