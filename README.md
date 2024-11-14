# WRO_FE_2024 Engineering Documentation / **Project SMOKI** / Team **MAYERDOA_ROBOTICS** / Bangladesh

<div align="center">
  <img src="https://github.com/user-attachments/assets/172c3a2a-33b5-4c01-a7e5-fbb2edcce263" alt="MAYERDOA Robotics Logo" width="200" />
</div>

# 🤖 Welcome to the WRO Bot Project Repository!

<div align="center">
  <img src="https://github.com/user-attachments/assets/172c3a2a-33b5-4c01-a7e5-fbb2edcce263" alt="Mayerdoa Robotics Logo" width="200" />
</div>

---

## 🌍 World Robot Olympiad (WRO) Bot Project: **MAYERDOA_ROBOTICS**

Welcome to the **World Robot Olympiad (WRO) Bot Project** repository! This project is a result of innovative engineering, teamwork, and a passion for robotics, designed to push the boundaries of autonomous functionality in a competitive environment. Our bot, **SMOKI**, combines the modularity and durability of **LEGO Technic** components, the processing power of a **Raspberry Pi 5**, and a comprehensive array of sensors controlled by an **ESP32 microcontroller** to bring high performance, adaptability, and intelligence to the WRO competition stage.

---

## 🎉 Introduction

The **WRO Bot Project** aims to create a highly capable, autonomous robot designed to excel in the **World Robot Olympiad (WRO) 2024 Future Engineers** category. With a focus on **smart and sustainable mobility**, this bot will perform intricate tasks under a range of challenging conditions. Using advanced robotics principles, the processing power of a **Raspberry Pi 5**, modular **LEGO Technic** components, and a suite of sensors, the bot is built to achieve precision, efficiency, and adaptability across various mission scenarios.

---

## 🎯 Project Objective

This project aims to create a competitive and reliable robot that can autonomously execute tasks in a time-sensitive, dynamic environment as outlined in the **WRO Future Engineers** competition. Key objectives include:

1. **Build a High-Performance Robot**  
   Design a robust robot capable of handling diverse and demanding tasks outlined in WRO’s mission-based rounds, focusing on modularity to adapt to different configurations and scenarios. The bot should execute tasks with precision, including object manipulation, autonomous pathfinding, and obstacle navigation.

2. **Utilize Modular and Reusable Parts**  
   By incorporating LEGO Technic components, a custom PCB, and tailored mounts, the bot’s structure is modular and reusable, allowing for easy reconfiguration and quick repairs. This setup ensures optimal performance across rounds and mission variations.

3. **Implement Advanced Control Code**  
   Develop sophisticated algorithms for the **ESP32** to manage sensor data interpretation, path planning, and task handling. This includes efficient data handling from ultrasonic, infrared, and camera sensors to enable the bot to make real-time decisions and adapt to environmental changes.

4. **Optimize for Future Engineers Rounds**  
   Prepare the robot specifically for the missions of the Future Engineers category, with flexible design and control logic to adapt to tasks like object sorting, navigation, alignment, and complex maneuvers. 

---

## 👥 Team Members

- **Anas Bin Azim** – [anas.azim.71@gmail.com](mailto:anas.azim.71@gmail.com)
- **Rakibul Islam** – [rakibul.rir06@gmail.com](mailto:rakibul.rir06@gmail.com)
- **Mohiuddin Sami** – [sm.mohiuddin.sami@gmail.com](mailto:sm.mohiuddin.sami@gmail.com)

**Team**: **MAYERDOA_ROBOTICS**  
**Country**: **Bangladesh**  
**Event**: **2024 World Robot Olympiad**

---

## 🚀 Features

Our bot is built to adapt to complex tasks and deliver high performance in the WRO environment. Below are some of the key features:

