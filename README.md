# 🪖 Advanced Embedded Smart Helmet with Wireless Ignition Control (IoT)

## 📌 Project Overview

The **Advanced Embedded Smart Helmet with Wireless Ignition Control (IoT)** is an ESP32-based safety system designed to enhance two-wheeler rider protection.

This system ensures that the motorcycle engine starts only when:
- The helmet is properly worn
- No alcohol is detected
- Safety conditions are satisfied

The helmet unit wirelessly communicates with the bike ignition system to control engine ignition.

---

## 🚀 Key Features

- Wireless Ignition Control
- Helmet Wear Detection (Touch + PIR Sensors)
- Alcohol Detection (MQ-3 Sensor)
- GPS Location Tracking
- SOS Emergency Alert System
- GSM-based SMS Notification
- Real-time Embedded Processing using ESP32

---

## 🏗 System Architecture

### 🪖 Helmet Unit (Transmitter)
- ESP32 Microcontroller
- Touch Sensor
- PIR Sensor
- MQ-3 Alcohol Sensor
- GPS Module (NEO-6M)
- GSM Module (SIM800L)
- SOS Push Button
- Buzzer
- Rechargeable Battery

### 🏍 Bike Unit (Receiver)
- ESP32 Microcontroller
- Relay Module
- Ignition Control Circuit

---

## 🔄 Working Principle

1. The helmet detects whether it is properly worn using touch and PIR sensors.
2. The MQ-3 sensor checks for alcohol presence.
3. If helmet is worn and alcohol level is safe → ESP32 sends wireless signal.
4. Receiver ESP32 activates relay → Engine ignition enabled.
5. If alcohol is detected → Ignition is blocked.
6. When SOS button is pressed:
   - GPS module fetches current location.
   - GSM module sends emergency SMS with Google Maps link.

---

## 🛠 Technologies Used

- ESP32
- Embedded C (Arduino IDE)
- IoT Communication (WiFi / ESP-NOW)
- NEO-6M GPS Module
- SIM800L GSM Module
- MQ-3 Alcohol Sensor

---

## 📂 Repository Structure

```
Advanced-Embedded-Smart-Helmet-IoT/
│
├── Transmitter_Helmet/
│   └── helmet_code.ino
│
├── Receiver_Bike/
│   └── bike_code.ino
│
├── Circuit_Diagram/
│   └── smart_helmet_diagram.png
│
└── README.md
```

---

## 🎯 Objective

To reduce road accidents by enforcing helmet usage, preventing drunk driving, and enabling emergency location tracking using IoT and embedded systems technology.

---

## 🔐 Future Improvements

- Accident detection using accelerometer
- Cloud data logging
- Mobile app integration
- Real-time tracking dashboard

---

## 👨‍💻 Author

Your Name  
Embedded Systems & IoT Project
