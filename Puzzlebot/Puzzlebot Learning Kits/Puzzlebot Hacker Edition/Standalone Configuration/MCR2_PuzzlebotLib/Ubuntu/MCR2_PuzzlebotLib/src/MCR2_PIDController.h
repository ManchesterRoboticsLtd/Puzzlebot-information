/**
 * \file PIDController.h
 * \author Eduard Codres, Mario Martinez
 * \copyright Manchester Robotics
 * \date March, 2019
 * \brief PIDController class header file.
 */

#ifndef MCR2_PIDCONTROLLER_H
#define MCR2_PIDCONTROLLER_H
#include "Arduino.h"
#include "time.h"
//#include "iostream"


using namespace std;

/**
 * \brief PID class. Implements an incremental pid controller.
 */
class PIDController
{
  double u;                 ///< controller output
  double ek_0;              ///< error at current step
  double ek_1;              ///< error at step (k-1)
  double ek_2;              ///< error at step (k-2)
  double yk_0;              ///< system output at current step
  double yk_1;              ///< system output at step (k-1)
  double yk_2;              ///< system output at step (k-2)
  double Kp;                ///< pid Kp parameter
  double Ti;                ///< pid Ti parameter
  double Td;                ///< pid Td parameter
  double u_min;             ///< control output lower limit
  double u_max;             ///< control output higher limit
  double u_zero;            ///< control output zero value
  double dead_min;          ///< controller dead zone min limit
  double dead_max;          ///< controller dead zone max limit

  long start_mil, start_mic;
//  struct timeval start;     ///< start time structure. Used to measure samplin time.
  bool first;               ///< flag used to detect first time pid control is called

public:

  /**
   * \brief Constructor
   */
  PIDController();

  /**
   * \brief Sets the pid parameters
   * \param Kp the Kp parameter of the pid controller
   * \param Ti the ti parameter of the pid controller
   * \param Td the Td parameter of the pid controller
   */
  void SetParameters(double Kp,double Ti,double Td);

  /**
   * \brief Computes the control output of the pid controller
   * \param desired the current setpoint
   * \param system_ the curent output value of the system
   * \return the control output
   */
  double GetControl(double desired, double system_);

  /**
   * \brief Sets the control limits for the controller
   * \param u_min the lower limit of the controller output
   * \param u_max the higher limit of the controller output
   */
  void SetControlLimits(double u_min,double u_max);

  /**
   * \brief Sets the controller zero value (default: 0)
   * \param u_zero the controller zero value
   */
  void SetControlZero(double u_zero);

  /**
   * \brief Sets the controller dead zone
   * \param dead_min the dead zone lower limit
   * \param dead_max the dead zone higher limit
   */
  void SetDeadZone(double dead_min,double dead_max);
};



#endif // PIDCONTROLLER_H
