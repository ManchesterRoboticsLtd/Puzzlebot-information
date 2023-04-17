/**
   \file DC_Motor_Control_Example.ino
   \author Eduard Codres, Mario Martinez
   \copyright Manchester Robotics Ltd.
   \date October, 2020
   \brief Example program controlling the speed of a motor.
*/

/**
   \brief Include the libraries to be used
*/
#include "MCR2_MotorDriver.h"
#include "MCR2_Encoder.h"
#include "MCR2_PIDController.h"

using namespace std;

/**
   \brief Define the MotorDriver, Encoder Pins and rotation sign 
    For ESP32 Motor Driver: PWMpin=4, Pin A=15, Pin B=18, Sign=[-1,1] // Encoder: PinA=34, PinB=36, Sign=[-1,1]
    For Arduino Motor Driver: PWMpin=2, Pin A=3, Pin B=4, Sign=[-1,1] // Encoder: PinA=18, PinB=19, Sign=[-1,1]
*/

#ifdef ESP32
  #define PWMpin 4
  #define pinA   15
  #define pinB   18
  #define motorSign -1

  #define encoderPinA 34
  #define encoderPinB 36
  #define encoderSign -1

#else
  #define PWMpin 2
  #define pinA   3
  #define pinB   4
  #define motorSign -1

  #define encoderPinA 18
  #define encoderPinB 19
  #define encoderSign -1

#endif

/**
   @defgroup motor_control Motor Control
   This group defines the global variables to configure the motors, encoders and controller
   @{
*/

/**
   \brief Motor Configuration Variables
*/
int motR_pins[3] = {PWMpin, pinA, pinB};     //Define the Motor Pins
int motR_sign = motorSign;                 //Define the motor rotation sign

/**
   \brief Encoder Configuration Variables
*/
int encoderR_pins[2] = {encoderPinA, encoderPinB};
float gear_ratio_r = 34;            //Define gear ratio
float encoderR_ticks = 48;          //Number of encoder ticks
int encoderR_sign = -1;             //Sign of the encoder velocity


/**
   \brief PID Controller Configuration Variables
*/
double Kp_R=0.050;                     //The Kp parameter of the pid controller
double Ti_R=0.08;                    //The Ti parameter of the pid controller
double Td_R=0;                       //The Td parameter of the pid controller
double uR_min=-1;                    //The lower limit of the controller output
double uR_max=1;                     //The upper limit of the controller output
float desired_R=0;
int flag=1;
double u=0;

/** @} end of motor_control*/

/**
   \brief Define set up functions and initialise Objects
*/
MotorDriver motor_R;
Encoder encoder_R;
PIDController PID_R;
void setupMotEnc();
void setupControl();

void setup() {
  setupMotEnc();
  setupControl();
  Serial.begin(115200);
}

void loop() {
  
float omega=350.0;
desired_R=10*sin(omega*millis()/1e6);                 //Set Point Definition
encoder_R.ReadSensors();                              // Read Encoders
u=PID_R.GetControl(desired_R,encoder_R.Get_Speed());  //Get Control
motor_R.MotorWrite(u);                                //Motor Write

Serial.print(desired_R);                              //Print the desired, open "Arduino Serial Plot" to see the results.
Serial.print("\t");
Serial.print(encoder_R.Get_Speed());
Serial.print("\n");

delay(100);
}


void setupMotEnc()
{
  //Setup the Motor Object
  motor_R.SetSign(motR_sign);                                            //Set up motor sign
  #ifdef ESP32
  motor_R.DriverSetup(motR_pins[0], 0, motR_pins[1], motR_pins[2]);      //Setup the motor pins (PWMpin, Pin A, Pin B)
  #else
  motor_R.DriverSetup(motR_pins[0], motR_pins[1], motR_pins[2]);         //Setup the motor pins (PWMpin, Pin A, Pin B)
  #endif
  motor_R.MotorWrite(0);                                                 //Write 0 velocity to the motor when initialising

  //Setup the Encoder Object
  encoder_R.SetTicksPerRev(encoderR_ticks);                              //Set the number of enconder pulses per revolution
  encoder_R.SetGearRatio(gear_ratio_r);                                  //Set the gear ratio
  encoder_R.SetSign(encoderR_sign);                                      //Set the encoder velocity sign
  encoder_R.Encoder_setup(encoderR_pins[0], encoderR_pins[1], 'R');      //Set encoder pins
}

void setupControl()
{
  //Setup the PID Control Object
  PID_R.SetParameters(Kp_R,Ti_R,Td_R);                                    //Set up the PID Parameters
  PID_R.SetControlLimits(uR_min,uR_max);                                  //Set control output Limits
}
