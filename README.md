# Smart Thermometer Display 🌡️

This Arduino project uses the **AHT10** temperature and humidity sensor and a **0.96" SSD1306 OLED display** to show real-time readings with icons.

## 🧠 Features
- Displays temperature and humidity
- Shows icon based on temperature/humidity level
- Compact, I2C-based hardware setup

## 🧰 Components Used
- Arduino Uno
- AHT10 Sensor (I2C)
- SSD1306 OLED Display 128x64 (I2C)
- Jumper Wires & Breadboard

## 🛠️ Wiring

| AHT10 Pin | Arduino Pin |
|----------|-------------|
| VIN      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

| OLED Pin | Arduino Pin |
|----------|-------------|
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

## 📦 Libraries Used

- `Adafruit AHTX0`
- `Adafruit SSD1306`
- `Adafruit GFX`

Install from Arduino Library Manager.
