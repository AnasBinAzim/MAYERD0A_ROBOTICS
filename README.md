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

<div align="center">
  <img src=![ROUND1 WRO](https://github.com/user-attachments/assets/823b29fa-8c92-479e-a78a-9fc96c407858)
 />
</div>

### 🏆 Round 2: Lap Completion with Obstacle Avoidance and Parking

In **Round 2**, the bot must complete **three laps** while avoiding green and red obstacles:
  - **Green Obstacles**: The bot should move **left** to avoid.
  - **Red Obstacles**: The bot should move **right** to avoid.
  
After completing the laps, the bot must accurately park within a designated zone.

- **Objective**: Complete three laps, avoid obstacles, and park in the designated area.
- **Tasks**: Obstacle detection, color-based avoidance, and precision parking.

<div align="center">
  <img src=![WRO TRACK](https://github.com/user-attachments/assets/b578392d-b443-4315-8fe3-f03af828c39a)
 />
</div>

---

## 🧩 Components and Hardware

Our bot is equipped with various components that support its autonomous functionality. Here is a breakdown of the key hardware elements used in this project:

| Component                | Description                                                                                      | Image                                                                                                                                             | Purchase Link                                                                                 |
|--------------------------|--------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
| **Raspberry Pi 5**       | Provides processing power for control algorithms and sensor data management.                     | ![Raspberry Pi 5](https://github.com/user-attachments/assets/a16b195a-2446-4413-97ef-c06426b3b4ef)                                              | [Purchase Raspberry Pi 5](https://amzn.to/3wKg5TG)                                            |
| **ESP32 Microcontroller**| Handles real-time sensor data interpretation and motor control.                                  | ![ESP32](https://github.com/user-attachments/assets/43c1e57a-8e3b-459e-9aeb-4ce3d8e4dd68)                                                        | [Purchase ESP32](https://amzn.to/3ESP32)                                                      |
| **LEGO EV3 Expansion Set (45560)** | Modular components used for building and structural support.                       | ![LEGO EV3 Set](https://github.com/user-attachments/assets/53ab529f-2e16-41dc-8b47-2b9b9a454a1b)                                                  | [Purchase LEGO 45560](https://amzn.to/3K4eLEGO)                                               |
| **XL4016 Buck Converter** | Provides stable voltage for the Raspberry Pi and ESP32, enhancing power management.             | ![XL4016 Buck Converter](https://github.com/user-attachments/assets/398f762d-c885-4e7c-b636-90ecdf7b67f4)                                       | [Purchase XL4016](https://amzn.to/4xl4016)                                                    |
| **Custom PCB**           | Custom-designed PCB for efficient wiring and stable connections across all components.          | ![Custom PCB](https://via.placeholder.com/150)                                                                                                   | [Custom Design](https://custompcbprovider.com)                                                |
| **Ultrasonic Sensors**    | Detects distances to obstacles and aids in precise navigation.                                   | ![Ultrasonic Sensor](https://via.placeholder.com/150)                                                                                            | [Purchase Ultrasonic Sensor](https://amzn.to/3Ultrasonic)                                     |
| **Infrared Sensors**     | Used for line-following and environmental data collection.                                       | ![Infrared Sensor](https://via.placeholder.com/150)                                                                                              | [Purchase IR Sensor](https://amzn.to/3Infrared)                                               |
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

![Chassis Assembly](./images/01_chassis_structure.jpg)

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
