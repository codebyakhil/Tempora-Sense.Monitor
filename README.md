# 🌡️ Arduino Temperature Monitor (LM35 + LCD)

A simple embedded systems project that reads real-time ambient temperature using the **LM35 analog temperature sensor** and displays it on a **16x2 LCD screen**, built with **Arduino Uno**.

![Platform](https://img.shields.io/badge/platform-Arduino-00979D?logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/language-C%2FC%2B%2B-blue)
![License](https://img.shields.io/badge/license-MIT-green)

---

## 📋 Overview

This project demonstrates how to interface an **analog sensor** with a microcontroller and display live sensor data on an output module. The LM35 sensor outputs a voltage directly proportional to temperature, which is read by the Arduino, converted into Celsius/Fahrenheit, and shown on an LCD in real time.

---

## 🛠️ Components Used

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno | 1 | Microcontroller board |
| LM35 Temperature Sensor | 1 | Measures ambient temperature |
| 16x2 LCD Display (HD44780) | 1 | Displays temperature reading |
| 10k Potentiometer | 1 | Adjusts LCD contrast |
| 220Ω Resistor | 1 | LCD backlight current limiting |
| Breadboard | 1 | Prototyping |
| Jumper Wires | ~15 | Connections |

---

## 🔌 Circuit / Wiring

**LM35 Sensor → Arduino**
| LM35 Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| OUT | A0 |
| GND | GND |

**16x2 LCD → Arduino** (4-bit mode)
| LCD Pin | Arduino Pin |
|---|---|
| RS | D12 |
| E | D11 |
| D4 | D5 |
| D5 | D4 |
| D6 | D3 |
| D7 | D2 |
| VSS | GND |
| VDD | 5V |
| V0 | Potentiometer wiper |
| RW | GND |
| A (backlight +) | 5V (via 220Ω resistor) |
| K (backlight -) | GND |

> See `images/circuit_diagram.png` for a visual wiring reference (add your own photo/Fritzing diagram here).

---

## ⚙️ How It Works

1. The **LM35 sensor** continuously outputs an analog voltage proportional to the surrounding temperature (~10mV per °C).
2. The Arduino reads this voltage via `analogRead()` on pin **A0**, sampling multiple times and averaging for a stable reading.
3. The raw ADC value (0–1023) is converted to actual voltage, then to temperature in Celsius using the LM35's known scale.
4. The temperature is also converted to Fahrenheit for display.
5. Both values are shown in real time on the **16x2 LCD**, updating every second.
6. Readings are also printed to the **Serial Monitor** for debugging.

---

## 📁 Project Structure

```
arduino-temp-monitor/
├── temperature_monitor.ino   # Main Arduino sketch
├── README.md                  # Project documentation
├── images/                    # Circuit diagrams / photos
└── LICENSE                    # MIT License
```

---

## 🚀 Getting Started

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Connect the components as per the wiring table above.
3. Open `temperature_monitor.ino` in the Arduino IDE.
4. Select **Board: Arduino Uno** and the correct **COM Port**.
5. Click **Upload**.
6. Open the **Serial Monitor** (9600 baud) to view debug readings, and watch the LCD for live temperature.

---

## 🔮 Future Improvements

- Add a **buzzer/LED alert** when temperature crosses a set threshold.
- Send data to the cloud using an **ESP8266/ESP32 Wi-Fi module** for remote/IoT monitoring.
- Log historical data to an **SD card module**.
- Replace LM35 with a **DHT11/DHT22** to also monitor humidity.

---

## 📄 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

---

## 🙋 Author

Built as a hands-on embedded systems / IoT learning project to understand analog sensor interfacing with microcontrollers.
