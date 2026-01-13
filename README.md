# 🔥 IoT Based Automatic Fire Alarm & Extinguisher System

An **IoT-enabled automatic fire detection and extinguishing system** developed using **NodeMCU (ESP8266)** and **Blynk IoT**.  
The system detects fire, triggers an alarm, automatically activates a water pump for a fixed duration, and sends a real-time alert to the user’s smartphone.

---

## 🚀 Features

- 🔥 Fire detection using flame sensor  
- 🚨 Audible and visual alerts (Buzzer + LED)  
- 🚿 Automatic fire extinguisher using water pump  
- ⏱️ Timer-based pump control (10 seconds)  
- 📱 Real-time notification via Blynk IoT  
- 🔁 Auto reset when fire is cleared  
- 🌐 WiFi-enabled IoT monitoring  

---

## 🛠️ Hardware Requirements

- NodeMCU ESP8266  
- Fire / Flame Sensor (Digital)  
- Relay Module (5V)  
- DC Water Pump  
- Buzzer  
- LED  
- 220Ω Resistor  
- Breadboard & Jumper Wires  
- External Power Supply (6–12V for pump)

---

## 🔌 Pin Configuration (NodeMCU)

| Component | Pin |
|---------|-----|
| Fire Sensor (DO) | D5 |
| LED | D6 |
| Buzzer | D7 |
| Relay Module | D8 |

---

## 📱 Blynk IoT Configuration

1. Create a new **Template** in Blynk IoT
2. Copy:
   - `BLYNK_TEMPLATE_ID`
   - `BLYNK_AUTH_TOKEN`
3. Create an **Event**:
   - Event Name: `fire_alert`
   - Description: Fire detected! Auto extinguisher activated.

---

## ⚙️ Working Principle

1. The fire sensor continuously monitors flame.
2. When fire is detected:
   - LED turns ON
   - Buzzer activates
   - Relay switches ON the water pump
   - Pump runs for **10 seconds**
   - Alert notification is sent to the mobile phone
3. When fire is removed:
   - System resets automatically

---

## ⏱️ Timer-Based Pump Control

- Pump runs only for a fixed time (10 seconds)
- Prevents water wastage
- Protects motor from overheating
- Uses `millis()` instead of `delay()` for non-blocking IoT operation

---

## 📂 Software & Libraries

- Arduino IDE  
- ESP8266WiFi Library  
- Blynk IoT Library  

---

## 🧠 Why `millis()` Instead of `delay()`?

- Maintains WiFi connectivity
- Prevents blocking of Blynk communication
- Ensures real-time IoT operation

---

## 🎓 Applications

- Smart homes  
- Industrial fire safety  
- Warehouses  
- Server rooms  
- College minor & major projects  

---

## 📌 Future Enhancements

- Manual pump control via Blynk  
- Adjustable pump duration from mobile app  
- Smoke & temperature sensors  
- Multiple fire detection zones  
- Cloud data logging  
