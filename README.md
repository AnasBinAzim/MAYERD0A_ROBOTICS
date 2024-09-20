# Mayerdoa Robotics Future Engineers Documentation 2024: SMOKI Project Overview
---

<div align="center">
  <img src="https://github.com/user-attachments/assets/08601b9d-fa28-4cfd-aa6c-960e2666ef5a" alt="SMOKI robot" width="300" />
</div>

### This repository is a collection of engineering materials related to **SMOKI**, a self-driving vehicle model developed by **Team MAYERDOA_ROBOTICS**, participating in the **2024 WRO National Final (Future Engineers)** from **Bangladesh**.

---

## Team Members
- **Anas Bin Azim** – [anas.azim.71@gmail.com](mailto:anas.azim.71@gmail.com)
- **Rakibul Islam** – [rakibul.rir06@gmail.com](mailto:rakibul.rir06@gmail.com)
- **Mohiuddin Sami** – [sm.mohiuddin.sami@gmail.com](mailto:sm.mohiuddin.sami@gmail.com)

---

## Repository Overview

* `models` – 3D printable files used in our robot.
* `getting started` – Guide to getting started with our project.
* `src` – Contains the main code for the robot.
* `video` – Links to a YouTube video showcasing our robot in action.
* `t-photos` – Contains one serious and one funny team photo.
* `v-photos` – Contains photos of the robot from all required angles.
* `others` – Additional essential photos.

---

## Mechanical Design

### Mechanical Parts List
* M3 Nut 3mm – 10 pcs
* M3 15mm Screw – 12 pcs
* M2 Nut – 10 pcs
* 35.5mm Red Female-to-Female Round Spacer – 4 pcs
* 30mm Male-to-Female Hex Spacer – 4 pcs
* 15mm Male-to-Female Hex Spacer – 3 pcs
* Bearings

---

## Robot's Chassis

The **SMOKI** chassis is designed for both functionality and aesthetic appeal, featuring an **Ackermann steering system**, **bevel gear**, **3D printed body**, and **sonar mounts with adjustable angle**.

### Ackermann Steering System

<div align="center">
  <img src="https://github.com/user-attachments/assets/5f9959c6-4502-4eab-a4da-55fe32c69f43" alt="Ackermann Steering System" width="400" />
</div>

The **Ackermann steering system** allows for precise turns, reducing tire scrubbing and enhancing the robot's maneuverability by ensuring that the wheels follow the correct turning radius. This is particularly useful for making tight corners and improving handling.


### Bevel Gear

<div align="center">
  <img src="https://github.com/user-attachments/assets/43fb031e-52ba-4e7a-ab7d-bf6c4b74763a" alt="Bevel Gear Photo" width="400" />
</div>

The **bevel gear** system is designed to manage torque and speed efficiently, providing precise control over movement. Its compact and durable structure is ideal for robotics, allowing for agile and responsive behavior during operations.

### 3D Printed Body

The **3D printed body** of the SMOKI robot offers a sleek, customizable design while optimizing weight distribution and structural integrity. Advanced 3D printing techniques were used to create the complex shapes required for the robot's modern look and functionality.

### Sonar Mounts

The **sonar mounts** are strategically positioned to maximize sensor performance, allowing for better obstacle detection. Their placement on the chassis ensures that the sonar sensors are both functional and aesthetically integrated into the overall design.


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

Power efficiency is crucial to ensure smooth operation. We employed voltage conversion techniques to meet the robot's diverse power needs.

### LM4016 Buck Converter for Voltage Step-Down 🔽
![buck converter](https://github.com/user-attachments/assets/4e7c2bde-ba4d-4ce8-a09f-45d2f8686652)



To power the **Raspberry Pi 5** and other components, we used the **LM4016 10A buck converter** to step down battery voltage from **8.4V** to **5V**. This stable 5V supply is crucial for the Raspberry Pi, which demands between **5-6A** at peak performance. The converter efficiently regulates voltage, ensuring minimal energy loss.

### MT3608 Boost Converter for Motor Power 🔼


  <img src="https://github.com/user-attachments/assets/df1ad4a9-8bfe-4b93-9299-7dd5913af512" alt="MT3608 Boost Converter" width="400" />


To power the motors, we used the **MT3608 boost converter** to step up the voltage to **14V**. This ensures that the motors receive adequate current for smooth and responsive operation under varying loads.

### Raspberry Pi and Camera Integration 📷

<div align="center">
  <img src="https://github.com/user-attachments/assets/8f873be0-f273-4863-8847-c895b6039f63" alt="Raspberry Pi and Camera" width="400" />
</div>

Our **Raspberry Pi 5** powers the **SJCAM C200 Action Camera**, which is integral for navigation and obstacle detection. The optimized power delivery system ensures stable operation of the camera and other critical components.

---

## Conclusion 🌟

The SMOKI robot exemplifies a well-thought-out combination of engineering and design principles. Our advanced power delivery system, Ackermann steering, 3D-printed body, and carefully integrated sonar mounts represent a commitment to innovation and precision. These design choices provide a competitive edge as we approach the 2024 WRO National Final.

---

## Debugging Tools and Strategies
*(Details coming soon)*

