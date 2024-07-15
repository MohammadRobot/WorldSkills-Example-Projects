#include "subsystems/Joystick.h"


frc::Joystick drivePad(DRIVE_USB_PORT);

/**
 * @return the y-axis value from the drivePad right joystick
 */
double Joystick::GetRightDriveY(void)
{
    double joy = drivePad.GetRawAxis(RIGHT_ANALOG_Y);
    if(fabs(joy) < 0.05)
        return 0.0;
    else
        return joy;
}

/**
 * @return the x-axis value from the drivePad right joystick
 */
double Joystick::GetRightDriveX(void)
{
    double joy = drivePad.GetRawAxis(RIGHT_ANALOG_X);
    if(fabs(joy) < 0.05)
        return 0.0;
    else
        return joy;
}

/**
 * @return the y-axis value from the drivePad left joystick
 */
double Joystick::GetLeftDriveY(void)
{
    double joy = drivePad.GetRawAxis(LEFT_ANALOG_Y);
    if(fabs(joy) < 0.05)
        return 0.0;
    else
        return joy;
}

/**
 * @return the x-axis value from the drivePad left joystick
 */
double Joystick::GetLeftDriveX(void)
{
    double joy = drivePad.GetRawAxis(LEFT_ANALOG_X);
    if(fabs(joy) < 0.05)
        return 0.0;
    else
        return joy;
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveRightTrigger(void)
{
    return drivePad.GetRawButton(RIGHT_TRIGGER);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveRightBumper(void)
{
    return drivePad.GetRawButton(RIGHT_BUMPER);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::getDriveLeftTrigger(void)
{
    return drivePad.GetRawButton(LEFT_TRIGGER);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveLeftBumper(void)
{
    return drivePad.GetRawButton(LEFT_BUMPER);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveXButton(void)
{
    return drivePad.GetRawButtonPressed(X_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveSquareButton(void)
{
    return drivePad.GetRawButton(SQUARE_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveCircleButton(void)
{
    return drivePad.GetRawButton(CIRCLE_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveTriangleButton(void)
{
    return drivePad.GetRawButton(TRIANGLE_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveOptionsButton(void)
{
    return drivePad.GetRawButton(OPTIONS_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveShareButton(void)
{
    return drivePad.GetRawButton(SHARE_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveRightAnalogButton(void)
{
    return drivePad.GetRawButton(RIGHT_ANALOG_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveLeftAnalogButton(void)
{
    return drivePad.GetRawButton(LEFT_ANALOG_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDrivePS4Button(void)
{
    return drivePad.GetRawButton(PS4_BUTTON);
}

/**
 * @return a true or false depending on the input
 */
bool Joystick::GetDriveTouchpadButton(void)
{
    return drivePad.GetRawButton(TOUCHPAD_BUTTON);
}