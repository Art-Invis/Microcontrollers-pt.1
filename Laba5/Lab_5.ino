#include "wifi_setup.h"
#include "firebase_setup.h"
#include "sensors.h"
#include "display.h"

void setup() {
  Serial.begin(115200);
  initWiFi();
  configTime(3 * 3600, 0, "pool.ntp.org", "time.nist.gov");
  initFirebase();
  initSensors();
  initDisplay();
  showSplashScreen();
}

void loop() {
  updateTime();

  if (millis() - lastUpdate > updateInterval) {
    readSensors();
    sendSensorData();
    lastUpdate = millis();
  }

  handleDisplaySlides();
  delay(500);
}
