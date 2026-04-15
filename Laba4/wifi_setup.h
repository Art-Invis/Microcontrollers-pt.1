#ifndef WIFI_SETUP_H
#define WIFI_SETUP_H

const char* ssid = "****";
const char* password = "****";

void connectToWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi connected");
}

#endif
