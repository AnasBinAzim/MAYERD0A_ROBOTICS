# Mayerdoa Robotics Future Engineers Documentation 2024: Smoki Project Overview
----
<div align="center">
  <img src="https://github.com/user-attachments/assets/08601b9d-fa28-4cfd-aa6c-960e2666ef5a" alt="bot" width="300" />
</div>

### This repository is a collection of engineering materials related to SMOKI, a self-driving vehicle model developed by Team MAYERDOA_ROBOTICS, participating in the 2024 WRO National Final (Future Engineers) from BANGLADESH.
----

## Team Members:
> Anas Bin Azim, email: anas.azim.71@gmail.com

> Rakibul Islam - email:

> Mohiuddin Sami - email:

----

## Overview of our Repository

 * `models` - the 3D printable files used in our robot.
 * `getting started` - getting started guide.
 * `src` - contains the main code of our robot.
 * `video` - contains the video link of YouTube where our robot can be seen in action.
 * `t-photos` - contains one serious and one funny photo of our team.
 * `v-photos` - contains the photos of the robot from all required directions.
 * `others` - other essential photos.

----

## Mechanical Design

### Mechanical Parts List
* M3 Nut 3mm – 10 pcs
* M3 15mm – 12 pcs
* M2 Nut – 10 pcs
* 35.5 mm Red Female-to-Female Round Spacer – 4 pcs
* 30 mm Male-to-Female Hex Spacer – 4 pcs
* 15 mm Male-to-Female Hex Spacer – 3 pcs
* Bearing

----

## Robot's Chassis

The chassis of the SMOKI self-driving vehicle is designed to integrate innovative mechanical and electrical components, ensuring both functionality and aesthetic appeal. This section highlights the key features of the chassis, including the Ackermann steering system, babble gear, 3D printed body, and sonar mounts.


### Ackermann Steering System

![Ackermann-steering-mechanism-This-is-the-diagram-for-the-Ackermann-steering-mechanism](https://github.com/user-attachments/assets/5f9959c6-4502-4eab-a4da-55fe32c69f43)



---

The **Ackermann steering system** is a crucial feature of the SMOKI chassis, designed to enhance maneuverability and reduce tire wear during turns. This steering mechanism allows the inner front wheel to turn at a larger angle than the outer wheel, ensuring that both wheels follow a common turning radius. This configuration minimizes tire scrubbing and improves handling, particularly in tight corners. The design is based on a modified four-bar linkage that optimally aligns the wheels with the center of the turning radius, providing smooth navigation and stability at various speeds.

### Bevel Gear
<u> </u>
![BEVELGEAR](https://github.com/user-attachments/assets/43fb031e-52ba-4e7a-ab7d-bf6c4b74763a)

---




Incorporating **bevel gear** into the chassis enhances the vehicle's ability to manage torque and speed efficiently. This gear system allows for precise control over movement, enabling quick adjustments during operation. The design of bevel gears contributes to a compact structure while maintaining strength, making it ideal for robotic applications where agility and responsiveness are paramount.

### 3D Printed Body

The **3D printed body** of SMOKI not only adds to its aesthetic appeal but also allows for customization in design and functionality. The use of advanced 3D printing techniques enables the creation of complex shapes that traditional manufacturing methods cannot achieve. This flexibility in design helps optimize weight distribution and structural integrity while providing a modern look that aligns with the innovative spirit of robotics.

### Sonar Mounts

The integration of **sonar mounts** is another significant aspect of the chassis design. These mounts are strategically positioned to enhance sensor performance, allowing for better obstacle detection and navigation capabilities. By optimizing the placement of sonar sensors, SMOKI can achieve improved handling and responsiveness in dynamic environments. The aesthetic integration of these mounts into the chassis design ensures that functionality does not compromise visual appeal.

## Conclusion

The SMOKI robot chassis exemplifies a harmonious blend of advanced engineering principles and modern design aesthetics. The combination of an Ackermann steering system, babble gear, 3D printed body, and well-placed sonar mounts creates a robust platform for autonomous operation while ensuring an appealing visual presentation. This thoughtful integration reflects Team MAYERDOA_ROBOTICS' commitment to innovation in robotics as they prepare for the 2024 WRO National Final from Bangladesh.

----

## Electrical Design of Our Robot

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

----

## Power Delivery and Optimization

* ## Power Delivery and Optimization ⚡🔋 *

In the SMOKI project, efficient power delivery and optimization are paramount to ensure that all components operate reliably and effectively. Our design utilizes advanced voltage conversion techniques to meet the specific power requirements of various systems within the robot.
---

### Voltage Conversion with LM4016 Buck Converter 🔽

To convert our battery voltage from **8.4 volts** to **5 volts**, we employed an **LM4016-based 10 amp buck converter**. This step-down converter is essential for powering our main microcontroller, Raspberry Pi, and other components that require a stable 5V supply. The Raspberry Pi, in particular, demands between **5 to 6 amps** at 5V, making it crucial for us to implement a robust power solution. The LM4016 not only ensures efficient voltage regulation but also minimizes energy loss, allowing our system to operate smoothly and efficiently.
---

### MT3608 Boost Converter for Motor Power 🔼
For powering the motors, we integrated an MT3608 boost converter, which steps up the voltage to 14V DC. This converter is vital for delivering the necessary current to drive the motors effectively while maintaining performance under varying load conditions. The ability of the MT3608 to provide stable output at higher voltages ensures that our motors can function optimally, enhancing the overall performance of the SMOKI vehicle.
---

### Raspberry Pi and Camera Integration 📷
Additionally, our Raspberry Pi is responsible for powering the onboard camera, which plays a critical role in navigation and obstacle detection. By utilizing these optimized power delivery methods, we can ensure that all components receive the appropriate voltage and current they require for seamless operation.
---

### Conclusion 🌟
The careful selection of power delivery components such as the LM4016 buck converter and MT3608 boost converter reflects our commitment to creating a reliable and efficient robotic system. These optimizations not only enhance performance but also contribute to the longevity of the SMOKI project as we prepare for the challenges of the 2024 WRO National Final from Bangladesh.

## Debugging

----
----
----





----
----
----
