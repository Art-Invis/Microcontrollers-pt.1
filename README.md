# 💻 Microcontrollers Part 1: IoT & Embedded Systems

## 📌 About This Repository
This repository contains a progressive series of laboratory works and a final capstone IoT project developed during the "Microcontrollers" course at **Lviv Polytechnic National University (CSA Department)**. 

The projects demonstrate a complete journey from basic GPIO manipulation to building a full-stack, cloud-connected Internet of Things (IoT) ecosystem using the **ESP8266 (Wemos D1 Mini)** platform.

## 🛠️ Core Tech Stack
* **Hardware:** ESP8266 (Wemos D1 Mini), SSD1306 OLED, DS18B20, SG90 Servo, Analog Sensors.
* **Languages:** C/C++ (Arduino framework), HTML, CSS, JavaScript.
* **Protocols:** Wi-Fi, MQTT (TLS), HTTP, UART, I²C, 1-Wire, NTP.
* **Cloud & Backend:** Firebase Realtime Database, HiveMQ Cloud.

---

## 📂 Project Index

### 🧪 [Lab 1: ESP8266 Basics & Local Web UI](./Lab_1)
* **Focus:** GPIO control, hardware debouncing, and basic asynchronous HTTP web servers.
* **Highlights:** Remote LED algorithm control via a locally hosted Web UI.

### 🧪 [Lab 2: UART Peer-to-Peer Communication](./Laba2)
* **Focus:** Device-to-device serial communication.
* **Highlights:** Two ESP8266 nodes exchanging Octal commands over UART, synchronizing hardware algorithms across distinct Web Servers.

### 🧪 [Lab 3: Multi-Sensor Node & Firebase Integration](./Laba-3)
* **Focus:** I²C, 1-Wire, and cloud data synchronization.
* **Highlights:** Aggregating data from DS18B20 and Analog Water sensors, syncing time via NTP, and displaying animated UIs on an OLED display while fetching schedules from Firebase.

### 🧪 [Lab 4: Cloud MQTT via TLS (HiveMQ)](./Laba-4)
* **Focus:** Secure Pub/Sub messaging architecture.
* **Highlights:** Establishing a TLS-encrypted connection to a global HiveMQ broker, parsing remote payload commands, and triggering hardware actions safely from anywhere in the world.

### 🏆 [Lab 5 (Capstone): AquaAssistant - Full-Stack IoT System](./Laba-5)
* **Focus:** Complete IoT product development.
* **Highlights:** A fully automated smart aquarium manager. Features real-time telemetry (water level, temperature), an OLED interface, an automated servo-driven feeder, and a custom Web Dashboard for remote monitoring, scheduling, and history logging via Firebase.

---

## 🚀 Repository Structure
```text
Microcontrollers_pt.1/
├── Lab_1/          # GPIO & HTTP Web Server
├── Laba2/          # UART Communication
├── Laba-3/         # I2C, 1-Wire & Basic Firebase
├── Laba-4/         # Secure MQTT (HiveMQ)
├── Laba-5/         # AquaAssistant (Capstone Project)
└── README.md       # Repository overview (This file)