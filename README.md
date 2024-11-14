# 🤖 WRO Future Engineers 2024: SMOKI Bot Project by MAYERDOA_ROBOTICS

<div align="center">
  <img src="https://github.com/user-attachments/assets/172c3a2a-33b5-4c01-a7e5-fbb2edcce263" alt="Mayerdoa Robotics Logo" width="200" />
</div>

---

## 🌍 World Robot Olympiad (WRO) Bot Project

Welcome to the **SMOKI Bot Project** repository for the **WRO Future Engineers 2024** category! Our team, **MAYERDOA_ROBOTICS** from Bangladesh, has built a fully autonomous robot capable of navigating a track, avoiding obstacles, and completing missions in alignment with WRO Future Engineers objectives.

---

## 🎉 Team and Project Introduction

**MAYERDOA_ROBOTICS** is a robotics team competing in the **WRO 2024 Future Engineers** category with an autonomous bot designed for high adaptability and intelligent navigation. Our bot, **SMOKI**, combines LEGO Technic modularity, advanced processing from the **Raspberry Pi 5**, and an ESP32 microcontroller for real-time sensor control.

### Team Members

1. **Anas Bin Azim** (Software & Hardware Developer) – [anas.azim.71@gmail.com](mailto:anas.azim.71@gmail.com)
2. **Rakibul Islam** (Software & Hardware Developer) – [rakibul.rir06@gmail.com](mailto:rakibul.rir06@gmail.com)
3. **Mohiuddin Sami** (Software Developer) – [sm.mohiuddin.sami@gmail.com](mailto:sm.mohiuddin.sami@gmail.com)

**Country**: Bangladesh  
**Event**: World Robot Olympiad 2024

---

## 🎯 Project Objective

The primary objective of this project is to develop an autonomous robot capable of navigating a track, avoiding obstacles, and parking precisely, as outlined in the WRO Future Engineers 2024 guidelines.

### Mission Details

Our robot will participate in two rounds, each with unique goals related to autonomous navigation, obstacle avoidance, and parking accuracy.

### 🏁 Round 1: Lap Completion

In **Round 1**, the bot must autonomously complete **three laps** around the track without needing to avoid obstacles.

- **Objective**: Complete three laps within the time limit.
- **Tasks**: Path-following and speed control.

# 🤖 Welcome to the WRO Bot Project Repository!


---

## 🎯 Project Objective

This project is designed to meet the challenges and missions set forth in the **WRO 2024 Future Engineers** category. Our robot will participate in two rounds, each with specific goals related to autonomous navigation, obstacle avoidance, and parking accuracy.

### Mission Overview for WRO Future Engineers Rounds

### 🏁 Round 1: Lap Completion

In **Round 1**, the robot must autonomously complete **three laps** on a pre-defined track. The goal of this round is for the bot to demonstrate stable navigation and precise lap tracking without any obstacle avoidance requirements.

- **Objective**: Complete three laps on the track within the allotted time.
- **Key Tasks**: Accurate path-following, speed control, and lap counting.

<div align="center">
  <img src="https://github.com/user-attachments/assets/823b29fa-8c92-479e-a78a-9fc96c407858" alt="Round 1 WRO Track" width="500" />
</div>

---

### 🏆 Round 2: Lap Completion with Obstacle Avoidance and Parking

In **Round 2**, the bot must complete **three laps** while avoiding green and red obstacles:
  - **Green Obstacles**: The bot should move **left** to avoid.
  - **Red Obstacles**: The bot should move **right** to avoid.
  
After completing the laps, the bot must accurately park within a designated zone.

- **Objective**: Complete three laps, avoid obstacles, and park in the designated area.
- **Tasks**: Obstacle detection, color-based avoidance, and precision parking.

<div align="center">
  <img src="https://github.com/user-attachments/assets/b578392d-b443-4315-8fe3-f03af828c39a" alt="Round 2 WRO Track" width="500" />
</div>


---

## 🧩 Components and Hardware

Our bot is equipped with various components that support its autonomous functionality. Here is a breakdown of the key hardware elements used in this project:

