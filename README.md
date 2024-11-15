# 🤖 **MAYERDOA Robotics - WRO 2024 Project** 🤖

<div align="center">
  <img src="https://github.com/user-attachments/assets/15e9b36d-2bf1-4de5-bdc4-36a72aa1e23a" alt="MAYERDOA Robotics Banner"/>
</div>

---

## 👥 **Team MAYERDOA - "Mothers' Prayers"**

- **Anas Bin Azim**  – Software & Hardware Developer | [anas.azim.71@gmail.com](mailto:anas.azim.71@gmail.com)
- **Rakibul Islam**  – Team Leader, Software & Hardware Developer | [rakibul.rir06@gmail.com](mailto:rakibul.rir06@gmail.com)
- **Mohiuddin Sami** – Primary Software Developer | [sm.mohiuddin.sami@gmail.com](mailto:sm.mohiuddin.sami@gmail.com)

**Team Origin**: Bangladesh

---

### 🌟 **The Meaning Behind MAYERDOA**

Our team name, **"MAYERDOA,"** translates to **"Mother's Prayers"** in Bengali, a tribute to the unwavering support of our mothers. They have been our guiding light, steadfastly cheering us on from the initial selection to the WRO global stage. Through every challenge, they are our invisible strength—their love and prayers fueling each achievement, each step forward, each line of code. Their blessings are woven into the fabric of this project, making it more than just a technical endeavor; it’s a heartfelt journey.

---


## 🎉 **Project Overview**

## GITHUB GUIDE

This repository contains all files, designs, and code used to create **SMOKI**. Below is a breakdown of the folder structure:

* `models` – STL files for 3D-printed components.
* `getting_started` – Initial setup guide.
* `src` – Main code files for the robot.
* `video` – Link to a YouTube demonstration of SMOKI in action.
* `t-photos` – Contains one serious and one funny team photo.
* `v-photos` – Photos of the robot from all angles.
* `others` – Additional essential photos.

---

## Table of Contents

