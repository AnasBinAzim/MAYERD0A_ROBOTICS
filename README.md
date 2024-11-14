# 🤖 **MAYERDOA Robotics - WRO 2024 Project** 🤖

<div align="center">
  <img src="https://github.com/user-attachments/assets/172c3a2a-33b5-4c01-a7e5-fbb2edcce263" alt="Mayerdoa Robotics Logo" width="200" />
</div>

---

## 👥 **Team MAYERDOA - "Mothers' Prayers"**

- **Anas Bin Azim** – Software & Hardware Developer | [anas.azim.71@gmail.com](mailto:anas.azim.71@gmail.com)
- **Rakibul Islam** – Software & Hardware Developer | [rakibul.rir06@gmail.com](mailto:rakibul.rir06@gmail.com)
- **Mohiuddin Sami** – Software Developer | [sm.mohiuddin.sami@gmail.com](mailto:sm.mohiuddin.sami@gmail.com)

**Team Origin**: Bangladesh

---

### 🌟 **The Meaning Behind MAYERDOA**

Our team name, **"MAYERDOA,"** translates to **"Mother's Prayers"** in Bengali, a tribute to the unwavering support of our mothers. They have been our guiding light, steadfastly cheering us on from the initial selection to the WRO global stage. Through every challenge, they are our invisible strength—their love and prayers fueling each achievement, each step forward, each line of code. Their blessings are woven into the fabric of this project, making it more than just a technical endeavor; it’s a heartfelt journey.

---


## 🎉 **Project Overview**

Our bot, **SMOKI**, is built for excellence in the **World Robot Olympiad 2024** in the Future Engineers category. From its structural core using LEGO Technic elements to its computing capabilities powered by the **Raspberry Pi 5** and **ESP32 microcontroller**, SMOKI is crafted to handle the nuanced challenges of autonomous navigation and obstacle handling.

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

| Component                      | Description                                                                                      | Image                                                                                                        | Purchase Link                                                                                    |
|--------------------------------|--------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| **Raspberry Pi 5**             | Provides processing power for control algorithms and sensor data management.                     | ![Raspberry Pi 5](https://github.com/user-attachments/assets/b6b79ab7-a635-4ff0-9f66-b53b7e97dcd7)           | [Purchase Raspberry Pi 5](https://amzn.to/3wKg5TG)                                               |
| **ESP32 Microcontroller**      | Handles real-time sensor data interpretation and motor control.                                  | ![ESP32](https://github.com/user-attachments/assets/0fe5f54b-8df2-492c-a68c-8e100bae381d)                    | [Purchase ESP32](https://amzn.to/3ESP32)                                                         |
| **LEGO EV3 Expansion Set (45560)** | Modular components used for building and structural support.                             | ![LEGO EV3 Set](https://github.com/user-attachments/assets/c99f6a51-5c82-4981-bed8-0cb59690b966)             | [Purchase LEGO 45560](https://amzn.to/3K4eLEGO)                                                  |
| **XL4016 Buck Converter**      | Provides stable voltage for the Raspberry Pi and ESP32, enhancing power management.              | ![XL4016 Buck Converter](https://github.com/user-attachments/assets/b7184ca5-34c3-48db-86e7-a5e919362516)    | [Purchase XL4016](https://amzn.to/4xl4016)                                                       |
| **Custom PCB**                 | Custom-designed PCB for efficient wiring and stable connections across all components.           | ![Custom PCB](https://via.placeholder.com/150)                                                               | [Custom Design](https://custompcbprovider.com)                                                   |
| **Ultrasonic Sensors**         | Detects distances to obstacles and aids in precise navigation.                                   | ![Ultrasonic Sensor](https://github.com/user-attachments/assets/dc6408c5-e4c1-4a63-b9cf-35efa5a8483a)        | [Purchase Ultrasonic Sensor](https://amzn.to/3Ultrasonic)                                        |
| **Camera - SJ CAM C200**       | Captures visual data, supporting navigation and obstacle detection tasks.                        | ![SJ CAM C200](https://github.com/user-attachments/assets/8bb8ceb2-e95b-45cd-9e9d-ec480b62baaa)              | [Purchase SJ CAM C200](https://amzn.to/3SJCAM)                                                   |
| **3D Printed Mounts**          | Custom-made mounts for stable sensor and component positioning.                                  | ![3D Printed Mount](https://via.placeholder.com/150)                                                         | N/A                                                                                              |

---





## 🚀 Key Features

- **Modular LEGO Design**: Easily reconfigurable using LEGO Technic parts, allowing for quick adjustments.
- **Advanced Processing with Raspberry Pi 5**: Enables complex algorithms and sensor data handling.
- **Efficient Power Management**: The XL4016 buck converter and custom PCB provide stable voltage.
- **Comprehensive Sensor Suite**: Includes ultrasonic and infrared sensors for precision navigation.
- **3D Printed Mounts**: Ensures stable and adaptable sensor and component placement.

---

## 🔧 Assembly Instructions

### 🏗️ Chassis Assembly

The following images showcase the detailed assembly process of our WRO Bot's chassis, utilizing the LEGO 45560 expansion set.

<p align="center">
  <img src="https://github.com/user-attachments/assets/f35d0fc2-224d-45f7-a863-30e9098c40af" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/1b8da3c9-1893-435a-a694-a94949254aeb" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/305f3ca1-0cee-404a-8215-7aa532ce29b4" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/41d0e57a-37c3-4f4c-ac51-11565c5eae3e" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/603f8648-d725-40b9-9c70-7f7e070e68ce" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/98ead8a8-19e7-466c-9a73-a7ec516daf5e" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/41d0e57a-37c3-4f4c-ac51-11565c5eae3e" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/7aa07579-eaef-4024-b4e7-54cf38eaba18" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/6a235cf7-fba6-4403-862e-a4929a48b6a9" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/e717916d-93f4-4844-b1ac-7bc6b1c991f5" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/64b7140a-9e3e-4bfb-b659-bb22befd86a8" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/e717916d-93f4-4844-b1ac-7bc6b1c991f5" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/38c7edd0-b888-41a8-91f2-c0fb84ade69e" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/ec1019fc-c8fe-4b5d-86d1-c554ce76b774" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/ec1019fc-c8fe-4b5d-86d1-c554ce76b774" width="120" height="120" />
  <img src="https://github.com/user-attachments/assets/ec1019fc-c8fe-4b5d-86d1-c554ce76b774" width="120" height="120" />
  
</p>


*Each image provides a unique angle or assembly step, helping illustrate the complexity and modularity of the design.*

*Each image provides a unique angle or assembly step, helping illustrate the complexity and modularity of the design.*


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
