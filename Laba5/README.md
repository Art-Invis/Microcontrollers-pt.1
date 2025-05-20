# Lab 5: AquaAssistant - Full-Stack IoT Aquarium Manager

## 📌 Overview
This capstone project represents a complete, end-to-end IoT ecosystem designed to automate and monitor aquarium conditions. Dubbed **AquaAssistant**, the system uses an ESP8266 edge node to aggregate environmental telemetry, control physical actuators (servo-driven feeder), and maintain bidirectional real-time synchronization with a **Firebase Realtime Database**. 

Coupled with a custom Web Dashboard, it allows users to monitor water quality parameters, review historical logs, and trigger or schedule automated feeding cycles remotely.

> **Note:** Hardware schematics, KiCad designs, and academic requirements are located in the [`Assigments`](Assigments/) folder.

## ⚙️ Core Features
* **Automated & Remote Feeding:** Utilizes an SG90 servo motor to dispense food. Can be triggered manually via the web app or scheduled autonomously based on Firebase timestamps.
* **Environmental Telemetry:** Continuously tracks water temperature (DS18B20) and water levels (Analog ADC). Drops below safety thresholds trigger automated Cloud Alerts.
* **Cloud Backend (Firebase):** * Real-time state management for feeding events (`Idle` vs `Feed`).
  * Time-series data logging for temperature and water levels.
  * Immutable feed logs detailing exactly when the system dispensed food (`Auto` or `Manual`).
* **Local UI with Animations:** An SSD1306 OLED acts as the local console, utilizing smooth fade-animations to transition between telemetry slides every 5 seconds.
* **Web Dashboard:** A responsive HTML/JS frontend providing graphical charts (historical data), system status alerts, and remote execution buttons.

## 🛠 Tech Stack & Hardware
* **Microcontroller:** Wemos D1 Mini (ESP8266)
* **Actuators:** SG90 Micro Servo Motor (PWM)
* **Sensors:** DS18B20 (1-Wire), Analog Water Level Sensor
* **Display:** 0.96" I2C OLED (SSD1306)
* **Cloud Platform:** Firebase Realtime Database
* **Firmware:** C++, Firebase ESP8266 Client, NTP Time Synchronization

## 📂 Architecture & Data Flow
The architecture strictly follows a 3-tier IoT model:
1. **Edge (Hardware):** Captures data, runs local safety checks, and manages the OLED UI.
2. **Backend (Firebase):** Acts as the centralized state manager and historical ledger.
3. **Client (Web App):** Fetches time-series data for visualization and writes commands to the Firebase command nodes.

## 🚀 Getting Started

### Setup Requirements
1. Flash the ESP8266 with your Wi-Fi and Firebase credentials.
2. Ensure the structural integrity of the 1-Wire bus by including a 4.7kΩ pull-up resistor for the DS18B20.
3. Deploy the web interface files to a standard web server or view locally.
4. Verify the initial state of the Firebase database (ensure the `/Feeder/Status` node is set to `Idle`).