- [Team MAYERDOA - "Mothers' Prayers"](#-team-mayerdoa---mothers-prayers)
- [Project Overview](#-project-overview)
- [Project Objective](#-project-objective)
- [Mission Overview for WRO Future Engineers Rounds](#mission-overview-for-wro-future-engineers-rounds)
- [Components and Hardware](#-components-and-hardware)
- [Mobility Management](#-mobility-management)
- [Power and Sense Management](#-power-and-sense-management)
- [Program Infrastructure and Explanation of Algorithm](#-program-infrastructure-and-explanation-of-algorithm)
- [Software Setup](#-software-setup)

---




Our bot, **SMOKI**, is built for excellence in the **World Robot Olympiad 2024** in the Future Engineers category. From its structural core using LEGO Technic elements to its computing capabilities powered by the **Raspberry Pi 5** and **ESP32 microcontroller**, SMOKI is crafted to handle the nuanced challenges of autonomous navigation and obstacle handling.

---

### Mission Overview for WRO Future Engineers Rounds

<table>
  <tr>
    <td width="50%" valign="top" align="left">
      <h3>🏁 Round 1: Lap Completion</h3>
      <p>In <strong>Round 1</strong>, the robot must autonomously complete <strong>three laps</strong> on a pre-defined track. The goal of this round is for the bot to demonstrate stable navigation and precise lap tracking without any obstacle avoidance requirements.</p>
      <ul>
        <li><strong>Objective</strong>: Complete three laps on the track within the allotted time.</li>
        <li><strong>Key Tasks</strong>: Accurate path-following, speed control, and lap counting.</li>
      </ul>
      <!-- Adding more spacing to align the images -->
      <div align="center">
        <br><br><br><br><br>
        <img src="https://github.com/user-attachments/assets/823b29fa-8c92-479e-a78a-9fc96c407858" alt="Round 1 WRO Track" width="250" height="180" />
      </div>
    </td>
    <td width="50%" valign="top" align="left">
      <h3>🏆 Round 2: Lap Completion with Obstacle Avoidance and Parking</h3>
      <p>In <strong>Round 2</strong>, the bot must complete <strong>three laps</strong> while avoiding green and red obstacles:</p>
      <ul>
        <li><strong>Green Obstacles</strong>: The bot should move <strong>left</strong> to avoid.</li>
        <li><strong>Red Obstacles</strong>: The bot should move <strong>right</strong> to avoid.</li>
      </ul>
      <p>After completing the laps, the bot must accurately park within a designated zone.</p>
      <ul>
        <li><strong>Objective</strong>: Complete three laps, avoid obstacles, and park in the designated area.</li>
        <li><strong>Tasks</strong>: Obstacle detection, color-based avoidance, and precision parking.</li>
      </ul>
      <div align="center">
        <img src="https://github.com/user-attachments/assets/b578392d-b443-4315-8fe3-f03af828c39a" alt="Round 2 WRO Track" width="250" height="180" />
      </div>
    </td>
  </tr>
</table>


---



## 🧩 Components and Hardware

Our bot is equipped with various components that support its autonomous functionality. Here is a breakdown of the key hardware elements used in this project:

| Component                      | Description                                                                                      | Image                                                                                                        | Purchase Link                                                                                    |
|--------------------------------|--------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| **Raspberry Pi 5**             | Provides processing power for control algorithms and sensor data management.                     | <div align="center"><img src="https://github.com/user-attachments/assets/b6b79ab7-a635-4ff0-9f66-b53b7e97dcd7" alt="Raspberry Pi 5" width="100"></div> | [Purchase Raspberry Pi 5](https://amzn.to/3wKg5TG)                                               |
| **ESP32 Microcontroller**      | Handles real-time sensor data interpretation and motor control.                                  | <div align="center"><img src="https://github.com/user-attachments/assets/0fe5f54b-8df2-492c-a68c-8e100bae381d" alt="ESP32" width="100"></div>        | [Purchase ESP32](https://amzn.to/3ESP32)                                                         |
| **LEGO EV3 Expansion Set (45560)** | Modular components used for building and structural support.                             | <div align="center"><img src="https://github.com/user-attachments/assets/c99f6a51-5c82-4981-bed8-0cb59690b966" alt="LEGO EV3 Set" width="100"></div>  | [Purchase LEGO 45560](https://amzn.to/3K4eLEGO)                                                  |
| **XL4016 Buck Converter**      | Provides stable voltage for the Raspberry Pi and ESP32, enhancing power management.              | <div align="center"><img src="https://github.com/user-attachments/assets/b7184ca5-34c3-48db-86e7-a5e919362516" alt="XL4016 Buck Converter" width="100"></div> | [Purchase XL4016](https://amzn.to/4xl4016)                                                       |
| **Custom PCB**                 | Custom-designed PCB for efficient wiring and stable connections across all components.           | <div align="center"><img src="https://via.placeholder.com/150" alt="Custom PCB" width="100"></div>           | [Custom Design](https://custompcbprovider.com)                                                   |
| **Ultrasonic Sensors**         | Detects distances to obstacles and aids in precise navigation.                                   | <div align="center"><img src="https://github.com/user-attachments/assets/dc6408c5-e4c1-4a63-b9cf-35efa5a8483a" alt="Ultrasonic Sensor" width="100"></div> | [Purchase Ultrasonic Sensor](https://amzn.to/3Ultrasonic)                                        |
| **Camera - SJ CAM C200**       | Captures visual data, supporting navigation and obstacle detection tasks.                        | <div align="center"><img src="https://github.com/user-attachments/assets/8bb8ceb2-e95b-45cd-9e9d-ec480b62baaa" alt="SJ CAM C200" width="100"></div>  | [Purchase SJ CAM C200](https://amzn.to/3SJCAM)                                                   |
| **3D Printed Mounts**          | Custom-made mounts for stable sensor and component positioning.                                  | <div align="center"><img src="https://via.placeholder.com/150" alt="3D Printed Mount" width="100"></div>     | N/A                                                                                              |

---









## 🚀 Key Features

- **Modular LEGO Design**: Easily reconfigurable using LEGO Technic parts, allowing for quick adjustments.
- **Advanced Processing with Raspberry Pi 5**: Enables complex algorithms and sensor data handling.
- **Efficient Power Management**: The XL4016 buck converter and custom PCB provide stable voltage.
- **Comprehensive Sensor Suite**: Includes ultrasonic and infrared sensors for precision navigation.
- **3D Printed Mounts**: Ensures stable and adaptable sensor and component placement.

---



## 🔧 Assembly Instructions

### 🏗️ Chassis Assembly - LEGO 45560 Expansion Set

Our robot’s chassis is built using components from the **LEGO Technic Expansion Set 45560**. This set provides modular, robust, and flexible building parts that are ideal for constructing a stable and durable chassis foundation. The combination of LEGO’s high-quality materials and custom components ensures that our robot is adaptable, allowing for quick adjustments and additions.

#### 📘 LEGO 45560 Expansion Set Manual
For a step-by-step guide on using the LEGO 45560 parts, refer to the official **LEGO 45560 Expansion Set Manual**:
- **[LEGO 45560 Expansion Set Manual (PDF Download)](https://www.lego.com/cdn/manuals/45560.pdf)**

---

#### 🧩 Parts List - LEGO 45560 Expansion Set

The LEGO 45560 Expansion Set contains a variety of parts that are essential for building complex mechanisms. Below is a detailed list of all parts included in the set:

| Part Number | Part Name                     | Quantity |
|-------------|--------------------------------|----------|
| 45502       | LEGO Technic Beam 3x5          | 2        |
| 45503       | LEGO Technic Beam 3x7          | 4        |
| 45504       | LEGO Technic Beam 5x11         | 2        |
| 45505       | LEGO Technic Beam 5x7          | 4        |
| 45507       | LEGO Technic Beam 1x9          | 6        |
| 45508       | LEGO Technic Beam 1x15         | 4        |
| 45509       | LEGO Technic Angular Beam 4x6  | 6        |
| 45510       | LEGO Technic Angular Beam 3x5  | 4        |
| 3703        | LEGO Technic Beam 1x16         | 2        |
| 32000       | LEGO Technic Brick 1x14        | 4        |
| 32002       | LEGO Technic Cross Block 3x3   | 4        |
| 92907       | LEGO Technic Axle 7            | 8        |
| 32009       | LEGO Technic Axle 9            | 4        |
| 24316       | LEGO Technic Gear 24 Tooth     | 4        |
| 42003       | LEGO Technic Gear 16 Tooth     | 6        |
| 6538b       | LEGO Technic Connector Peg w/ Friction | 50 |
| 3647        | LEGO Technic Gear 8 Tooth      | 6        |
| 87083       | LEGO Technic Pin 2L            | 60       |
| 32269       | LEGO Technic Connector Peg     | 20       |
| 40490       | LEGO Technic Axle Pin          | 40       |
| 32556       | LEGO Technic Double Cross Block | 6      |
| 32184       | LEGO Technic Connector with Bush | 8      |
| 3749        | LEGO Technic Bush              | 40       |
| 3713        | LEGO Technic Half Bush         | 30       |
| 42195       | LEGO Technic Pin w/ Stop       | 12       |
| 18654       | LEGO Technic Angular Beam 4x4  | 6        |
| 11478       | LEGO Technic Frame 5x7         | 2        |

> **Note**: Quantities are approximate based on the LEGO 45560 set contents. For exact counts, refer to the [manual](https://www.lego.com/cdn/manuals/45560.pdf).

---

#### 🛠️ Chassis Assembly Process

Here’s a step-by-step overview of the chassis assembly process using the LEGO 45560 Expansion Set:

1. **Base Frame Construction**: Start by assembling the base frame using 5x11 and 5x7 beams for structural stability. These beams provide a strong foundation for mounting additional components.
2. **Motor and Axle Integration**: Utilize the LEGO Technic beams and axle connectors to securely attach the motors. Ensure proper alignment to enable smooth and controlled movement.
3. **Reinforcing with Angular Beams**: Use the 4x6 and 3x5 angular beams to reinforce corners and support areas where weight and stress are concentrated.
4. **Mounting Sensors and Electronics**: Attach sensor mounts and electronic components using cross blocks and bushings, making sure they are aligned for efficient data capture and processing.
5. **Gear Assembly for Differential Drive**: Assemble gears (8, 16, and 24-tooth gears) to create a differential drive system, allowing independent rotation of wheels for smooth turns.

---

#### 🔍 Benefits of Using LEGO Technic Parts

- **Modularity**: The LEGO Technic beams and connectors allow for quick modifications, so adjustments can be made without disrupting the entire structure.
- **Durability**: High-quality materials ensure the chassis remains stable even during rigorous testing.
- **Precision**: Technic gears, axles, and connectors provide precise alignment, which is critical for movement control and sensor accuracy.

---

By leveraging the flexibility and durability of the LEGO 45560 Expansion Set, our chassis design achieves a balance between robustness and adaptability. The manual and parts list serve as valuable resources for replicating or modifying the design as needed.


---


The following images showcase the detailed assembly process of our WRO Bot's chassis, utilizing the LEGO 45560 expansion set.

<p align="center">
  <img src="https://github.com/user-attachments/assets/0994a988-1f73-43db-b7f9-34c5243a842a" width="300" height="225" />
  <img src="https://github.com/user-attachments/assets/39b389db-0038-425f-bcd5-740f748e3cc9" width="300" height="225" />
  <img src="https://github.com/user-attachments/assets/339eaf97-91a8-4987-8af9-c86c2d4fe360" width="300" height="225" />
  <img src="https://github.com/user-attachments/assets/30eae1ee-b442-4caf-86c3-7d5bbb12c6c3" width="300" height="225" />
  <img src="https://github.com/user-attachments/assets/e95b4755-0067-4639-bd6b-58631e9da91e" width="300" height="225" />
  <img src="https://github.com/user-attachments/assets/cb176c4d-0af5-4f80-ae3b-d7a9033592d0" width="300" height="225" />
  <img src="https://github.com/user-attachments/assets/14527900-366e-4555-8aac-33a8163e1e19" />
</p>


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


## 🚗 Mobility Management

This section covers the mobility features of our robot, including drive mechanisms, steering, and any additional mobility-specific hardware. By integrating components like differential drives or custom mounts, we ensure the robot can move accurately and reliably across different surfaces.

---

## ⚡ Power and Sense Management

Power management and sensor integration are critical for maintaining consistent operation. This section explains our approach to stabilizing power supply to all components, while managing sensors like ultrasonic and camera modules for optimal performance.

---

## 🧠 Program Infrastructure and Explanation of Algorithm

In this section, we discuss the underlying software infrastructure, including how data flows within the system, how sensors are interpreted, and the logic behind navigation, obstacle avoidance, and lap counting algorithms. Our programming approach ensures efficient processing and response times.

---

## 💻 Software Setup

1. **Install Dependencies**:
   ```bash
   sudo apt update
   sudo apt install python3 python3-pip
   pip3 install -r requirements.txt
