#ifndef DISPLAY_UTILS_H
#define DISPLAY_UTILS_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void displayUnknownCommand(String cmd) {
  Serial.println("❌ Unknown command");

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Command: ");
  display.println(cmd);

  display.setCursor(0, 20);
  display.setTextSize(1);
  display.println("Unknown command");
  display.setCursor(0, 40);
  display.println("* Try: WATER_CHECK");

  display.display();
}

#endif
