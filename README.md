# Game of Boards: ESP Microcontroller Course Suite 🚀

Welcome to the **ESP Microcontroller (ESP32 / ESP8266) Coding Suite** for the *Game of Boards* course. This repository contains 7 complete, production-ready, non-blocking Arduino sketches tailored specifically for ESP microcontrollers.

---

## ⚡ Important Hardware & Voltage Guidelines

When teaching or working with ESP32 / ESP8266 boards, ensure students follow these safety rules:

1. **3.3V Logic Level**: ESP microcontrollers operate strictly on **3.3V logic**. Never supply 5V directly to any GPIO pin.
2. **Current Limits**: ESP GPIO pins source up to ~12mA–20mA max. Always place a **220Ω–330Ω current-limiting resistor** in series with LEDs.
3. **12-Bit ADC**: ESP32 ADCs are **12-bit** ($0 - 4095$ range) accepting $0.0\text{V} - 3.3\text{V}$, compared to traditional 10-bit ($0 - 1023$) 5V Arduinos.
4. **Dedicated Power for Motors**: Servo motors draw high peak currents ($>500\text{mA}$) and must be powered from an **external 5V supply** with a **common ground** tied to the ESP.

---

## 📂 Repository Structure & Sketches

Each sketch is located in its own directory matching Arduino IDE project conventions:

| # | Directory / Sketch Name | Key Concepts & Peripherals | GPIO Mapping |
|---|---|---|---|
| 1 | [`Task1_Basic_LED_Blink/`](./Task1_Basic_LED_Blink/Task1_Basic_LED_Blink.ino) | Digital output, HIGH/LOW states, standard delay | GPIO 2 |
| 2 | [`Task2_Serial_Controlled_Blink/`](./Task2_Serial_Controlled_Blink/Task2_Serial_Controlled_Blink.ino) | UART Serial communication (115200 baud), non-blocking `millis()` state machine | GPIO 2, USB UART |
| 3 | [`Task3_LED_PWM_Fading/`](./Task3_LED_PWM_Fading/Task3_LED_PWM_Fading.ino) | ESP32 LEDC PWM hardware timers, 10-bit resolution fading | GPIO 4 |
| 4 | [`Task4_Pattern_Blink/`](./Task4_Pattern_Blink/Task4_Pattern_Blink.ino) | Structured modular functions, Morse code S.O.S. pattern (`... --- ...`) | GPIO 2 |
| 5 | [`Task5_Servo_Motor_PWM/`](./Task5_Servo_Motor_PWM/Task5_Servo_Motor_PWM.ino) | 50 Hz PWM servo sweep using `ESP32Servo` library | GPIO 18, External 5V |
| 6 | [`Task6_Analog_Sensor_Read/`](./Task6_Analog_Sensor_Read/Task6_Analog_Sensor_Read.ino) | 12-bit ADC sampling ($0-4095$), voltage calculation ($0-3.3\text{V}$) | GPIO 34 |
| 7 | [`Task7_Sensor_To_Servo_Mapping/`](./Task7_Sensor_To_Servo_Mapping/Task7_Sensor_To_Servo_Mapping.ino) | Exponential Moving Average (EMA) filtering, deadband thresholding, analog mapping | GPIO 34 (ADC) $\rightarrow$ GPIO 18 (Servo) |

---

## 🛠️ Required Arduino IDE Libraries & Setup

1. **Board Support Package**:
   - Open Arduino IDE $\rightarrow$ **Preferences** $\rightarrow$ Additional Board Manager URLs:
     `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
   - Go to **Tools $\rightarrow$ Board $\rightarrow$ Boards Manager** and install **esp32** by Espressif Systems.
2. **Libraries**:
   - Install **ESP32Servo** library via **Tools $\rightarrow$ Manage Libraries...** (required for Task 5 & Task 7).

---

## 💻 Quick Code Summary

### Task 1: Basic LED Blink
Simple 1-second interval toggle of onboard LED on GPIO 2.

### Task 2: Serial-Controlled Blink
Listens on Serial Monitor (115200 baud) for `'1'` (ON), `'0'` (OFF), or `'b'` (Blink) to toggle modes non-blockingly.

### Task 3: LED PWM Fading
Demonstrates 10-bit PWM fading using ESP32's hardware LEDC timer peripheral with compatibility for both Core v2.x and Core v3.x.

### Task 4: Pattern Blink (SOS)
Modular functions execute S.O.S. Morse code timings.

### Task 5: Servo Motor PWM Control
Generates 50 Hz PWM signals via `ESP32Servo` to sweep shaft position between 0° and 180°.

### Task 6: Analog Sensor Read
Samples 12-bit ADC values ($0-4095$) from GPIO 34 and outputs converted voltage ($0-3.3\text{V}$) to Serial Monitor.

### Task 7: Sensor-to-Servo Mapping with Noise Filtering
Filters ADC electrical noise with an Exponential Moving Average (EMA) algorithm ($\alpha = 0.15$) and deadband thresholding before driving servo angles.

---

## 📜 License & Usage
This repository is created for educational purposes as part of the AutoVIT *Game of Boards* course curriculum. Free to use and modify for learning and teaching.
