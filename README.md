# 🚀 Arduino Planetary Lander

Simulates a planetary lander using an ultrasonic sensor and servo motors.

## 🔗 Tinkercad Simulation
[View on Tinkercad](https://www.tinkercad.com/things/2SoOtA97ULH-arduino-based-lander?sharecode=6GvJP1rtzBVp1LRZAnJJ8kIT5nNZYdtq362znjOIJeY)

## ⚙️ How It Works
- HC-SR04 sensor measures distance to ground
- When distance < 150 cm → all 4 servos deploy to 160°
- When distance ≥ 150 cm → servos retract to 0°

## 🛠️ Components
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- 4x Servo Motors

## 📌 Pin Configuration
| Component | Pin |
|---|---|
| Trigger | 7 |
| Echo | 8 |
| Servo 1 | 2 |
| Servo 2 | 3 |
| Servo 3 | 4 |
| Servo 4 | 5 |

## 📷 Circuit
![Circuit Diagram](arduinolandercircuit.png)
