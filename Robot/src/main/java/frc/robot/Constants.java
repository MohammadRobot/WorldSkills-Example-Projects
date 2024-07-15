/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot;

/**
 * The Constants class provides a convenient place for teams to hold robot-wide numerical or boolean
 * constants.  This class should not be used for any other purpose.  All constants should be
 * declared globally (i.e. public static).  Do not put anything functional in this class.
 *
 * <p>It is advised to statically import this class (or one of its inner classes) wherever the
 * constants are needed, to reduce verbosity.
 */
public final class Constants {
        /**
     * Motor Constants
     */
    public static final int TITAN_ID    = 42;
    public static final int M0          = 0;
    public static final int M1          = 1;
    public static final int M2          = 2;
    public static final int M3          = 3;

    public static final int SERVO           = 0;
    public static final int SERVO_C         = 1;


    /**
     * Sensors
     */
    public static final int SHARP           = 0;
    public static final int SONIC_TRIGG     = 8;
    public static final int SONIC_ECHO      = 9;

    /**
     * Encoder Constants
     */

    //Radius of Wheel
    private static final double wheelRadius  = 51; //mm / change to 2.00787 for inches

    //Encoder pulses per revolution
    private static final double pulsePerRevolution = 1440;

    //Gear ratio between encoder and wheel
    private static final double gearRatio            = 1/1; //Wheel on motor shaft

    //Pulse per revolution of the wheel
    private static final double encoderPulseRatio    = pulsePerRevolution * gearRatio;

    //Distance per tick
    public static final double DIST_PER_TICK        = (Math.PI * 2 * wheelRadius) / encoderPulseRatio;
}
