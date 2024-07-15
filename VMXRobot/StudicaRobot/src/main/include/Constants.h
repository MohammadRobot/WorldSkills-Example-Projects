/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a goo d idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#define _USE_MATH_DEFINES
#include <math.h>

namespace constant
{
    //Motors
    static constexpr int TITAN_ID             = 42;
    static constexpr int FRONT_LEFT_MOTOR     = 2;
    static constexpr int BACK_LEFT_MOTOR      = 3;
    static constexpr int FRONT_RIGHT_MOTOR    = 0;
    static constexpr int BACK_RIGHT_MOTOR     = 1;

    //Encoder
    static constexpr double WHEEL_RADIUS    = 51; //mm
    static constexpr double PULSE_PER_REV   = 1464;
    static constexpr double GEAR_RATIO      = 1/1;
    static constexpr double ENCODER_PULSE_RATIO = PULSE_PER_REV * GEAR_RATIO;
    static constexpr double DIST_PER_TICK   =   (M_PI * 2 * WHEEL_RADIUS) / ENCODER_PULSE_RATIO;

    //Inputs
    static constexpr int START_BUTTON   = 9;
    static constexpr int E_STOP_BUTTON    = 11;

    //Outputs
    static constexpr int RUNNING_LED    = 20;
    static constexpr int STOPPED_LED    = 21;
}