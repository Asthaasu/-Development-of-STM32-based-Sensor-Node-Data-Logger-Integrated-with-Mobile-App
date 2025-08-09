# ESP8266 + STM32 Temperature Logging & LED Control

## 📌 Overview
This project integrates an **ESP8266** and an **STM32** to monitor temperature from a DS18B20 sensor, control an LED automatically or manually via **Blynk**, and log temperature data to **ThingSpeak**.

## 🛠 Features
- Real-time temperature monitoring with DS18B20
- Automatic LED control based on temperature threshold
- Manual LED control through Blynk mobile app
- Data logging to ThingSpeak for cloud monitoring

## 📂 Project Structure
- `esp8266_code.ino` → Handles WiFi, Blynk control, and ThingSpeak logging
- `stm32_code.ino` → Reads temperature and controls LED
- `README.md` → Project documentation

## 🚀 How It Works
1. **STM32** reads temperature and sends it to **ESP8266** over UART.
2. **ESP8266** uploads the data to **ThingSpeak** every 2 seconds.
3. **Blynk App** can send manual LED control commands to STM32.
4. LED automatically turns ON if temperature < 25°C (in auto mode).

## 🔧 Hardware Required
- ESP8266 (NodeMCU)
- STM32 (Blue Pill)
- DS18B20 Temperature Sensor
- LED + Resistor
- Breadboard & Jumper Wires

## 📲 Setup
1. Configure your **WiFi credentials** in `esp8266_code.ino`.
2. Update **ThingSpeak API Key** and **Blynk Auth Token**.
3. Upload respective codes to **ESP8266** and **STM32**.
4. Open **Blynk App** to control and monitor.

---
👤 Author: Astha Pankaj

![circuit Layout](https://github.com/user-attachments/assets/eaae7951-2e06-4451-8b40-dd34829157f3)


https://github.com/user-attachments/assets/ec01ce43-dc91-46fe-b1ae-d257e9abb670

![layout](https://github.com/user-attachments/assets/436d63ee-2a1a-40b9-b634-3a054ab7a18a)

