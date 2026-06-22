# Smart Fire and Gas Safety System

[![Hardware](https://img.shields.io/badge/Hardware-Arduino_UNO-00979D?style=flat&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B%20/%20Arduino-00599C?style=flat&logo=c%2B%2B&logoColor=white)]()
[![Status](https://img.shields.io/badge/Status-Completed-success)]()

An automated, real-time embedded safety solution designed to detect environmental hazards, smoke concentrations, and toxic gas leaks. Built on the Arduino hardware ecosystem, this project processes data from analog air quality sensors and digital infrared flame modules to trigger immediate, localized audio-visual alarms to mitigate domestic and industrial risks.

---

## 📌 Features & Objectives

* **Dual-Hazard Monitoring:** Real-time, simultaneous scanning for open flame infrared signatures and combustible gas/smoke densities.
* **Instantaneous Alert Mechanics:** Microcontroller-driven logic triggers localized responses via active piezo buzzers and indicator LED arrays as soon as threshold boundaries are breached.
* **Edge-Threshold Tuning:** Utilizes calibrated baseline ranges to effectively eliminate false positives while preserving sensor tracking sensitivity.
* **Modular Code Structure:** Built with clean pin mappings to seamlessly allow future hardware scaling (e.g., IoT modules, LCD outputs).

---

## 🛠️ System Architecture & Hardware Setup

The system relies on a low-latency execution loop handling safety-critical edge sensor inputs:

### 1. Hardware Bill of Materials
* **Microcontroller:** Arduino UNO (ATmega328P platform)
* **Gas Sensor:** MQ-2 Gas/Smoke Sensor Module (Combustible gas, smoke, LPG)
* **Fire Sensor:** Infrared (IR) Flame Detection Sensor Module
* **Actuators:** Active Piezo Buzzer & LED State Indicators

### 2. Physical Pin Layout

```text
       ┌────────────────────────────────────────────────┐
       │                  ARDUINO UNO                   │
       └──────┬───────────┬────────────┬───────────┬────┘
              │ 5V        │ GND        │ A0        │ D2
              │           │            │           │
       ┌──────▼───────────▼──────┐     │           │
       │     MQ-2 GAS SENSOR     │     │           │
       │  (VCC, GND, Analog Out) ├─────┘           │
       └─────────────────────────┘                 │
                                                   │
       ┌─────────────────────────┐                 │
       │   IR FLAME SENSOR       │                 │
       │  (VCC, GND, Digital Out)├─────────────────┘
       └──────▲───────────▲──────┘
              │ 5V        │ GND
              │           │
       ┌──────┴───────────┴──────┐
       │   ALARM CIRCUIT         │
       │ (Buzzer & Indicator LED)├─── [ Digital Pin 8 / 9 ]
       └─────────────────────────┘
