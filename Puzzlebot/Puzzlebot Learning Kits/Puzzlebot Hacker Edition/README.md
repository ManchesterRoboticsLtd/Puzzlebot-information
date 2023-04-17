
---

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://github.com/ManchesterRoboticsLtd/Puzzlebot/blob/main/Misc/Logos/NVIDIA_logo_BL.jpg">
  <source media="(prefers-color-scheme: light)" srcset="https://github.com/ManchesterRoboticsLtd/Puzzlebot/blob/main/Misc/Logos/NVIDIA_logo_WL.jpg">
  <img alt="Shows Puzzlebot logo in black or white." width="170" align="right">
</picture>

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://github.com/ManchesterRoboticsLtd/Puzzlebot/blob/main/Misc/Logos/MCR2_Logo_White.png">
  <source media="(prefers-color-scheme: light)" srcset="https://github.com/ManchesterRoboticsLtd/Puzzlebot/blob/main/Misc/Logos/MCR2_Logo_Black.png">
  <img alt="Shows MCR2 logo in black or white." width="150" align="right">
</picture>


<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://github.com/ManchesterRoboticsLtd/Puzzlebot/blob/main/Misc/Logos/Puzzle_Bot_Logo_W.png">
  <source media="(prefers-color-scheme: light)" srcset="https://github.com/ManchesterRoboticsLtd/Puzzlebot/blob/main/Misc/Logos/Puzzle_Bot_Logo_B.png">
  <img alt="Shows MCR2 logo in black or white." width="250" align="left">
</picture>



<br/><br/>
<br/><br/>

---

# Puzzlebot Hacker Edition

## Introduction

* The Puzzlebot Hacker Edition contains all the essential components needed to quickly access meaningful robotics capabilities and provides a user-friendly platform for incorporating a wide range of advanced add-on feature-sets.

<picture>
  <source srcset="https://user-images.githubusercontent.com/67285979/232492862-61075ee0-279a-492b-ad22-a90c67c861a8.png">
  <img alt="Shows Puzzlebot views in black or white." width="250" align="right">
</picture>

Puzzlebot, is powered by the *Hackerboard* for algorithms which require real-time processing capabilities, such as: 
  * Low level control 
  * Navigation 
  * Obstacle avoidance
  * 2D-LiDAR based SLAM
  * Fault tolerant control.

<br/><br/>  

## Basic Internal Diagram

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/67285979/232494892-2e2e8409-6c73-4c42-8883-155d9cab9b60.png">
  <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/67285979/232494720-39c1937a-e8b6-48ce-8809-e09511e2dfa7.png">
  <img alt="Shows Puzzlebot block diagram." width="800" align="center">
</picture>
   
## Configurations
  * The Puzzlebot can be used in differen configuration according to the user requirments.
 <br/><br/>

<picture>
  <source srcset="https://user-images.githubusercontent.com/67285979/232495809-decedd1e-ce71-4ef1-8145-8fd46377d412.png">
  <img alt="Shows Puzzlebot views in black or white." width="450" align="left">
</picture>

### Standalone configuration
  * The most basic configuration.
  * The user directly programs the Hackerbard using the Arduino IDE.
  * Libraries for control and communication with computing units, sensors, and actuators are provided by MCR2.
  * 3rd Party peripherals can be attached.
  * The user can develop low level control libraries, using MCR2 libraries or add/develop its own libraries.
  
#### Instructions
  * To use the Puzzlebot in this configuration, follow the instructions on how to Download and install the Arduino IDE [here]()
  * Download and configure the drivers for the ESP32 microcontroller [here]()
  * Download the MCR2 Puzzlebot Libraries [here]()
  * Look at the examples provided in the libraries [here]()
 
  <br/><br/>
  
<picture>
  <source srcset="https://user-images.githubusercontent.com/67285979/232502452-9d5edf07-9c88-4c72-926e-f2e51d8dfa11.png">
  <img alt="Shows Puzzlebot views in black or white." width="650" align="right">
</picture>

### External Control Configuration
* The robot is controlled from an external computer via Wi-Fi or Serial Communication.
* The internal firmware and libraries for communicating with the robot, its sensors and actuators are provided by MCR2.
* Basic web interface for configuring and testing provided.
* MATLAB and LabVIEW libraries for communicating with the robot are provided by MCR2.
* MATLAB and LabVIEW simulator are provided. No extra libraries for required.

### Instructions





