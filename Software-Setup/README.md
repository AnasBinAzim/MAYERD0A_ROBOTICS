
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
