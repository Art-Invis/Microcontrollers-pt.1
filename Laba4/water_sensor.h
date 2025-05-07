#ifndef WATER_SENSOR_H
#define WATER_SENSOR_H

#define WATER_PIN A0
int waterLevel = 0;

void measureWaterLevel() {
  int raw = analogRead(WATER_PIN);
  waterLevel = constrain(map(raw, 1023, 0, 0, 100), 0, 100);

  Serial.print("💧 Water Level: ");
  Serial.print(waterLevel);
  Serial.println(" %");

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Command: WATER_CHECK");

  display.setTextSize(2);
  display.setCursor(0, 25);
  display.print("Water: ");
  display.print(waterLevel);
  display.println("%");

  display.display();
}

#endif
