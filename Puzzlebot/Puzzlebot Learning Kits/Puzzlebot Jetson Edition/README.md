
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

# Puzzlebot: NVIDIA JETSON® Edition
The Puzzlebot NVIDIA JETSON® Edition is an extension of the Puzzlebot Hacker Edition encompassing an NVIDIA Jetson® CPU, and a Raspberry Pi® Camera . Combining 
the power of the Hacker Board and the NVIDIA JETSON Nano®, allows users to implement research-level, real-time algorithms such as AI & Computer Vision, SLAM and 
autonomous driving algorithms using ROS.

The Puzzlebot NVIDIA JETSON® Edition works by communicating the Hacker Board (Plug and play) with the NVIDIA Jetson Nano®.

## Configurations
### Puzzlebot-ROS Connection: Classic 
* The user can develop advanced robotic algorithms in ROS (Robot Operating System) using the computing power of the NVIDIA Jetson Nano® and communicate to the actuators and sensors using the Hackerboard.
* The Hackerboard and NVIDIA Jetson Nano® are connected via Serial (Communication Libraires with Hackerboard, Sensors and Actuators, provided by MCR2).

<p align="center" >
  <img src="https://user-images.githubusercontent.com/67285979/232561765-37fca598-47e8-42e2-9311-81f41b370af2.png"  width="600"/>
</p>


### Puzzlebot-ROS Connection: Client
* In tis configuration, the user can connect to the NVIDIA Jetson Nano®, to monitor the functionality of the robot, monitor or control a process or simply control the robot wirelessly.
* This configuration works as the previous one, with the difference that in this case the user can connect to the External computing unit (ROS Master) via Wi-Fi.
* The ROS Master node is running in the NVIDIA Jetson Nano® making this a suitable combination for Advanced Distributed Control.

<p align="center" >
  <img src="https://user-images.githubusercontent.com/67285979/232562266-45612e47-63ae-435e-864b-96a582913820.png"  width="700"/>
</p>

## Latest Hackerboard Binaries
  * Use the latest hackerboard Binaries in the folder *MCR2_Hackerboard_Binaries*

## NVIDIA Jetson Nano Image
 * Download the NVIDIA Jetson Nano Image [here](https://manchesterrobotics-my.sharepoint.com/personal/rebeca_manchester-robotics_com/_layouts/15/onedrive.aspx?id=%2Fpersonal%2Frebeca%5Fmanchester%2Drobotics%5Fcom%2FDocuments%2Fpuzzlebot%2D003%2Dnano%2D2gb%2Djp46%2Ezip&parent=%2Fpersonal%2Frebeca%5Fmanchester%2Drobotics%5Fcom%2FDocuments&ga=1)
 * Use the Balena Etcher to flash the image [here](https://www.balena.io/etcher)
     