- **Raspberry Pi 5**  
  The **Raspberry Pi 5** serves as the brain of our bot, providing powerful processing capabilities for controlling sensors, managing tasks, and handling complex computational needs.
  ![Raspberry Pi 5](https://via.placeholder.com/150)  

- **ESP32 Microcontroller**  
  Acting as the main control unit, the **ESP32** is responsible for interpreting sensor data, handling input/output tasks, and executing control algorithms for movement and task execution.
  ![ESP32](https://via.placeholder.com/150)

- **XL4016 Buck Converter**  
  The **XL4016** buck converter efficiently steps down the voltage from the battery to supply stable 5V power to the Raspberry Pi and other components, ensuring reliable operation during competition tasks.
  ![XL4016 Buck Converter](https://via.placeholder.com/150)

- **Custom PCB**  
  Our custom-made PCB simplifies wiring and improves stability by integrating power management, sensor connections, and motor controls into a single, compact board.
  ![Custom PCB](https://via.placeholder.com/150)

- **LEGO EV3 Expansion Set (45560)**  
  This expansion set provides 853 LEGO Technic elements, such as beams, gears, and connectors, which enable us to build intricate mechanisms and expand our bot’s functionality.
  - **Key Models**: Six showcase models can be built using the 45560 set, such as the Elephant, Remote Control, Spinner Factory, Stair Climber, Tank Bot, and Znap.
  - **Purchase Link**: [LEGO EV3 Expansion Set 45560 on Amazon](https://www.amazon.com/dp/B00F3B2QK6)
  - **Building Instructions**: [Download LEGO 45560 Model Instructions](https://education.lego.com/en-us/product-resources/mindstorms-ev3/downloads)
  ![LEGO EV3 Set](https://via.placeholder.com/150)

- **Sensor Array**  
  Equipped with ultrasonic, infrared, and other sensors for obstacle detection, navigation, and environmental interaction.
  ![Sensor Array](https://via.placeholder.com/150)

- **Custom 3D-Printed Mounts**  
  Custom-made parts for securing components, ensuring stability and adaptability.
  ![3D Printed Mount](https://via.placeholder.com/150)

---

## 🧩 Hardware Components

- **Raspberry Pi 5**: The processing hub of the bot.
- **ESP32 Microcontroller**: The main controller, interpreting sensor data and managing control algorithms.
- **LEGO Technic Parts (45560)**: Essential building blocks of the bot's structure.
- **Ultrasonic and Infrared Sensors**: For distance measurement, navigation, and line-following tasks.
- **XL4016 Buck Converter**: Provides stable voltage for powering the Raspberry Pi.
- **Custom PCB**: Consolidates connections for efficient power and data handling.
- **DC Motors**: Provides propulsion and precision in movement.
- **3D Printed Parts**: Custom mounts for components, ensuring a secure setup.
- **Power Supply**: Batteries and voltage regulators to power all components reliably.

---

## 🔧 Assembly Instructions

### 🏗️ Chassis Structure

The bot's main frame is built using LEGO Technic parts from the 45560 set, providing a sturdy base for mounting all other components.

![Chassis Assembly](./images/01_chassis_structure.jpg)

### 🚗 Drive System

The drive system consists of DC motors connected to the wheels, providing the necessary propulsion and control for movement.

![Drive System](./images/02_drive_system.jpg)

### ⚡ Electronics and Power System

- **Power Module**: Supplies consistent power to the Raspberry Pi and motors.
- **Wiring**: Organized to ensure reliable connectivity and reduce interference.

![Electronics Setup](./images/03_electronics.jpg)

### 🔍 Sensors

Various sensors are strategically placed to provide the bot with spatial awareness, enabling obstacle avoidance, line tracking, and environmental data collection.

![Sensors Array](./images/04_sensors.jpg)

### 📸 Mounting the Raspberry Pi and Camera

The Raspberry Pi is securely mounted on the bot using custom 3D-printed parts, which also provide ventilation. The camera is positioned for optimal visibility and angle.

![Raspberry Pi and Camera Mount](./images/05_raspberry_camera.jpg)

---

## 💻 Software Setup

1. **Install Dependencies**:
   ```bash
   sudo apt update
   sudo apt install python3 python3-pip
   pip3 install -r requirements.txt
