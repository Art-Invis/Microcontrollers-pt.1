# Lab 4: Cloud MQTT Broker Integration via TLS (HiveMQ)

## 📌 Overview
This project transitions the IoT ecosystem from local network interactions to a globally accessible cloud architecture. The **Wemos D1 Mini (ESP8266)** is configured as a secure MQTT client connected to **HiveMQ Cloud** via TLS. The device subscribes to a specific cloud topic, listens for remote commands, triggers local hardware reads (analog water sensor), and updates the local OLED interface in real-time based on the received payload.

> **Note:** The complete academic task and KiCad schematics are available in the [`Assigments`](Assigments/) directory.

## ⚙️ Features
* **Secure Cloud Messaging:** Establishes a TLS-encrypted connection to an external HiveMQ MQTT broker.
* **Topic Subscription:** Actively listens to the `emqx/esp8266` topic for incoming string payloads.
* **Command Parsing & Execution:**
  * Payload `WATER_CHECK`: Triggers an ADC read from the water level sensor and displays the percentage on the OLED.
  * Invalid Payloads: Traps unknown commands and displays an "Unknown command" error state on the screen.
* **Dual-Output Debugging:** All network states, MQTT connection events, and parsed messages are simultaneously logged to the Serial Monitor and rendered graphically on the I2C OLED display.

## 🛠 Tech Stack & Hardware
* **Microcontroller:** Wemos D1 Mini (ESP8266)
* **Peripherals:** 0.96" I2C OLED Display, Analog Water Sensor.
* **Protocols:** Wi-Fi, MQTT (Pub/Sub), TLS/SSL.
* **Cloud Platform:** HiveMQ Cloud.
* **Libraries:** `PubSubClient`, `ESP8266WiFi`, `Wire.h` (Adafruit SSD1306).

## 📂 Project Structure
```text
Laba-4/
├── Assigments/      # Task descriptions and KiCad schematics
├── credentials.h    # Wi-Fi configs, HiveMQ URL, port (8883), and user/pass
├── Lab_4.ino        # Main loop, Wi-Fi/MQTT connection management
├── mqtt_handler.h   # Payload parsing and topic subscription logic
├── display.h        # OLED UI updates for sensor readings and errors
└── README.md        # Project documentation
```

## 🚀 Getting Started

### Prerequisites
* A free [HiveMQ Cloud](https://www.hivemq.com/mqtt-cloud-broker/) account and cluster.
* Wemos D1 Mini with wired OLED and Water Sensor.

### Setup & Usage
1. Clone the repository and navigate to the `Laba-4` directory.
2. Update the `credentials.h` file with your network and broker details:
   ```cpp
   #define WIFI_SSID "YOUR_WIFI"
   #define WIFI_PASSWORD "YOUR_WIFI_PASS"
   #define MQTT_BROKER "your-cluster.hivemq.cloud"
   #define MQTT_PORT 8883
   #define MQTT_USER "your_mqtt_username"
   #define MQTT_PASS "your_mqtt_password"
   ```
3. Flash the firmware to the ESP8266.
4. Open the HiveMQ Web Client (or any MQTT client like MQTTX) and connect to your broker.
5. Publish the message `WATER_CHECK` to the topic `emqx/esp8266` and watch the OLED display update dynamically.