| Component                | Description                                                                                      | Image                                                                                                                                             | Purchase Link                                                                                 |
|--------------------------|--------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
| **Raspberry Pi 5**       | Provides processing power for control algorithms and sensor data management.                     | ![Raspberry Pi 5](https://github.com/user-attachments/assets/b6b79ab7-a635-4ff0-9f66-b53b7e97dcd7)
)                           | [Purchase Raspberry Pi 5](https://amzn.to/3wKg5TG)                                            |
| **ESP32 Microcontroller**| Handles real-time sensor data interpretation and motor control.                                  | ![ESP32](https://github.com/user-attachments/assets/33a06ed7-70a8-4dc2-8be9-c8d0050e6f9a)                                                        | [Purchase ESP32](https://amzn.to/3ESP32)                                                      |
| **LEGO EV3 Expansion Set (45560)** | Modular components used for building and structural support.                       | ![LEGO EV3 Set](![lego expansion-Photoroom](https://github.com/user-attachments/assets/c99f6a51-5c82-4981-bed8-0cb59690b966)
)                          | [Purchase LEGO 45560](https://amzn.to/3K4eLEGO)                                               |
| **XL4016 Buck Converter** | Provides stable voltage for the Raspberry Pi and ESP32, enhancing power management.             | ![XL4016 Buck Converter](https://github.com/user-attachments/assets/12e22ca7-35a7-4113-8842-1284a45e5a7e)                                        | [Purchase XL4016](https://amzn.to/4xl4016)                                                    |
| **Custom PCB**           | Custom-designed PCB for efficient wiring and stable connections across all components.          | ![Custom PCB](https://via.placeholder.com/150)                                                                                                    | [Custom Design](https://custompcbprovider.com)                                                |
| **Ultrasonic Sensors**    | Detects distances to obstacles and aids in precise navigation.                                   | ![Ultrasonic Sensor](https://github.com/user-attachments/assets/25014896-2204-4e75-ab74-484e8e3103a0)                                            | [Purchase Ultrasonic Sensor](https://amzn.to/3Ultrasonic)                                     |
| **Camera - SJ CAM C200** | Captures visual data, supporting navigation and obstacle detection tasks.                        | ![SJ CAM C200](https://github.com/user-attachments/assets/5e6f4d5e-d3e1-4cfa-9f8c-1bb3a0e76e0a)                                                  | [Purchase SJ CAM C200](https://amzn.to/3SJCAM)                                                |
| **3D Printed Mounts**     | Custom-made mounts for stable sensor and component positioning.                                | ![3D Printed Mount](https://via.placeholder.com/150)                                                                                             | N/A                                                                                            |

---




## 🚀 Key Features

- **Modular LEGO Design**: Easily reconfigurable using LEGO Technic parts, allowing for quick adjustments.
- **Advanced Processing with Raspberry Pi 5**: Enables complex algorithms and sensor data handling.
- **Efficient Power Management**: The XL4016 buck converter and custom PCB provide stable voltage.
- **Comprehensive Sensor Suite**: Includes ultrasonic and infrared sensors for precision navigation.
- **3D Printed Mounts**: Ensures stable and adaptable sensor and component placement.

---

## 🔧 Assembly Instructions

### 🏗️ Chassis Structure

Built using LEGO Technic parts from the 45560 set, providing a strong base.

![Chassis Assembly]()

### 🚗 Drive System

The drive system includes DC motors, which provide reliable propulsion and control.

![Drive System](./images/02_drive_system.jpg)

### ⚡ Electronics and Power System

- **Power Module**: Ensures consistent power to the Raspberry Pi and ESP32.
- **Wiring**: Organized to minimize interference.

![Electronics Setup](./images/03_electronics.jpg)

### 🔍 Sensors

Sensors are arranged strategically for obstacle detection and navigation.

![Sensors Array](./images/04_sensors.jpg)

### 📸 Mounting the Raspberry Pi and Camera

The Raspberry Pi is mounted with custom 3D-printed parts for stability.

![Raspberry Pi and Camera Mount](./images/05_raspberry_camera.jpg)

---

## 💻 Software Setup

1. **Install Dependencies**:
   ```bash
   sudo apt update
   sudo apt install python3 python3-pip
   pip3 install -r requirements.txt
