/**
   \file DC Motor Encoder Example.ino
   \author Eduard Codres, Mario Martinez
   \copyright Manchester Robotics
   \date October, 2020
   \brief Example program for reading and writing motor velocities.
*/

/**
   \brief Include the libraries to be used
*/
#include "MCR2_Encoder.h"

/**
   \brief Define MotorEncoder Pins and rotation sign (EncoderPinA, EncoderPin B, Sign (-1,1))
    Arduino Pins: 18,19 / ESP32 pins 34,36
*/
#ifdef ESP32
   #define encoderPinA 34
   #define encoderPinB 36
   #define encoderSign -1
#else
   #define encoderPinA 18
   #define encoderPinB 19
   #define encoderSign -1
#endif

using namespace std;

/**
   \brief Encoder Configuration Variables
*/
int encoderR_pins[2] = {encoderPinA, encoderPinB};    // Encoder Pins [EncoderA, EncoderB]
float gear_ratio_r = 34;                              //Define gear ratiov(Puzzlebot=34)
float encoderR_ticks = 48;                            //Number of encoder ticks (Puzzlebot=48)
int encoderR_sign = encoderSign;                      //Sign of the encoder velocity

/**
   \brief Define setup functions and initialise Objects
*/
Encoder encoder_R;
void setupEnc();

void setup()
{
  setupEnc();
  Serial.begin(115200);
}

void loop()
{
  encoder_R.ReadSensors();                       //Read the Encoders
  Serial.print(encoder_R.Get_Speed());           //Serial print the motor velocities
  Serial.print("\n");
  delay(30);                                     //Delay before next loop iteration
}

void setupEnc()
{
  /**
    \brief Setup the Encoder Object
  */
  encoder_R.SetTicksPerRev(encoderR_ticks);                              //Set the number of enconder pulses per revolution
  encoder_R.SetGearRatio(gear_ratio_r);                                  //Set the gear ratio
  encoder_R.SetSign(encoderR_sign);                                      //Set the encoder velocity sign
  encoder_R.Encoder_setup(encoderR_pins[0], encoderR_pins[1], 'R');      //Set encoder pins
}
