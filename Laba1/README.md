# Lab 1: ESP8266 Web-Controlled LED Interface

## 📌 Overview
This project demonstrates a foundational IoT implementation using the **Wemos D1 Mini (ESP8266)**. It focuses on combining physical GPIO interactions (buttons, LEDs, hardware debouncing) with a remote HTTP Web UI to control the device's execution algorithms. 

> **Note:** The detailed academic task, variant specifications, and simulation schematics can be found in [`../Assigments/Assigment_1.md`](../Assigments/Assigment_1.md).

## ⚙️ Features
* **Remote Web Control:** A lightweight HTTP server hosting an interactive web page to trigger algorithms and reset states remotely.
* **Hardware Interfacing:** Reliable physical button handling on `GPIO13` using an external pull-up resistor and software debouncing.
* **Algorithm Execution:** Sequential LED blinking logic (`D4` → `D5` → `D6`). The blink rate significantly increases upon receiving a trigger (via physical button or Web UI) and reverts to default upon a reset command.

## 🛠 Tech Stack & Hardware
* **Firmware:** C++ (Arduino IDE)
* **Hardware:** Wemos D1 Mini (ESP8266), Tactile Button, LEDs, 10kΩ Resistor, Breadboard.
* **Protocols:** Wi-Fi, HTTP.

## 📂 Project Structure
To maintain clean code and separation of concerns, the firmware is modularized:

* `Lab1.ino` — Main application loop and setup initialization.
* `wifi.h` — Wi-Fi credentials and network connection logic.
* `webPage.h` — HTML/CSS payload for the remote interface.
* `ledControl.h` — GPIO pin definitions and LED algorithm logic.

## 🚀 Getting Started

### Prerequisites
1. [Arduino IDE](https://www.arduino.cc/en/software) installed.
2. ESP8266 board package added to Arduino IDE's Boards Manager.

### Installation & Setup
1. Clone the repository and switch to the laboratory branch:
   ```bash
   git clone <your-repo-url>
   git checkout Lab_1
   ```
2. Open `Laba1/Lab1.ino` in your Arduino IDE.
3. Configure your network credentials. Open `wifi.h` and update the constants:
   ```cpp
   const char* ssid = "YOUR_WIFI_SSID";
   const char* password = "YOUR_WIFI_PASSWORD";
   ```
4. Connect the Wemos D1 Mini via USB and select the appropriate board and COM port in the IDE.
5. Click **Upload**.

### Usage
1. Open the **Serial Monitor** (set baud rate to `115200`).
2. Wait for the device to connect to your Wi-Fi network. The assigned IP address will be printed in the console.
3. Open a web browser and navigate to the printed IP address (e.g., `http://192.168.1...`).
4. Use the on-screen buttons to interact with the LEDs or press the physical button on the breadboard.
