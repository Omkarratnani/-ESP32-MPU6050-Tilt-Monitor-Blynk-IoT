# -ESP32-MPU6050-Tilt-Monitor-Blynk-IoT
Real-time tilt monitoring system using ESP32 and MPU6050 with Blynk IoT dashboard integration. Displays X, Y, Z angles for motion and orientation tracking.
# 📐 ESP32 + MPU6050 Tilt Monitoring with Blynk IoT

This project reads real-time tilt angle data (X, Y, Z axes) from an MPU6050 accelerometer module using an ESP32 microcontroller and displays the data on the Blynk IoT dashboard (mobile/web).

---

## 📦 Features

- 🔧 ESP32 with I2C MPU6050 sensor
- 🌐 WiFi connectivity
- 📲 Real-time angle data via Blynk (V2, V3, V4)
- 📉 Visual dashboard for X, Y, Z tilt angles

---

## 🔌 Circuit Diagram

| MPU6050 Pin | ESP32 Pin |
|-------------|-----------|
| VCC         | 5V        |
| GND         | GND       |
| SDA         | GPIO 21   |
| SCL         | GPIO 22   |

> ⚠️ Power the **HW-123/GY-521** with **5V** (it has a regulator).

---

## 🛠️ Libraries Required

Install these in Arduino IDE:

- Blynk (IoT version)  
- Wire  
- WiFi  
- BlynkSimpleEsp32

---

## 🚀 Getting Started

1. Clone or download this repo.
2. Open `.ino` file in Arduino IDE.
3. Replace WiFi and Blynk credentials:
   ```cpp
   char ssid[] = "Your_SSID";
   char pass[] = "Your_PASSWORD";
   char auth[] = "Your_BLYNK_AUTH_TOKEN";
