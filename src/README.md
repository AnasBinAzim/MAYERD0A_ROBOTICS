#  Source Code :
<u>  </u>
### This contains the source code of the bot which includes opencv works and the arduino codes.
---

![arduino5804](https://github.com/user-attachments/assets/d3fc7745-01cd-43c3-9105-fc6b4c8bee38)


In the Future Engineers category of the World Robotics Olympiad (WRO), Arduino code is utilized to control and program robots for various tasks. Participants use Arduino boards to interface with sensors, motors, and other hardware components, allowing their robots to execute complex behaviors.

## Key Points:

Sensor Integration: Arduino code reads data from various sensors (e.g., ultrasonic, infrared) to enable the robot to perceive its environment.

Motor Control: Code is written to manage motor speed and direction, allowing robots to move accurately and respond to obstacles.

Autonomous Navigation: Teams program their robots to follow specific paths or navigate through challenges autonomously using algorithms.

Real-time Processing: Arduino's capabilities allow for real-time decision-making, essential for tasks requiring quick reactions to dynamic environments.

Customization: Participants can modify and optimize their code to improve performance, making the competition an excellent platform for learning and innovation in robotics.

Arduino's versatility and ease of use make it a popular choice for teams competing in the Future Engineers category.
<u> </u>

---

![Blog-Image-Template--71-](https://github.com/user-attachments/assets/8557bb37-24d6-4240-9ffe-e01ce5bc7632)
---

In the Future Engineers category of the World Robotics Olympiad (WRO), OpenCV (Open Source Computer Vision Library) plays a crucial role in object detection, particularly for identifying specific colors like green and red, as well as blue lines. Here’s how OpenCV facilitates these processes:

1. Color Space Conversion
OpenCV allows users to convert images from the RGB color space to other color spaces, such as HSV (Hue, Saturation, Value), which is more effective for color detection. In HSV, colors can be isolated more easily, making it simpler to identify green and red objects.
2. Color Thresholding
Using OpenCV, developers can set specific thresholds for the HSV values corresponding to green and red. This involves defining a range of hue, saturation, and value to create masks that highlight areas of the image that fall within these color ranges.
3. Contour Detection
Once the color mask is created, OpenCV can find contours in the masked image. This helps in identifying the shapes and locations of the detected green and red objects. Contours can be used to determine the size and position of the objects, aiding in further decision-making.
4. Hough Line Transform
For detecting blue lines, the Hough Line Transform is employed. After converting the image to grayscale and applying edge detection (like the Canny edge detector), the Hough Transform identifies straight lines in the image. This is particularly useful for tasks requiring path following or line detection in competitions.
5. Object Tracking
OpenCV provides functionalities to track the detected objects in real-time. This is essential for robots that need to follow or interact with specific colored objects or navigate along detected lines.
6. Integration with Robotics
The processed information can be integrated with the robot's control algorithms. For example, if a robot detects a red object or a blue line, it can be programmed to navigate toward it or perform specific actions based on its presence.
7. Efficiency and Speed
OpenCV is optimized for performance, allowing real-time processing, which is critical in dynamic competition settings where quick responses to color detection and line following can determine success.
By leveraging OpenCV for color detection and line detection, teams can enhance their robots' capabilities, making them more effective in tasks that require recognizing and reacting to specific colors and navigating paths, thus improving their chances of success in the competition.

---



![determining_object_color_featured](https://github.com/user-attachments/assets/0b1a72c6-f1ce-4f9b-ba7b-ba0572ac4da4)
