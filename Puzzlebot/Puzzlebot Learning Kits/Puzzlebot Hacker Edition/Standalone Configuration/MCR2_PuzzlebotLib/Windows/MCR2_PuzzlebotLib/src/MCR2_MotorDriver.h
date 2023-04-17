/**
   \file MotorDriver.h
   \author Eduard Codres, Mario Martinez, Zachary Madin
   \copyright Manchester Robotics
   \date March, 2019
   \brief MotorDriver class header file.
*/

#ifndef MCR2_MotorDriver_h
#define MCR2_MotorDriver_h

#include "Arduino.h"

/**
   \brief Motor class. Handles the speed of brushless or dc motors.
*/
class MotorDriver
{
  private:
    int PWMpin;          ///< pwm pin used to send signal to the driver
    int PinA;            ///< pin used for direction setting
    int PinB;            ///< pin used for direction setting
    int MotorBaseFreq;   ///< base freq of the brushless motor
    int Precision;       ///< precision of the pwm
    int Channel;         ///< pwm channel
    int sign;            ///< sign - determines if the motor rotates forwards or backwards
    
  public:
    /**
       \brief Constructor
    */
    MotorDriver();

     /**
       \brief sets motor rotation direction (forwards or backwards)
       \param sign motor sign
    */
    void SetSign(int sign);

    /**
       \brief Set the base frequency for the PWM
       \param BaseFreq base frequency used for the PWM Signal
    */
    void SetBaseFreq(int BaseFreq);

  #ifdef ESP32
    /**
       \brief Sets up the pins and pwm channel of the motor driver
       \param PWMpin the pwm pin of the motor
       \param Channel the pwm channel of the motor
       \param PinA PinA pin_a and pin_b for dc motor, direction pin for brushless motor
       \param PinB PinB pin_a and pin_b of the dc motor
    */
    void DriverSetup(int PWMpin, int Channel, int PinA, int PinB);
    /**
       \brief Write the pwm value to the motor driver
       \param PWM percentage (-1,1) value sent to the motor
    */
    void MotorWrite(float PWM);

  #else
    /**
       \brief Sets up the pins and pwm channel of the motor driver
       \param PWMpin the pwm pin of the motor
       \param Channel the pwm channel of the motor
       \param PinA PinA pin_a and pin_b for dc motor, direction pin for brushless motor
       \param PinB PinB pin_a and pin_b of the dc motor
    */
    void DriverSetup(int PWMpin, int PinA, int PinB);

    /**
       \brief Write the pwm value to the motor driver
       \param PWM percentage (-1,1) value sent to the motor
    */
    void MotorWrite(float PWM);

    #endif 
    
};

#endif
