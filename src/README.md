
#Thesecond round code is in WRO_int_2nd_finalV1.zip




# Source Code 🧑‍💻
This repository contains the core source code for **SMOKI**, our competition robot. It includes:

- **Arduino code** for motor and sensor control 🚗💡
- **OpenCV** implementation for color and line detection 🎨📸

---

<img src="https://github.com/user-attachments/assets/4d58a303-1fc4-4131-9e0a-257a0b3cafb1" alt="Arduino and SMOKI Setup" width="500"/>

### Arduino in Action 🛠️
In the **Future Engineers** category of the **World Robotics Olympiad (WRO)**, Arduino plays a vital role in controlling our robot's movements and interacting with the environment. Here's how we use it:

#### Key Features:
- **Sensor Integration**: Arduino reads from ultrasonic, infrared, and other sensors to help SMOKI perceive its surroundings. 📡
- **Motor Control**: It handles motor speed and direction, allowing for precise movement and obstacle avoidance. 🚗
- **Autonomous Navigation**: We implement path-following algorithms for SMOKI to navigate autonomously. 🤖
- **Customization**: Code optimizations enhance performance, improving SMOKI’s chances in the competition. ⚙️✨

---

<img src="https://github.com/user-attachments/assets/8557bb37-24d6-4240-9ffe-e01ce5bc7632" alt="OpenCV Color Detection" width="500"/>

### OpenCV & Color Detection 🎨
In **SMOKI**, **OpenCV** is used extensively for detecting objects and lines by color. Below are key processes and how they work in our robot:

1. **Color Space Conversion**: Convert RGB to HSV to isolate colors more effectively. 🌈
2. **Color Thresholding**: Identify specific color ranges (green, red, etc.) using masks. 🎯
3. **Contour Detection**: Find the shape and size of detected objects based on the masks. 🔍
4. **Hough Line Transform**: Used for blue line detection to navigate paths. 📏
5. **Object Tracking**: Real-time tracking of colors and lines, crucial for dynamic navigation. 🔄

---

<img src="https://github.com/user-attachments/assets/0b1a72c6-f1ce-4f9b-ba7b-ba0572ac4da4" alt="Object Color Detection" width="500"/>

By integrating Arduino and OpenCV, **SMOKI** is capable of advanced color detection and navigation, making it a strong contender in the WRO competition. 🚀

