# WRO_FE_2024 Engineering Documentation / **Project SMOKI** / Team **MAYERDOA_ROBOTICS** / Bangladesh

<div align="center">
  <img src="https://github.com/user-attachments/assets/172c3a2a-33b5-4c01-a7e5-fbb2edcce263" alt="MAYERDOA Robotics Logo" width="200" />
</div>

### Welcome to the repository for **SMOKI**! Developed by **Team MAYERDOA_ROBOTICS**, this project represents our entry for the **2024 WRO National Final (Future Engineers)**. In this repository, you'll find all engineering materials related to **SMOKI**, our self-driving vehicle model.

---

## Table of Contents
1. [Introduction](#introduction)
2. [Team Members](#team-members)
3. [Project Overview](#project-overview)
4. [Mechanical Design](#mechanical-design)
5. [Electrical Design](#electrical-design)
6. [Programming & Algorithms](#programming--algorithms)
7. [Conclusion](#conclusion)

---

## Introduction

The **LEGO EV3 Expansion Set 45560** is central to our design, allowing for the flexibility, durability, and educational alignment required for WRO. This set enables us to develop advanced mechanical structures that meet **WRO regulations** for the **Future Engineers** category, which emphasizes functionality, modularity, and adaptability in robotics design. Our design goals align with the WRO objectives: creating a competitive, high-performing robot that demonstrates precision, problem-solving, and innovation.

---

## Team Members

- **Anas Bin Azim** – [anas.azim.71@gmail.com](mailto:anas.azim.71@gmail.com)
- **Rakibul Islam** – [rakibul.rir06@gmail.com](mailto:rakibul.rir06@gmail.com)
- **Mohiuddin Sami** – [sm.mohiuddin.sami@gmail.com](mailto:sm.mohiuddin.sami@gmail.com)

---

## Project Overview

This repository contains all files, designs, and code used to create **SMOKI**. Below is a breakdown of the folder structure:

* `models` – STL files for 3D-printed components.
* `getting_started` – Initial setup guide.
* `src` – Main code files for the robot.
* `video` – Link to a YouTube demonstration of SMOKI in action.
* `t-photos` – Contains one serious and one funny team photo.
* `v-photos` – Photos of the robot from all angles.
* `others` – Additional essential photos.

---

## Mechanical Design

### Mechanical Parts List
* **LEGO Technic Elements** (from the EV3 Expansion Set 45560)
* M3 Nut 3mm – 10 pcs
* M3 15mm Screw – 12 pcs
* M2 Nut – 10 pcs
* 35.5mm Red Female-to-Female Round Spacer – 4 pcs
* 30mm Male-to-Female Hex Spacer – 4 pcs
* 15mm Male-to-Female Hex Spacer – 3 pcs
* Bearings

---

## Robot's Chassis

The **SMOKI** chassis, designed with a mix of LEGO Technic parts and 3D-printed components, provides a sturdy base that supports all critical systems, including **Ackermann steering**, a **bevel gear system**, and integrated sonar mounts.

### Ackermann Steering System

<div align="center">
  <img src="https://github.com/user-attachments/assets/5f9959c6-4502-4eab-a4da-55fe32c69f43" alt="Ackermann Steering System" width="400" />
</div>

Our **Ackermann steering system** allows for precise turning, essential for navigating tight corners on the WRO course. This system reduces tire scrubbing and improves overall maneuverability by ensuring the wheels follow the correct turning radius.

### Bevel Gear

![GEARMAINMAIN](https://github.com/user-attachments/assets/8e56c556-2eb2-46a9-8785-7f3f2b5e6b47)

The **bevel gear** system is designed to manage torque and speed efficiently, providing precise control for agile and responsive movements.

### 3D Printed Body

The **3D printed body** of SMOKI offers a sleek, customizable design while optimizing weight distribution and structural integrity.

### Sonar Mounts

Strategically placed **sonar mounts** maximize sensor performance, allowing for effective obstacle detection.

---

## Electrical Design

### Electronics Parts List
* 25GA 800 RPM Motor
* Raspberry Pi 5 (8GB)
* SJCAM C200 Action Camera
* Arduino Nano
* Copper Plate
* MG90S Servo – 1 pcs
* Li-Ion Battery – 2 pcs
* Ultrasonic Sensor – 4 pcs
* 10A Buck Module
* MT3608 Booster Module
* L298N Motor Driver
* Push Button
* Buzzer

---

## Power Delivery and Optimization ⚡🔋

Efficient power delivery ensures that SMOKI operates smoothly during intense tasks.

### LM4016 Buck Converter for Voltage Step-Down 🔽

![buck converter](https://github.com/user-attachments/assets/4e7c2bde-ba4d-4ce8-a09f-45d2f8686652)

We used the **LM4016 10A buck converter** to step down voltage from **8.4V** to **5V** for the **Raspberry Pi 5**, which demands between **5-6A** at peak performance.

### MT3608 Boost Converter for Motor Power 🔼

<img src="https://github.com/user-attachments/assets/df1ad4a9-8bfe-4b93-9299-7dd5913af512" alt="MT3608 Boost Converter" width="400" />

The **MT3608 boost converter** steps up voltage to **14V** for the motors, ensuring sufficient power for responsive movement.

### Raspberry Pi and Camera Integration 📷

<div align="center">
  <img src="https://github.com/user-attachments/assets/8f873be0-f273-4863-8847-c895b6039f63" alt="Raspberry Pi and Camera" width="400" />
</div>

Our **Raspberry Pi 5** powers the **SJCAM C200 Action Camera**, which is integral for navigation and obstacle detection.

---

## Programming & Algorithms

### Avoiding Obstacles
* Utilizing sonar sensors and the camera feed to detect and avoid obstacles on the course.

### Lap Counting
* Uses camera processing to track and count laps in compliance with WRO rules.

### Autonomous Steering
* Custom algorithms allow for smooth autonomous steering based on Ackermann geometry principles.

---

## Conclusion 🌟

The SMOKI robot represents a careful balance of engineering and design principles. Our use of the LEGO EV3 Expansion Set 45560 alongside customized mechanical and electrical systems positions SMOKI as a strong contender for the 2024 WRO National Final.

---

