#include "commands/ManualDrive.h"

ManualDrive::ManualDrive(DriveTrain* driveTrain, Joystick* joystick)
{
    AddRequirements({driveTrain, joystick});
    m_subsystem_driveTrain = driveTrain;
    m_subsystem_joystick = joystick;
}

void ManualDrive::Initialize(){}

void ManualDrive::Execute()
{
    /**
     * Get Joystick Data
     */
    inputLeftY = m_subsystem_joystick->GetLeftDriveY(); 
    inputLeftX = m_subsystem_joystick->GetLeftDriveX();
    inputRightY = m_subsystem_joystick->GetRightDriveY();
    inputRightX = m_subsystem_joystick->GetRightDriveX();
    
    /**
     * Ramp
     */ 
    deltaLeftX = inputLeftX - prevLeftX;
    deltaLeftY = inputLeftY - prevLeftY;
    deltaRightX = inputRightX - prevRightX;
    deltaRightY = inputRightY - prevRightY;
    if(deltaLeftX >= DELTA_LIMIT)
        inputLeftX += RAMP_UP;
    else if (deltaLeftX <= -DELTA_LIMIT)
        inputLeftX -= RAMP_DOWN;
    if(deltaLeftY >= DELTA_LIMIT)
        inputLeftY += RAMP_UP;
    else if (deltaLeftY <= -DELTA_LIMIT)
        inputLeftY -= RAMP_DOWN;
    if(deltaRightX >= DELTA_LIMIT)
        inputRightX += RAMP_UP;
    else if (deltaRightX <= -DELTA_LIMIT)
        inputRightX -= RAMP_DOWN;
    if(deltaRightY >= DELTA_LIMIT)
        inputRightY += RAMP_UP;
    else if (deltaRightY <= -DELTA_LIMIT)
        inputRightY -= RAMP_DOWN;
    prevLeftY = inputLeftY;
    prevLeftX = inputLeftX;
    prevRightY = inputRightY;
    prevRightX = inputRightX;

    //train->HolonomicDrive(inputLeftX, -inputLeftY, inputRightX);
    m_subsystem_driveTrain->XBotMotorControl(inputLeftX, -inputLeftY, inputRightX);
}

void ManualDrive::End(bool interrupted)
{

    //train->HolonomicDrive(0, 0, 0);
    m_subsystem_driveTrain->XBotMotorControl(0, 0, 0);
}

bool ManualDrive::IsFinished()
{
    return false;
}