# Autonomous-Surveillance-and-Hazards-Detection-Bot
# 🤖🔥 Smart Fire Detection & Surveillance Robot

A multifunctional **IoT-based robot** that performs **fire detection**, **obstacle avoidance**, **line following**, and **mobile app-based surveillance**. Built with **ESP32**, **Arduino UNO**, and integrated with **Firebase** and **Blynk** for real-time data monitoring and control.

---

## 🛠️ Tech Stack & Components

| Component         | Description                                     |
|------------------|-------------------------------------------------|
| 🔌 ESP32 + Arduino UNO | Main controller units (Wi-Fi + analog control) |
| 🌫️ MQ2 Sensor        | Detects smoke/gas (fire indicator)           |
| 🌡️ DHT11 Sensor      | Measures temperature and humidity            |
| 🟪 IR Sensors        | For line following                          |
| 📏 Ultrasonic Sensor | For obstacle detection and avoidance         |
| 📟 OLED / LCD Display| Shows live sensor data and system status     |
| 🔊 Buzzer            | Alerts during fire detection                 |
| ☁️ Firebase Realtime DB | Logs real-time sensor data via Wi-Fi       |
| 📱 Blynk / MIT App Inventor | Mobile app integration for remote monitoring |

---

## 🧠 Features

- 🔥 **Fire and Smoke Detection** (MQ2 with buzzer alert)
- 🤖 **Line Following** (IR sensor-based path control)
- 🚧 **Obstacle Avoidance** (Ultrasonic sensor)
- 📡 **Real-Time Firebase Logging** (via ESP32 Wi-Fi)
- 📺 **OLED / LCD Display Output** (on-device feedback)
- 📲 **Mobile App Control & Alerts** (Blynk / MIT App)

---

## 📷 System Overview

[ MQ2 ] [ DHT11 ] [ IR Sensors ] [ Ultrasonic ]
| | | |
[Arduino UNO] ---> Core Control
|
[ESP32 Wi-Fi] ---> Firebase + Mobile App 🌐📱
|
[OLED / LCD] + 🔊 Buzzer


---

### 🔧 Setup Instructions

#### ✅ Software

- Arduino IDE (ESP32 board support)
- Firebase ESP32 Library
- Blynk or MIT App Inventor
- Required Arduino libraries:
  - `WiFi.h`, `FirebaseESP32.h`
  - `DHT.h`, `MQ2.h`, `LiquidCrystal.h` or `Adafruit_SSD1306.h`
  - `BlynkSimpleEsp32.h`

#### ✅ Hardware Wiring (Example)

| Device           | Pin Mapping (ESP32/Arduino) |
|------------------|-----------------------------|
| MQ2              | A0 (Arduino)                |
| DHT11            | D2                          |
| IR Sensors       | D3, D4                      |
| Ultrasonic       | TRIG - D5, ECHO - D6        |
| OLED Display     | I2C (SDA - D21, SCL - D22)  |
| Buzzer           | D7                          |
| ESP32 Serial     | Connected to Arduino Tx/Rx  |

---

## 📲 Mobile App Integration

### 🔹 Blynk App Setup

1. Install **Blynk IoT** from Play Store
2. Create new project:
   - Add widgets: Gauge (Temp, Smoke), LED (Fire Alert), Terminal, etc.
   - Copy **Auth Token**
3. Use code in `blynk_integration.ino`:
```cpp
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "SmartFireBot"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

---

### 🔧 Setup Instructions

#### ✅ Software

- Arduino IDE (ESP32 board support)
- Firebase ESP32 Library
- Blynk or MIT App Inventor
- Required Arduino libraries:
  - `WiFi.h`, `FirebaseESP32.h`
  - `DHT.h`, `MQ2.h`, `LiquidCrystal.h` or `Adafruit_SSD1306.h`
  - `BlynkSimpleEsp32.h`

#### ✅ Hardware Wiring (Example)

| Device           | Pin Mapping (ESP32/Arduino) |
|------------------|-----------------------------|
| MQ2              | A0 (Arduino)                |
| DHT11            | D2                          |
| IR Sensors       | D3, D4                      |
| Ultrasonic       | TRIG - D5, ECHO - D6        |
| OLED Display     | I2C (SDA - D21, SCL - D22)  |
| Buzzer           | D7                          |
| ESP32 Serial     | Connected to Arduino Tx/Rx  |

---

## 📲 Mobile App Integration

### 🔹 Blynk App Setup

1. Install **Blynk IoT** from Play Store
2. Create new project:
   - Add widgets: Gauge (Temp, Smoke), LED (Fire Alert), Terminal, etc.
   - Copy **Auth Token**
3. Use code in `blynk_integration.ino`:
```cpp
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "SmartFireBot"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";
