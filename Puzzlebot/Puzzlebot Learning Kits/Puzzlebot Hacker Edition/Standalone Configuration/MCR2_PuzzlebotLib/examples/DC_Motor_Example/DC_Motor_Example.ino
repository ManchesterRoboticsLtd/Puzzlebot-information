/**
   \file DC_Motor_Example.ino
   \author Eduard Codres, Mario Martinez
   \copyright Manchester Robotics Ltd.
   \date October, 2020
   \brief Example program for regulating the speed of a motor by sending PWM signal to a Motor Driver, to be used in the Hackerboard or a simple H bridge (L298).
*/

/**
   \brief Include the libraries to be used
*/
#include <MCR2_MotorDriver.h>

/**
   \brief Define the MotorDriver Pins and rotation sign (PWMpin, Pin A, Pin B, Sign (-1,1))
    Arduino Pins: 2,3,4 / ESP32 pins 4,15,18
*/
#ifdef ESP32
  #define PWMpin 4
  #define pinA   15
  #define pinB   18
  #define motorSign -1
#else
  #define PWMpin 2
  #define pinA   3
  #define pinB   4
  #define motorSign -1
#endif

/**
   \brief Motor Configuration Variables
*/
int motR_pins[3] = {PWMpin, pinA, pinB};     //Define the Motor Pins
int motR_sign = motorSign;                 //Define the motor rotation sign

/**
   \brief Define set up functions and initialise Objects
*/
MotorDriver motor_R;
void setupMot();

using namespace std;

void setup()
{
  setupMot();
  Serial.begin(9600);
}

//Loop
void loop()
{
  for (float fadeValue = -1 ; fadeValue <= 1; fadeValue += 0.01) {    //Increase the motor velocity from -1 to 1 (-100% to 100%)
    motor_R.MotorWrite(fadeValue);                                    //Set Velocity percentage to the Motors (-1 to 1)
    Serial.println(fadeValue);  
    delay(30);
  }

  for (float fadeValue = 1 ; fadeValue >= -1; fadeValue -= 0.01) {    //Fade Motor velocity from 1 to -1 (100% to -100%)
    motor_R.MotorWrite(fadeValue);
    delay(30);
    Serial.println(fadeValue);
  }

}

void setupMot()
{
  /**
     \brief Setup the Motor Object
  */
  motor_R.SetSign(motR_sign);                                            //Set up motor sign
#ifdef ESP32
  motor_R.DriverSetup(motR_pins[0], 0, motR_pins[1], motR_pins[2]);      //Setup the motor pins (PWMpin, Pin A, Pin B)
#endif
#else
  motor_R.DriverSetup(motR_pins[0], motR_pins[1], motR_pins[2]);         //Setup the motor pins (PWMpin, Pin A, Pin B)
#endif
  motor_R.MotorWrite(0);                                                 //Write 0 velocity to the motor when initialising

}
