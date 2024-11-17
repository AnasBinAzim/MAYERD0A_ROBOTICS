# 🤖 **MAYERDOA Robotics - WRO 2024 Project** 🤖

<div align="center">
  <img src="https://github.com/user-attachments/assets/b69b15b8-69d2-439a-aac6-5dcfc8eba67c"/>
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
<img align="right" alt="SMOKI" width="350" src="https://github.com/user-attachments/assets/36358350-49c4-48aa-8618-6050d7534626">

This repository contains all files, designs, and code used to create **SMOKI**. Below is a breakdown of the folder structure:

* `models` - STL files for 3D-printed components.
* `getting_started` - Initial setup guide.
* `src` - Main code files for the robot.
* `video` - Link to a YouTube demonstration of SMOKI in action.
* `t-photos` - Contains one serious and one funny team photo.
* `v-photos` - Photos of the robot from all angles.
* `others` - Additional essential photos.


----
----
----

## Table of Contents

- [Team MAYERDOA - "Mothers' Prayers"](#team-mayerdoa---mothers-prayers)
- [Mission Overview for WRO Future Engineers Rounds](#mission-overview-for-wro-future-engineers-rounds)
- [Components and Hardware](#components-and-hardware)
- [Assembly Instructions](#assembly-instructions)
- [Project Objective](#project-objective)
- [Mobility Management](#mobility-management)
- [Power and Sense Management](#power-and-sense-management)
- [Program Infrastructure and Explanation of Algorithm](#program-infrastructure-and-explanation-of-algorithm)
- [Software Setup](#software-setup)





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
  <img src="https://github.com/user-attachments/assets/0994a988-1f73-43db-b7f9-34c5243a842a" width="330" height="225" />
  <img src="https://github.com/user-attachments/assets/39b389db-0038-425f-bcd5-740f748e3cc9" width="330" height="225" />
  <img src="https://github.com/user-attachments/assets/339eaf97-91a8-4987-8af9-c86c2d4fe360" width="330" height="225" />
  <img src="https://github.com/user-attachments/assets/30eae1ee-b442-4caf-86c3-7d5bbb12c6c3" width="330" height="225" />
  <img src="https://github.com/user-attachments/assets/e95b4755-0067-4639-bd6b-58631e9da91e" width="330" height="225" />
  <img src="https://github.com/user-attachments/assets/cb176c4d-0af5-4f80-ae3b-d7a9033592d0" width="330" height="225" />
  <img src="https://github.com/user-attachments/assets/14527900-366e-4555-8aac-33a8163e1e19" />
</p>


### 🚗 Drive System

The drive system includes DC motors, which provide reliable propulsion and control.

https://github.com/user-attachments/assets/59de14fc-f248-4ac2-8b31-80baea148cff


<p align="center">
  <img src="https://github.com/user-attachments/assets/297d61d9-bef9-49eb-92bd-bed3f49f170d" width="700"height="400" />
  <img src="https://github.com/user-attachments/assets/3731a99c-2025-4ecf-bbbc-6adab70886ab" width="700" height="400" />
  <img src="https://github.com/user-attachments/assets/e5054dfd-4277-47fe-9986-4acdd1ff4e14" width="700" height="400" />
  <img src="https://github.com/user-attachments/assets/f5ab2184-7332-4fab-bb6f-050e5189baf2" width="700" height="400" />
</p>

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

The mobility system of our robot has been meticulously designed to ensure smooth, efficient, and reliable movement, addressing both power distribution and maneuverability.

### Front Axle Articulation

The front axle is articulated by a **Servo Motor**, enabling precise steering control. This configuration allows the robot to execute sharp turns and navigate complex paths with accuracy. The servo motor's responsiveness ensures that the robot can adapt to dynamic scenarios effectively, providing the necessary flexibility for competitive tasks.

### Rear Axle Power Distribution

The rear wheels are powered through a **differential gearbox**, driven by a **LEGO Encoder Motor** from the **45560 Expansion Set**. The differential gearbox serves a critical role by enabling the wheels on the same axle to rotate at different speeds while receiving power from a single **DC motor**. This functionality is especially important during turns, where the outer wheel must travel a greater distance than the inner wheel.

#### Understanding the Differential Gearbox

A differential gearbox is a mechanical device that splits the engine torque two ways, allowing each output to spin at a different speed. This is crucial for vehicles, including robots, to navigate turns smoothly. When a vehicle turns, the wheels on the outside of the turn must cover more distance than the wheels on the inside. Without a differential, both wheels would be forced to rotate at the same speed, leading to increased tire wear, reduced traction, and potential mechanical strain.

<p align="center">
  <img src="https://github.com/user-attachments/assets/18ed7431-8bcc-4953-92a2-46f3a52d74c5" width="500" height="305" />
</p>

*Image Source: [LearnMech](https://learnmech.com/working-of-differential-gear-box-for/)*

#### How It Works

The differential gearbox consists of several key components:

- **Input Shaft (Driveshaft):** Transmits power from the motor to the differential.
- **Bevel Gears:** Facilitate the splitting of torque between the wheels.
- **Side Gears:** Connected to the axle shafts, transmitting power to the wheels.
- **Pinion Gears:** Interact with the side gears to allow differential action.

During straight-line movement, the differential distributes equal torque to both wheels, causing them to rotate at the same speed. However, during a turn, the pinion gears rotate around the side gears, allowing one wheel to speed up and the other to slow down, accommodating the difference in distance each wheel travels.

#### Benefits in Robotic Applications

- **Smooth Turning:** Enables the robot to navigate turns without wheel slippage or mechanical strain.
- **Energy Efficiency:** Reduces the power required to maneuver, conserving battery life.
- **Component Longevity:** Minimizes wear on wheels and axles, extending the lifespan of mechanical parts.

#### Integration with LEGO Encoder Motor

The LEGO Encoder Motor provides precise control over rotational speed and direction, which, when combined with the differential gearbox, allows for:

- **Accurate Speed Regulation:** Ensures that the differential receives consistent input, facilitating predictable wheel behavior.
- **Feedback Mechanism:** The encoder provides real-time data on motor performance, enabling adjustments for optimal operation.

<p align="center">
  <img src="https://github.com/user-attachments/assets/6e02cdbc-f871-4d50-b9f5-c20749cfb451" />
</p>

*Image Source: [3DTool](https://3dtool.ru/product/resursnyj-nabor-dlya-sborki-robotov-lego-mindstorms-ev3-45560-obrazovatelnaya-versiya/)*

### Motor Control System

To control the motors effectively, we integrated an **L298N Motor Driver**. This versatile motor driver module enables bidirectional motor control and speed regulation for both the encoder and DC motors. Key features of the L298N include:

- **Dual H-Bridge Design:** Facilitates independent control of two motors.
- **PWM Support:** Allows precise speed adjustments for optimal performance.
- **Current Overload Protection:** Enhances system reliability by safeguarding agai

## ⚡ Power and Sense Management

Power management and sensor integration are critical for maintaining consistent operation. This section explains our approach to stabilizing power supply to all components, while managing sensors like ultrasonic and camera modules for optimal performance.

---

## 🧠 Program Infrastructure and Explanation of Algorithm

In this section, we discuss the underlying software infrastructure, including how data flows within the system, how sensors are interpreted, and the logic behind navigation, obstacle avoidance, and lap counting algorithms. Our programming approach ensures efficient processing and response times.

---

## 💻 Software Setup

Our software environment integrates **Arduino IDE** for ESP32 programming and **Ubuntu OS** on the Raspberry Pi 5. Below is the complete guide for setting up the software environment, with all necessary commands and instructions.

---

### 1. Arduino IDE Setup for ESP32 Programming

We use **Arduino IDE** to program the ESP32 microcontroller. Follow these steps:

#### Step 1: Download and Install Arduino IDE
1. Visit the [official Arduino website](https://www.arduino.cc/en/software).
2. Download the version compatible with your operating system.
3. Run the installer and complete the installation process.

#### Step 2: Configure Arduino IDE for ESP32
1. Open the Arduino IDE.
2. Navigate to **File > Preferences**.
3. In the "Additional Boards Manager URLs," paste the following URL:
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
4. Click **OK**.
5. Go to **Tools > Board > Boards Manager**, search for "ESP32," and click **Install**.

#### Step 3: Verify the Setup
1. Connect your ESP32 via USB.
2. Select the correct board and port under **Tools**.
3. Upload a sample program (e.g., Blink) to test the setup.

---

### 2. Ubuntu OS Setup on Raspberry Pi 5

For this project, we installed **Ubuntu OS** on the Raspberry Pi 5. Here's how to do it:

#### Step 1: Download Ubuntu OS
1. Visit the [official Ubuntu website](https://ubuntu.com/download/raspberry-pi).
2. Download the Ubuntu image compatible with Raspberry Pi.

#### Step 2: Flash Ubuntu OS to an SD Card
1. Download and install **Raspberry Pi Imager** from [here](https://www.raspberrypi.com/software/).
2. Insert your SD card into the computer.
3. Open Raspberry Pi Imager and:
- **Select Operating System**: Choose the Ubuntu image you downloaded.
- **Select Storage**: Choose your SD card.
4. Click **Write** to flash the OS onto the SD card.

#### Step 3: Boot Ubuntu OS
1. Insert the SD card into the Raspberry Pi 5.
2. Connect peripherals (monitor, keyboard) and power up the Raspberry Pi.
3. Follow the on-screen instructions to complete the Ubuntu setup.

---

### 3. Installing Python on Ubuntu

Python is essential for running scripts and software. Install it by running the following commands:

| **Command**                      | **Description**                              |
|----------------------------------|----------------------------------------------|
| `sudo apt update`                | Updates the system package list.            |
| `sudo apt install python3 python3-pip -y` | Installs Python 3 and pip.                |

---

### 4. Installing OpenCV and Geany Editor

#### Install OpenCV
To enable computer vision functionalities, install OpenCV:

| **Command**                      | **Description**                              |
|----------------------------------|----------------------------------------------|
| `pip3 install opencv-python`     | Installs OpenCV.                             |
| `pip3 install opencv-python-headless` | Installs a lightweight version of OpenCV. |

#### Install Geany Editor
We used **Geany**, a lightweight IDE, for programming:

| **Command**                      | **Description**                              |
|----------------------------------|----------------------------------------------|
| `sudo apt install geany -y`      | Installs Geany editor.                       |

---

### 5. Remote Access with RealVNC

To remotely access the Raspberry Pi, we used **RealVNC**. Here's the setup process:

#### Step 1: Install RealVNC
Run the following commands:

| **Command**                      | **Description**                              |
|----------------------------------|----------------------------------------------|
| `sudo apt update`                | Updates the system package list.            |
| `sudo apt install realvnc-vnc-server realvnc-vnc-viewer -y` | Installs RealVNC.                  |

#### Step 2: Enable VNC
Enable VNC via the Raspberry Pi configuration tool:

| **Command**                      | **Description**                              |
|----------------------------------|----------------------------------------------|
| `sudo raspi-config`              | Opens the Raspberry Pi configuration tool.  |

- Navigate to **Interface Options > VNC** and select **Enable**.

#### Step 3: Start the VNC Server
Start the VNC server:

| **Command**                      | **Description**                              |
|----------------------------------|----------------------------------------------|
| `vncserver`                      | Starts the VNC server.                       |

#### Step 4: Automate VNC Server on Boot
To ensure the VNC server starts automatically on boot:

1. Open the VNC service configuration file:
```bash
sudo nano /etc/systemd/system/vncserver@.service

[Unit]
Description=Start VNC Server at user logon
After=syslog.target network.target

[Service]
Type=forking
User=pi
ExecStart=/usr/bin/vncserver :1
ExecStop=/usr/bin/vncserver -kill :1

[Install]
WantedBy=multi-user.target

sudo systemctl enable vncserver@1.service
sudo systemctl start vncserver@1.service
```


#### Step 5: Connect Remotely

Find the IP address of the Raspberry Pi by running:

| **Command**      | **Description**                                     |
|------------------|-----------------------------------------------------|
| `hostname -I`    | Displays the IP address of the Raspberry Pi.        |

1. Open **RealVNC Viewer** on your computer.
2. Enter the IP address (e.g., `192.168.x.x`) in the connection bar.
3. Log in using the VNC password you set during configuration.

---

### Summary of Installed Components

| **Component**     | **Purpose**                                          |
|--------------------|------------------------------------------------------|
| **Ubuntu OS**      | Operating system for the Raspberry Pi 5.            |
| **Arduino IDE**    | Programming the ESP32 microcontroller.              |
| **Python**         | Programming and script execution.                   |
| **OpenCV**         | Computer vision tasks.                              |
| **Geany**          | Lightweight editor for programming.                 |
| **RealVNC**        | Remote access and control of the Raspberry Pi.      |
