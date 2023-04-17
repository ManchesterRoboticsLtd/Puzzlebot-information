/**
 * \file Encoder.h
 * \author Eduard Codres, Mario Martinez
 * \copyright Manchester Robotics
 * \date March, 2019
 * \brief Encoder class header file.
 */

#ifndef MCR2_Encoder_h
#define MCR2_Encoder_h

#include "Arduino.h"

/** @defgroup enc_func Encoder functions
 *  This group contains encoder interrupt and parser functions (Encoder.h:684)
 *  @{
 */

/**
 * \brief Left dc motor encoder interrupt handler function for channel A
 */
void HandleLeftMotorInterruptA();
/**
 * \brief Left dc motor encoder interrupt handler function for channel B
 */
void HandleLeftMotorInterruptB();

/**
 * \brief Right dc motor encoder interrupt handler function for channel A
 */
void HandleRightMotorInterruptA();
/**
 * \brief Right dc motor encoder interrupt handler function for channel B
 */
void HandleRightMotorInterruptB();


/**
 * \brief Center dc motor encoder interrupt handler function for channel A
 */
void HandleCenterMotorInterruptA();
/**
 * \brief Center dc motor encoder interrupt handler function for channel B
 */
void HandleCenterMotorInterruptB();

/**
 * \brief Left encoder parser function.
 * 
 * Interprets digital signals from channel A and channel B of left encoder and outputs encoder ticks
 */
long ParseEncoder_L();

/**
 * \brief Right encoder parser function.
 * 
 * Interprets digital signals from channel A and channel B of right encoder and outputs encoder ticks
 */
long ParseEncoder_R();

/**
 * \brief Center encoder parser function.
 * 
 * Interprets digital signals from channel A and channel B of center encoder and outputs encoder ticks
 */
long ParseEncoder_C();

/** @} end of enc_func*/ 

/**
 * \brief Encoder class. Counts encoder pulses and computes the angular velocity.
 * 
 */
class Encoder
{
  float omega;                             ///< angular velocity of the encoder
  long tick_prev;                          ///< previous encoder tick index in the encoder_vec
  int sign;                                ///< sign - determines if the encoder rotates forwards or backwards
  long t_prev;                             ///< previous encoder read time (microseconds)
  volatile long int* EncoderTicks;         ///< pointer value updated by the interrupt function
  int ticks_rev;                           ///< ticks per revolution of the encoder
  float gear_ratio;                        ///< gear ratio of the motor
  int enc_dir;                             ///< used to store the estimated real encoder direction (not from the motor direction pin)

public:    
      
  /**
   * \brief Constructor
   */
  Encoder();

  /**
   * \brief setup method
   * \param pin1 first input pin of the encoder
   * \param pin2 second input pin of the encoder
   * \param selector selects right, left or center encoder
   */
  void Encoder_setup(int pin1,int pin2, char selector);

  /**
   * \brief reads the encoder value and computes angular velocity
   */
  void ReadSensors();

  /**
   * \brief sets the number of ticks of the encoder
   * \param n_ticks number of encoder ticks
   */
  void SetTicksPerRev(int n_ticks);

  /**
   * \brief sets the gear ratio of the motor
   * \param gear_ratio gear ratio
   */
  void SetGearRatio(float gear_ratio);

  /**
   * \brief sets encoder rotation direction (forwards or backwards)
   * \param sign encoder sign
   */
  void SetSign(int sign);

  /**
   * \brief get angular speed of the ecoder
   * \return the current angular speed
   */
  float Get_Speed();     
};


#endif
