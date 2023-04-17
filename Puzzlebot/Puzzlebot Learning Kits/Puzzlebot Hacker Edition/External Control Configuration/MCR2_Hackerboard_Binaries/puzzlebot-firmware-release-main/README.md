# Puzzlebot firmware

## 1. Features
The puzzlebot firmware implements functionality for handling sensors, actuators and communication for a ground mobile robot.
Currently, the software is designed to work on an espressif esp32 microcontroller. Developement and uploading is done using the **Arduino IDE**.

The existing functionality is detailed in the following.


Sensors:
 - encoders (Encoder class);
 - sonars (Sonar class);
 - reflectance sensors (ReflectanceSensor class);


Actuators:
 - dc motors and brushless motors (MotorDriver class);
 - servomotor (ServoMotor class);


Communication:
 - implementation of a peer to peer communication protocol. Used for direct communication over wifi with programs developped in  matlab, Labview, python, c++ etc (RobotServer class);
 - communication with robot operationg system - ROS (serial or wifi);
 - web server - implements communication with a web browser and allows setting, reading parameters and editing text files;
 - WiFi access point setup (RobotServer class);


Others:
 - incremental PID controler (PIDController class);
 - display support (Screen class);
 - loading config parameters from text files stored in the esp32 flash memory (RobotServer class);
 
 ## 2. Flashing the ESP32
Get latest binaries from https://github.com/codres-ali/puzzlebot-firmware/releases  
The firmware utilities allow for flashing the puzzlebot firmware and SPIFFS file system data on the ESP32 chip.

### Linux & MacOS

To flash the firmware and data to the PuzzleBot execute the following in a terminal:
```
./FirmwareFlash.sh
```
The script files are located in the */Linux* and *MacOS* folders respectively. it may be necessary to set permission to be executed in properties.

### Windows
To flash the firmware to the PuzzleBot run `FirmwareFlash.bat`.

The script files are located in the *Windows* folder from the downloaded binaries.
The script will attempt to locate all connected ESP32s and flash them one after the other. If the flash fails, ensure to disconnect all USB devices that except the PuzzleBot.


