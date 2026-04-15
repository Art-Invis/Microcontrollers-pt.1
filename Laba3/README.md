# Lab 3: Multi-Sensor IoT Node with I²C OLED & Firebase Integration

## 📌 Overview
This project advances the IoT ecosystem by integrating multiple hardware protocols and cloud services. The **Wemos D1 Mini (ESP8266)** acts as a central node that aggregates environmental data (water level, temperature), synchronizes real-time data via NTP, and communicates with a remote **Firebase Realtime Database**. The system features a local UI with animations on an OLED display to provide immediate visual feedback.

This architecture serves as a robust foundation for practical environmental monitoring systems (e.g., smart aquarium assistants or weather stations).

## ⚙️ Features
* **Multi-Protocol Sensor Integration:**
  * **I²C:** SSD1306 OLED Display for local UI.
  * **1-Wire:** DS18B20 Digital Temperature Sensor.
  * **Analog (ADC):** Analog Water Level Sensor.
* **Cloud & Network Capabilities:**
  * Wi-Fi connectivity with status monitoring.
  * **NTP (Network Time Protocol):** Fetches accurate real-world time.
  * **Firebase Integration:** Reads scheduled events and acts as a remote fallback for sensor data.
* **Dynamic User Interface (OLED):**
  * Animated Splash Screen on boot with project branding.
  * Custom iconography for temperature, water levels, and Wi-Fi status.
  * Pagination system: The display automatically cycles between data screens every 5 seconds.

## 🛠 Tech Stack & Hardware
* **Microcontroller:** Wemos D1 Mini (ESP8266)
* **Peripherals:** 0.96" I2C OLED Display, DS18B20 (Temp), Analog Water Sensor.
* **Software/Libraries:** C++ (Arduino IDE), `Wire.h` (I2C), `OneWire.h` & `DallasTemperature.h`, Firebase ESP8266 Client.
* **Cloud Services:** Firebase Realtime Database.

## 📂 Project Structure
```text
Laba-3/
├── credentials.h    # Wi-Fi and Firebase API keys (Keep Private!)
├── Lab_3.ino        # Main application loop and task scheduling
├── display_ui.h     # OLED drawing logic, custom icons, and animations
├── sensors.h        # I2C, 1-Wire, and ADC initialization and reading routines
└── README.md        # Project documentation
```

## 🚀 Getting Started

### Prerequisites
* Wemos D1 Mini and the required sensors.
* A configured Firebase project (Realtime Database).
* Arduino IDE with ESP8266 board support and necessary sensor/display libraries (e.g., Adafruit SSD1306).

### Setup
1. Clone the repository and navigate to the `Laba-3` directory.
2. Create a `credentials.h` file (or update the existing one) with your network and cloud details:
   ```cpp
   #define WIFI_SSID "YOUR_WIFI"
   #define WIFI_PASSWORD "YOUR_PASSWORD"
   #define FIREBASE_HOST "your-project.firebaseio.com"
   #define FIREBASE_AUTH "your_database_secret"
   ```
3. Wire the components according to the KiCad schematic provided in the assignments folder.
   * *Note: Ensure the DS18B20 has the appropriate 4.7kΩ pull-up resistor.*
4. Flash the firmware and monitor the Serial output (baud rate: 115200) for connection statuses and debug logs.
