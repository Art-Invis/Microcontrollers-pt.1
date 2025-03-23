# Lab 2: Inter-Controller UART Communication & Web UI

## 📌 Overview
This project explores device-to-device communication by establishing a serial connection (UART) between two **Wemos D1 Mini (ESP8266)** microcontrollers. Each controller hosts its own Web Server with a UI that allows users to send commands to the partner node, triggering specific hardware algorithms remotely.

> **Note:** This repository contains the code for **Node A (Variant 4)**. It is designed to work in tandem with a partner's **Node B (Variant 3)**. The detailed academic task and KiCad schematics can be found in the assignments folder.

## ⚙️ System Architecture & UART Specs
To ensure synchronized data exchange, both microcontrollers are configured with strictly matching serial parameters:
* **Baud Rate:** `28800`
* **Data Bits:** `8`
* **Parity:** `Even`
* **Stop Bits:** `1`
* **Data Format:** Commands are transmitted and parsed in **Octal (OCT)** format.

## 🔄 Interaction Logic
Both nodes feature a default state where LEDs blink sequentially. The behavior changes based on UART commands triggered via the Web UI:

### My Node (This Repository)
* **Action (TX):** Sending the octal representation of the command **`S`** via the Web UI stops the LED sequence on the partner's node and starts a 15-second pause timer.
* **Reaction (RX):** Upon receiving the octal command **`F`** from the partner, the local LED sequence speed increases significantly.

### Partner Node 
* **Action (TX):** Sends command **`F`** to speed up this node's LEDs.
* **Reaction (RX):** Pauses local LEDs for 15 seconds upon receiving **`S`**.

## 📂 Project Structure
The firmware is modularized for better maintainability:
```text
Laba2/
├── config.h         # Wi-Fi credentials and UART configuration parameters
├── Lab_2.ino        # Main application loop, UART serial event handling
├── led_control.h    # LED state machine and timer logic (15s delay & fast blink)
├── README.md        # Project documentation
└── webpage.h        # HTML/JS payload for the Web Server UI


## 🚀 Getting Started

### Prerequisites
* 2x Wemos D1 Mini (ESP8266) boards (one for you, one for a partner).
* Arduino IDE with ESP8266 core installed.
* Jumper wires to cross-connect `TX` to `RX` and `RX` to `TX` between the boards (ensure shared `GND`).

### Setup
1. Clone this branch locally.
2. Open `config.h` and configure your local Wi-Fi credentials.
3. Flash the code to your Wemos D1 Mini.
4. Open the Serial Monitor (set to `28800` baud, Even Parity) to view debug messages and find your IP address.
5. Access the IP address via a web browser to open the control interface.
6. Connect the UART pins to the partner's configured board and use the Web UI to test inter-controller commands.

## 📈 Results
The project successfully demonstrates peer-to-peer IoT communication. By combining asynchronous HTTP web servers with hardware-level UART serial communication, the system effectively coordinates distributed physical actions (LED timing algorithms) across multiple devices in real-time.

