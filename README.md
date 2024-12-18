# 🤖 **MAYERDOA Robotics - WRO 2024 Project** 🤖

<div align="center">
  <img src="https://github.com/user-attachments/assets/b69b15b8-69d2-439a-aac6-5dcfc8eba67c"/>
</div>

---

## 👥 **Team MAYERDOA - "Mothers' Prayers"**

- **Anas Bin Azim**  – Software & Hardware Developer | [anas.azim.71@gmail.com](mailto:anas.azim.71@gmail.com)
- **Rakibul Islam**  – Team Leader, Primary Hardware Developer | [rakibul.rir06@gmail.com](mailto:rakibul.rir06@gmail.com)
- **Mohiuddin Sami** – Primary Software Developer | [sm.mohiuddin.sami@gmail.com](mailto:sm.mohiuddin.sami@gmail.com)

**Team Origin**: Bangladesh

---

### 🌟 **The Meaning Behind MAYERDOA**

Our team name, "MAYERDOA," means "Mother's Prayers" in Bengali, honoring the constant support and encouragement of our mothers. From the early stages of selection to reaching the global WRO stage, they have been our strongest supporters, always standing by us. Their love and prayers have been our strength, helping us overcome challenges, achieve milestones, and stay motivated through every step of the journey. This project is more than just a technical effort—it’s a reflection of their unwavering belief in us.

---


## 🎉 Project Overview
<img align="right" alt="SMOKI" width="350" src="https://github.com/user-attachments/assets/46c38599-e416-42cb-93ba-6f83ff142c18">

This repository includes all files, designs, and code for **SMOKI**, our WRO 2024 robot. Below is the folder structure:

## 📂 Structure

Here’s a breakdown of the project folders:

- **[`Software-Setup`](./Software-Setup/)**: Steps for software and hardware setup.
- **[`experiments`](./experiments/)**: Documentation of trials and iterations with previous models.
- **[`models`](./models/)**: Contains 3D models and CAD designs.
- **[`other`](./other/)**: Additional documents and miscellaneous files.
- **[`schematic`](./schematic/)**: Wiring and circuit design diagrams.
- **[`src`](./src/)**: Source code for robot programming.
- **[`t-photos`](./t-photos/)**: Technical images of the robot build.
- **[`v-photos`](./v-photos/)**: Visual photos for aesthetics and showcasing.
- **[`video`](./video/)**: Performance and demo videos of SMOKI.

---






----

## Table of Contents

- <span style="color:blue;">Team MAYERDOA - "Mothers' Prayers"</span>
- <span style="color:green;">Mission Overview for WRO Future Engineers Rounds</span>
- <span style="color:orange;">Components and Hardware</span>
- <span style="color:purple;">Assembly Instructions</span>
- <span style="color:red;">Project Objective</span>
- <span style="color:teal;">Mobility Management</span>
- <span style="color:navy;">Power and Sense Management</span>
- <span style="color:brown;">Program Infrastructure and Explanation of Algorithm</span>
- <span style="color:darkgreen;">Software Setup</span>




