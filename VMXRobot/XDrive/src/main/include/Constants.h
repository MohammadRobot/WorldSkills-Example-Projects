/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
namespace constant
{
    /**
     * Motors
     */
    static constexpr int TITAN_ID           = 42; // Titan CAN ID
    static constexpr int FRONT_LEFT_MOTOR   = 2;  // M0
    static constexpr int FRONT_RIGHT_MOTOR  = 0;  // M1
    static constexpr int BACK_LEFT_MOTOR    = 3;  // M2
    static constexpr int BACK_RIGHT_MOTOR   = 1;  // M3

    //Encoder
    static constexpr double WHEEL_RADIUS    = 51; //mm
    static constexpr double PULSE_PER_REV   = 1464;
    static constexpr double GEAR_RATIO      = 1/1;
    static constexpr double ENCODER_PULSE_RATIO = PULSE_PER_REV * GEAR_RATIO;
    static constexpr double DIST_PER_TICK   =   (M_PI * 2 * WHEEL_RADIUS) / ENCODER_PULSE_RATIO;

    /**
     * Digital I/O
     */
    static constexpr int START_BUTTON       = 9;  // Digital Input 9
    static constexpr int E_STOP_BUTTON      = 11; // Digital Input 11
    static constexpr int RUNNING_LED        = 20; // Digital Output 20
    static constexpr int STOPPED_LED        = 21; // Digital Output 21
}