Our bot, **SMOKI**, is built for excellence in the **World Robot Olympiad 2024** in the Future Engineers category. From its structural core using LEGO Technic elements to its computing capabilities powered by the **Raspberry Pi 4B** and **ESP32 microcontroller**, SMOKI is crafted to handle the nuanced challenges of autonomous navigation and obstacle handling.

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
>[!IMPORTANT]
>**Important: WRO Future Engineers Rulebook**
>* **Thorough Reading:** Ensure that you thoroughly read the **WRO Future Engineers 2024 Rulebook** to understand all rules and guidelines.
>* **Official Link:** Access the rulebook here: [🔗 WRO Future Engineers 2024 Rulebook](https://wro-association.org/competitions/future-engineers/).

---
---


## 🧩 Components and Hardware

Our bot is equipped with various components that support its autonomous functionality. Here is a breakdown of the key hardware elements used in this project:

| Component                          | Description                                                                                      | Image                                                                                                        | Purchase Link                                                                                     |
|------------------------------------|--------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------|
| **Raspberry Pi 4B**                | Provides processing power for control algorithms and sensor data management.                     | <div align="center"><img src="https://github.com/user-attachments/assets/b6b79ab7-a635-4ff0-9f66-b53b7e97dcd7" alt="Raspberry Pi 4B" width="100"></div> | [Purchase Raspberry Pi 4B](https://amzn.to/3wKg5TG)                                              |
| **ESP32 Microcontroller**         | Handles real-time sensor data interpretation and motor control.                                  | <div align="center"><img src="https://github.com/user-attachments/assets/0fe5f54b-8df2-492c-a68c-8e100bae381d" alt="ESP32" width="100"></div>        | [Purchase ESP32](https://amzn.to/3ESP32)                                                         |
| **LEGO EV3 Expansion Set (45560)** | Modular components used for building and structural support.                                     | <div align="center"><img src="https://github.com/user-attachments/assets/c99f6a51-5c82-4981-bed8-0cb59690b966" alt="LEGO EV3 Set" width="100"></div>  | [Purchase LEGO 45560](https://amzn.to/3K4eLEGO)                                                  |
| **XL4016 Buck Converter**         | Provides stable voltage for the Raspberry Pi and ESP32, enhancing power management.              | <div align="center"><img src="https://github.com/user-attachments/assets/b7184ca5-34c3-48db-86e7-a5e919362516" alt="XL4016 Buck Converter" width="100"></div> | [Purchase XL4016](https://amzn.to/4xl4016)                                                       |
| **Custom PCB**                     | Custom-designed PCB for efficient wiring and stable connections across all components.           | <div align="center"><img src="https://github.com/user-attachments/assets/395457b5-f8e8-41e0-8a82-dc93fbd486c8" alt="Custom PCB" width="100"></div>           | N/A                                                                                              |
| **Ultrasonic Sensors**             | Detects distances to obstacles and aids in precise navigation.                                   | <div align="center"><img src="https://github.com/user-attachments/assets/dc6408c5-e4c1-4a63-b9cf-35efa5a8483a" alt="Ultrasonic Sensor" width="100"></div> | [Purchase Ultrasonic Sensor](https://amzn.to/3Ultrasonic)                                        |
| **Webcam - FIFINE K420 HD**        | Captures visual data, supporting navigation and obstacle detection tasks.                        | <div align="center"><img src="https://github.com/user-attachments/assets/fifine_k420_hd_webcam.png" alt="FIFINE K420 HD Webcam" width="100"></div> | [Purchase FIFINE K420 HD Webcam](https://amzn.to/3FifineK420)                                   |
| **Gyroscope - MPU 6050**           | Provides motion tracking and orientation data, enabling stable navigation and movement.          | <div align="center"><img src="https://github.com/user-attachments/assets/07cc2983-cd5c-4480-8f0b-84880edcf8bd" alt="MPU 6050" width="100"></div>       | [Purchase MPU 6050](https://amzn.to/3MPU6050)                                                   
| **Battery - GENS 1000mAh**         | Supplies power to the robot, ensuring long operational time and reliable energy for all components.| <div align="center"><img src="![Gens-Ace-2200mah-3s-lipo-removebg-preview](https://github.com/user-attachments/assets/87325f1f-403d-42e1-ae27-17ad206f80ad)" width="100"></div>       | [Buy GENS ACE 11.1V 3S LiPo Battery](https://www.rcshopbd.com/product/gens-ace-11-1v-3s-lipo-1000mah-1650mah-2200mah-3300mah-battery/)

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

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
  <table style = "width:100%; border-collapse:collapse">
    <caption><strong>Framed Images</strong></caption>
    <tr>
      <td><img src="https://github.com/user-attachments/assets/0994a988-1f73-43db-b7f9-34c5243a842a" alt="Image 1"></td>
      <td><img src="https://github.com/user-attachments/assets/39b389db-0038-425f-bcd5-740f748e3cc9" alt="Image 2"></td>
    </tr>
    <tr>
      <td><img src="https://github.com/user-attachments/assets/339eaf97-91a8-4987-8af9-c86c2d4fe360" alt="Image 3"></td>
      <td><img src="https://github.com/user-attachments/assets/30eae1ee-b442-4caf-86c3-7d5bbb12c6c3" alt="Image 4"></td>
    </tr>
    <tr>
      <td><img src="https://github.com/user-attachments/assets/e95b4755-0067-4639-bd6b-58631e9da91e" alt="Image 5"></td>
      <td><img src="https://github.com/user-attachments/assets/cb176c4d-0af5-4f80-ae3b-d7a9033592d0" alt="Image 6"></td>
    </tr>
    <tr>
      <td colspan="2"><img src="https://github.com/user-attachments/assets/14527900-366e-4555-8aac-33a8163e1e19" alt="Image 7" style="width: 100%; height: auto;"></td>
    </tr>
  </table>
</body>
</html>


### 🚗 Drive System

The drive system includes DC motors, which provide reliable propulsion and control.


<p align="center">
  <table>
    <tr>
      <td>
        <img src="https://github.com/user-attachments/assets/297d61d9-bef9-49eb-92bd-bed3f49f170d" width="350" height="200" />
      </td>
      <td>
        <img src="https://github.com/user-attachments/assets/3731a99c-2025-4ecf-bbbc-6adab70886ab" width="350" height="200" />
      </td>
    </tr>
    <tr>
      <td>
        <img src="https://github.com/user-attachments/assets/e5054dfd-4277-47fe-9986-4acdd1ff4e14" width="350" height="200" />
      </td>
      <td>
        <img src="https://github.com/user-attachments/assets/f5ab2184-7332-4fab-bb6f-050e5189baf2" width="350" height="200" />
      </td>
    </tr>
  </table>
</p>



----


# 🚗 Mobility Management

This segment goes over the mobility management of SMOKI
---

### **Rear Axle Power Distribution**

Initially, the rear wheels were powered through a **Bevel Gear**, but we later upgraded to a **Differential Gearbox** to improve efficiency and performance during turns.

---

#### **Bevel Gear**

<table>
<tr>
<td width="50%">
<div align="center">
  <img src="https://github.com/user-attachments/assets/9e19661f-b921-4bea-9028-4e0274306ced" width="300"/>
</div>
</td>
<td width="50%">

A **bevel gear** is a type of gear where the axes of the two shafts intersect, and the tooth-bearing faces of the gears are conical. Bevel gears are commonly used to transfer motion between intersecting shafts at an angle, typically 90°.

##### **How Bevel Gears Work**
- A driver gear transfers motion to a driven gear, which rotates an output shaft.
- The teeth of the gears are designed to mesh smoothly, transferring torque efficiently between the shafts.

##### **Advantages of Bevel Gears**
1. **Compact Design**: Suitable for space-constrained applications.
2. **Efficient Torque Transfer**: Provides reliable power transmission at angles.
3. **Versatility**: Can operate at angles other than 90° if needed.

</td>
</tr>
</table>

---
>[!IMPORTANT]
> Bevel gears were essential in the initial stages of our design, but they had limitations in terms of energy efficiency during turns.
---

#### **Differential Gearbox**

<table>
<tr>
<td width="50%">

A **differential gearbox** allows the wheels on the same axle to rotate at different speeds while receiving power from a single motor. This is crucial for smooth turning, where the outer wheel must travel a larger distance than the inner wheel.

##### **Advantages of Differential Gearbox**
1. **Smooth Turns**: Adapts to varying wheel speeds, ensuring efficient cornering.
2. **Energy Efficiency**: Reduces energy wastage by minimizing wheel slippage.
3. **Component Longevity**: Minimizes wear on tires and axles.

##### **How Differential Gears Work**
- Power from the motor is delivered to an input shaft.
- The differential splits the torque between the two wheels via bevel or spider gears inside the housing.
- During turns, the differential allows one wheel to spin faster than the other, ensuring smooth movement.

</td>
<td width="50%">
<div align="center">
  <img src="https://github.com/user-attachments/assets/4bd7f40f-d350-4215-8cf4-2bf46d3cc779" width="300"/>
</div>
</td>
</tr>
</table>

---

#### **Comparison: Bevel Gear vs. Differential Gearbox**

| **Feature**                | **Bevel Gear**                            | **Differential Gearbox**                |
|----------------------------|-------------------------------------------|-----------------------------------------|
| **Turning Efficiency**     | Limited; fixed wheel speeds.             | Superior; wheels rotate independently. |
| **Energy Usage**           | Higher due to slippage during turns.     | Lower; optimized for dynamic turns.    |
| **Durability**             | Higher strain on components.             | Reduced strain; longer component life. |

---

### **Servo Motor with L293D Motor Driver**

<table>
<tr>
<td width="30%">
<div align="center">
  <img src="https://github.com/user-attachments/assets/ffcfa0ae-2682-4199-8c0b-4bcbff421d08" width="150"/>
</div>
</td>
<td width="70%">

We used the **L293D Motor Driver** in combination with a **Servo Motor** to control the robot's wheels effectively. We are using **L293D Motor Driver** to control the rear axle motor. The L293D is a dual H-Bridge motor driver that is perfectly suited for the LEGO motor, which operates at **750mA** current.

##### **Why L293D?**
- **Optimal Current Capacity**: Can handle up to **1A** peak current, suitable for the LEGO motor’s 750mA requirement.
- **Bidirectional Control**: Facilitates forward and backward motion of the wheels.
- **Compact and Lightweight**: Ideal for small-scale robotic systems.
- **PWM Support**: Enables smooth speed control of the motors.

##### **Advantages of the Servo Motor with L293D**
1. **Accurate Steering**: The servo motor ensures precise angle adjustments.
2. **Smooth Speed Control**: PWM functionality provides variable speed control.
3. **Efficient Current Management**: Matches the LEGO motor's current needs, ensuring reliable operation.

</td>
</tr>
</table>

---

### **Steering Systems**

Our robot initially used the **Ackermann Steering System**, known for its efficiency in real-world vehicles. However, we later transitioned to the **LEGO Steering System** to simplify the design and improve modularity while maintaining effective steering control.

---

#### **What is Ackermann Steering System?**

The **Ackermann Steering System** ensures that the wheels of a vehicle turn at different angles during a corner. The inner wheels turn more sharply than the outer wheels, reducing tire slippage and allowing smooth, efficient turning.

##### **How Ackermann Steering Works**
- The front wheels are connected via a set of steering arms.
- These arms are angled so that their lines meet at the center of the turn’s radius, ensuring concentric paths for all wheels.

##### **Advantages of Ackermann Steering**
1. **Efficient Turning**: Minimizes tire slippage.
2. **Energy Savings**: Reduces power loss caused by wheel drag.
3. **Realistic Simulation**: Mirrors real-world vehicle steering.

---

#### **Why We Switched to LEGO Steering System**

The **LEGO Steering System** offered greater simplicity and modularity, which were critical for our robot’s design. While Ackermann Steering is ideal for large-scale vehicles, the LEGO system provided better adaptability for our compact robot.

---

#### **What is LEGO Steering System?**

The LEGO Steering System uses modular LEGO Technic parts with a simple rack-and-pinion mechanism for steering. It achieves a turning angle of **50 degrees**, allowing precise control over the robot's movements.

##### **Advantages of LEGO Steering**
1. **Modularity**: Easy to assemble, adjust, and maintain.
2. **Compact Design**: Fits seamlessly into the robot’s chassis.
3. **Precision**: Allows accurate steering movements with a servo motor.
4. **Ease of Use**: Simplifies the overall system design without sacrificing functionality.

---
---

### **Conclusion**

The upgrades to our robot’s mobility system—switching from bevel gears to a differential gearbox, integrating the L293D with a servo motor, and transitioning from  a 3D printed steering mechanism to a steering mechanism using LEGO parts—significantly enhanced its performance. These changes provided:
1. **Smoother Turns**: Differential gearbox enabled independent wheel speeds, reducing slippage.
2. **Precise Control**: The L293D motor driver ensured smooth speed and direction management.
3. **Simpler Design**: LEGO Steering’s modularity allowed for easier integration and maintenance.
4. **Energy Efficiency**: Reduced strain on components, improving energy usage and longevity.

Together, these upgrades ensured that our robot was optimized for the challenges of the WRO course, achieving a balance between simplicity and performance.


----
----
----

# ⚡ Power and Sense Management :

The **Power and Sense Management** system of our robot has been meticulously designed to optimize performance while ensuring reliable power delivery, precise sensing, and efficient communication between components.


## 📜 Overview
The power system ensures all components receive stable and efficient power tailored to their unique voltage and current requirements. This design optimizes energy utilization and guarantees reliability under various operational loads.

---

## ⚙️ System Architecture

### **1. Power Source: Two Lithium-Ion Cells**
- **Configuration**: Two 4.2V lithium-ion cells connected in series.
- **Total Voltage**: 8.4V when fully charged, dropping to ~6V when discharged.
- **Features**:
  - High energy density for extended runtime.
  - Lightweight and rechargeable.

---

### **2. XL4016 Buck Converter**
- **Input**: 8.4V from the battery pack.
- **Output**: Stable 5V for the **Raspberry Pi 5** and other components.
- **Specifications**:
  - Input Voltage Range: Up to 40V.
  - High efficiency (~90%) for minimal heat generation.
- **Usage**:
  - Powers the Raspberry Pi 4B to ensure stable performance for real-time processing tasks.

---

### **3. Additional Buck Converters**
#### **(a) 5V Buck Converter for Servo Motor**
- **Purpose**: Supplies 5V for the **Servo Motor**.
- **Key Benefits**:
  - Ensures optimal torque and speed for motor operations.
  - Prevents jitter or underperformance caused by unstable power.

#### **(b) 5V Buck Converter for ESP32**
- **Purpose**: Supplies 5V for the **ESP32 Microcontroller**.
- **Features**:
  - Powers the ESP32 for communication (Wi-Fi and Bluetooth).
  - Protects against overvoltage, ensuring stable and reliable operation.

---

### **4. Buck-Boost Converter for Motors**
- **Purpose**: Provides a consistent 12V for the motors, regardless of battery voltage variations.
- **How It Works**:
  - Boosts the voltage when input drops below 12V (e.g., batteries discharged to 6V).
  - Steps down the voltage if the input exceeds 12V.
- **Benefits**:
  - Delivers reliable motor performance under various loads.
  - Prevents voltage-related motor performance issues.

---

## 🔌 Voltage Distribution Table

| Component                | Voltage Supplied | Converter Type      |
|--------------------------|------------------|---------------------|
| **Raspberry Pi 4B**       | 5V               | XL4016 Buck         |
| **Servo Motor**          | 5V               | Buck Converter      |
| **ESP32 Microcontroller**| 5V               | Buck Converter      |
| **Motors**               | 12V              | Buck-Boost Converter|

---

## 🔧 Installation and Configuration

1. **Connect the Lithium-Ion Cells**:
   - Use a **series connection** to achieve 8.4V.
   - Ensure a proper battery management system (BMS) to prevent overcharging or deep discharging.

2. **Setup XL4016 Buck Converter**:
   - Adjust the output voltage to 5V using the onboard potentiometer.
   - Connect the output to the Raspberry Pi 5 power input.

3. **Install Buck Converters**:
   - **5V Converter for Servo Motor**:
     - Configure the output voltage to 5V for the servo motor.
     - Connect the output to the servo's power input.
   - **5V Converter for ESP32**:
     - Configure the output voltage to 5V for the ESP32 microcontroller.
     - Connect the output to the ESP32's power input.

4. **Configure Buck-Boost Converter**:
   - Set the output to 12V.
   - Connect the output to the motor driver’s power input.

5. **Test Voltage Levels**:
   - Use a multimeter to verify output voltages for each converter before powering the components.

---

## 🛠 Maintenance Tips
- **Regularly Check Connections**:
  - Ensure tight and secure connections to avoid power interruptions.
- **Monitor Battery Levels**:
  - Recharge the lithium-ion cells when the voltage drops below 6V.
- **Inspect Converters**:
  - Periodically check for overheating or loose components on the converters.

---

## 🚀 Future Improvements
- Integrate a smart power monitoring system to dynamically adjust power distribution.
- Upgrade to more energy-efficient components as technology advances. ( WE WILL BE AROUND HOPEFULLY)

---
## 🎥 Camera Placement and Functionality

The robot's main camera is positioned at the top and angled slightly downwards. This setup enhances object detection capabilities by providing:
- **🔍 Close-Range Detection**: The camera can identify objects in close proximity with high accuracy.
- **🌐 Extended-Range Detection**: Ensures objects further away are detected effectively.

The camera feeds data to the **Raspberry Pi 5**, which processes image recognition algorithms to detect towers and corner lines. The processed data is then transmitted to the **ESP32 microcontroller** for real-time navigation and obstacle avoidance.

---

## 📡 Sonar Mount Design

### 🛠️ Previous Design
In our earlier design, we used **HC-SR04 sonar sensors** placed at **45-degree angles**, mounted horizontally on two sides of the robot, with one sensor placed vertically in the middle. This configuration provided basic obstacle detection but had limitations:
- **🚫 Blind Spots**: The horizontal placement created gaps in detection range at certain angles.
- **⚠️ Inconsistent Readings**: The 45-degree angle sometimes caused inaccuracies due to signal reflections.

### 🔄 Why We Switched
After analyzing performance during testing, we made significant improvements:
- Replaced the 45-degree sensors with sensors mounted at **15 degrees**.
- Mounted the sensors **vertically on all sides**, ensuring:
  - **🛑 Improved Obstacle Detection**: Enhanced accuracy and coverage around the robot.
  - **📏 Better Range Consistency**: Reduced signal reflection issues for more reliable readings.

### 🚀 Current Design
The new configuration leverages **HC-SR04 sonar sensors**, chosen for their **wide availability** and **affordable price**. The updated design provides:
- **High Coverage**: Vertical mounting eliminates blind spots.
- **Early Detection**: Enhanced obstacle sensing allows for quicker decision-making.
- **Really Cheap**: You can buy 300 of these instead of a Lider Sensor.

---


>[!IMPORTANT]
> **Power Highlights:**
> - The XL4016 Buck Converter ensures stable voltage regulation, critical for protecting the Raspberry Pi and ESP32 microcontroller during operation.
> - Independent buck modules handle the servo motor and ESP32 power needs, optimizing energy usage across all components.

---
---

## 🛠️ Our PCB is custom made. The schematics are in the schematic folder 

---
# Project Name

## 🖼️ System Visuals

### PCB Views

| **Top View of PCB**                 | **Bottom View of PCB**             |
|-------------------------------------|-------------------------------------|
| <img src="https://github.com/user-attachments/assets/be051834-2c23-495e-9aa1-83d9620e1524" width="800"/> | <img src="https://github.com/user-attachments/assets/45d68411-f99a-4ef4-8aef-c63eb856a8e1" width="800"/> |

### Power Management Diagram

<img width="801" alt="DIAGRAM" src="https://github.com/user-attachments/assets/069480c6-0f9b-4a68-be3e-c151bef17a56"/>



---
---

# 🧠 Program Infrastructure and Explanation ## 🏁 Round 1 Algorithm - Lap Completion

In **Round 1**, our robot **SMOKI** must autonomously complete **three laps** on a predefined track without the need for obstacle avoidance. To achieve precise navigation and lap counting, we have developed a robust algorithm that integrates image processing with control systems.

---

### 🌐 Algorithm Overview

1. **📸 Image Acquisition**:
   - The robot captures real-time images of the track using its onboard camera.

2. **🎨 Color Space Conversion**:
   - Captured images are converted from the **RGB** color space to the **HSV (Hue, Saturation, Value)** color space.
   - The HSV color space is chosen for its effectiveness in color segmentation, as it is less sensitive to lighting variations.

3. **🔍 Color Segmentation and Orientation Determination**:
   - Using predetermined HSV ranges, the algorithm isolates the **blue** and **orange** line segments on the track.
   - During the first run, the robot checks whether the blue line appears before the orange line or vice versa.
   - **Orientation Determination**:
     - If the blue line comes before the orange line, the robot sets its orientation accordingly.
     - This initial orientation check ensures the robot follows the track in the correct direction.

4. **📏 Line Detection and Lap Counting**:
   - The **Hough Line Transform** method is applied to detect lines within the segmented images.
   - The robot counts the detected lines to keep track of laps.
   - **Lap Completion**:
     - After counting **12 lines** (corresponding to three laps), the robot initiates a predetermined delay and then stops.

5. **⚙️ Position Correction Using PID Control**:
   - Before setting the orientation, a **PID (Proportional-Integral-Derivative) controller** calculates the error.
   - **Error Calculation**:
     - The error is determined by the difference between the distances measured by sensors on the left and right sides of the robot (i.e., `error = left_distance - right_distance` or vice versa).
   - **Distance Maintenance**:
     - If the orientation is **right-based**, the robot maintains a **25 cm** distance from the right side.
     - If the orientation is **left-based**, it maintains a **25 cm** distance from the left side.
   - The PID controller adjusts the robot's steering to minimize the error, helping it stay centered on the track.

---

### 📖 Detailed Explanation

#### 1. 📸 Image Acquisition and Preprocessing

- **Camera Input**:
  - High-resolution images are captured at regular intervals to ensure up-to-date visual data.
- **HSV Conversion**:
  - Conversion to HSV allows for more effective color thresholding.
  - HSV separates image intensity (Value) from color information (Hue and Saturation), making it easier to detect specific colors under varying lighting conditions.

#### 2. 🎨 Color Segmentation

- **HSV Thresholding**:
  - Specific HSV ranges for blue and orange are defined based on calibration.
  - **Blue Line Detection**:
    - Pixels within the blue HSV range are extracted.
  - **Orange Line Detection**:
    - Pixels within the orange HSV range are extracted.
- **Orientation Check**:
  - By analyzing the sequence of color segments (blue vs. orange), the robot determines its starting orientation.
  - This prevents incorrect lap counting due to starting in the wrong direction.

#### 3. 📏 Line Detection with Hough Transform

- **Edge Detection**:
  - Preprocessing steps like Gaussian blur and Canny edge detection are applied to enhance line features.
- **Hough Line Transform**:
  - Detects straight lines by transforming points in image space to a parameter space.
  - Lines are identified based on the accumulation of intersecting points in the parameter space.
- **Lap Counting Logic**:
  - Each detected line crossing increments a counter.
  - The robot recognizes lap completion after counting **12** line crossings, accounting for both blue and orange lines over three laps.

<div align="center">
  <!-- Placeholder for Hough Line Transform Image -->

  <img src="https://github.com/user-attachments/assets/24ef6a2d-ce3d-4522-8181-7e811d370d6b" alt="Hough Line Transform" width="600">
  <p><em>Figure: Visualization of Hough Line Transform applied to track image.</em></p>
</div>

#### 🔗 **Hough Line Transform Tutorial**

For a comprehensive understanding of the Hough Line Transform method, you can watch this detailed tutorial:

- [🔗 Hough Line Transform Tutorial by DigitalSreeni](https://www.youtube.com/watch?v=5zAT6yTHvP0&ab_channel=DigitalSreeni)

#### 4. ⚙️ PID Control for Position Correction

- **Sensor Input**:
  - Distance sensors on both sides provide real-time measurements of the robot's position relative to the track edges.
- **Error Calculation**:
  - The error signal is the difference between the left and right distance measurements.
- **PID Controller**:
  - **Proportional Term (P)**: Reacts to the current error.
  - **Integral Term (I)**: Accounts for past errors to eliminate steady-state offset.
  - **Derivative Term (D)**: Predicts future error based on the rate of change.
- **Steering Adjustment**:
  - The PID output adjusts the steering angle to minimize the error.
  - Ensures the robot maintains the desired **25 cm** distance from the designated side.
- **Orientation-Based Behavior**:
  - **Right-Based Orientation**:
    - The robot favors the right side of the track.
  - **Left-Based Orientation**:
    - The robot favors the left side of the track.

---

### 📊 Flowchart of the Algorithm

## 📊 Flowchart of the Algorithm

```mermaid
flowchart TD
    A[Start] --> B[Capture Image]
    B --> C[Convert to HSV]
    C --> D[Segment Blue and Orange Portions]
    D --> H[Apply Hough Line Transform]
    H --> E{Blue Before Orange?}
    E -->|Yes| F[Set Right-Based Orientation]
    E -->|No| G[Set Left-Based Orientation]
    F --> I[Count Detected Lines]
    G --> I
    I --> J{Lines Counted >= 12?}
    J -->|No| K[Calculate Error]
    K --> L[PID Controller Adjusts Steering]
    L --> M[Continue Navigation]
    M --> B
    J -->|Yes| N[Delay and Stop]
    N --> O[End]
```
---

# 🏆 Round 2 Algorithm - Lap Completion with Obstacle Avoidance and Object Detection

Round 2 involves an enhanced version of our robot SMOKI, which autonomously completes three laps, avoiding obstacles and calculating the steering value based on object prioritization and boundary detection. Below is an in-depth look at the step-by-step algorithm implemented for this round.

## 🌟 Step-by-Step Algorithm Overview

### 📸 Image Acquisition:
- The camera captures real-time images of the track and surroundings.

### 🎨 HSV Color Conversion:
- Convert the captured image from RGB to HSV (Hue, Saturation, Value) scale.
- Store all relevant line and object colors for further use.

### 💨 Gaussian Blur:
- Apply Gaussian Blur to the frame to reduce noise.
- Based on predetermined HSV range, isolate the black border portion.

### ⚫ Black Border Detection:
- Use Canny Edge Detection to identify the black border walls.
- Apply Hough Line Probabilistic Transformation to determine acceptable border walls.

### 🛑 Border Masking:
- Create a border in the frame based on the detected lines.
- Mask out everything beyond the border to eliminate unnecessary information for the rest of the algorithm.

### 🔍 Line Detection (Blue or Orange):
- Identify lines using the predetermined HSV color range.
- Check for the blue or orange line in the frame.

### 📐 Slope Calculation:
- If a line is found, calculate the minimum and maximum slopes for both the blue and orange lines (if both are present).

### ↩️ Orientation Determination:
- If both blue and orange lines are detected, compare their slopes.
- Determine the clockwise or anti-clockwise orientation and store this in a variable for future reference.

### 📊 Object Detection and Prioritization:
- Detect acceptable objects within the boundary wall.
- Assign a priority value to each object based on distance, orientation, and coordinates.
- Register only one object based on predetermined mathematical calculations.
- Calculate the steering value for navigation using a quadratic function based on the object's distance and position along the x-axis.

### 📡 Serial Communication:
- Send the calculated steering value to the ESP32 via serial communication to adjust the robot's movement accordingly.

---

## Algorithm Explanation

- **HSV Conversion** allows for effective color segmentation, making it easier to distinguish between track lines and other features regardless of lighting conditions.
- **Gaussian Blur** helps to reduce noise, making the detection of borders and lines more reliable.
- Using **Hough Line Transform** and **Canny Edge Detection** enables accurate identification of boundaries, which is crucial for masking irrelevant parts of the frame.
- **Slope Comparison** provides the robot with information about its current orientation, enabling it to differentiate between clockwise and anti-clockwise directions based on the detected lines.
- The **Object Prioritization** mechanism ensures that the robot only reacts to the most relevant obstacle, improving navigation efficiency.
- Finally, the calculated steering value is sent to the ESP32 for precise movement control, ensuring that the robot maintains its intended path while avoiding obstacles effectively.

## Video Tutorial for Hough Line Transform

For a better understanding of how the Hough Line Transform method is used in our algorithm, you can watch this detailed video tutorial:

- [🔗 Hough Line Transform Tutorial by DigitalSreeni](https://www.youtube.com/watch?v=6-3HgNZkDGA)

## Next Steps

- Test the algorithm in various track conditions to ensure robustness.
- Fine-tune the HSV color ranges and quadratic function for steering to achieve optimal performance.
- Collect data on the robot's performance to further refine the object prioritization logic.

Feel free to reach out if you need more insights or help with further tuning the algorithm!




## **Flowchart**

```mermaid
flowchart TD
    Start --> Step1[Capture Image]
    Step1 --> Step2[Convert Image to HSV]
    Step2 --> Step3[Apply Gaussian Blur]
    Step3 --> Step4[Isolate Black Borders]
    Step4 --> Step5[Detect Borders with Canny Edge and Hough Transform]
    Step5 --> Step6[Mask Area Outside Borders]
    Step6 --> Step7[Detect Blue or Orange Lines]
    Step7 --> Step8[Calculate Min and Max Slopes]
    Step8 --> Decision1{Both Lines Detected?}
    Decision1 -- Yes --> Step9[Determine Orientation]
    Decision1 -- No --> Step9[Use Detected Line]
    Step9 --> Step10[Detect Objects Within Boundary]
    Step10 --> Step11[Assign Priority to Objects]
    Step11 --> Step12[Select Highest Priority Object]
    Step12 --> Step13[Calculate Steering Value]
    Step13 --> Step14[Send Steering Value to ESP32]
    Step14 --> End

```


---
---
<p align="center">
  # THATS ALL FROM US
</p>


<img src="https://github.com/user-attachments/assets/3c4eb0aa-37f5-4255-a176-253f5ae422f5" />
