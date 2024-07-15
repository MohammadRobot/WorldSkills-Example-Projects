#include "commands/robotCommands/DriveWithPID.h"

DriveWithPID::DriveWithPID(DriveTrain* drive, double setPointX, double setPointY, double setPointZ, double epsilonX, double epsilonY, double epsilonZ) : drive{drive}, setPointX{setPointX}, setPointY{setPointY}, setPointZ{setPointZ}, epsilonX{epsilonX}, epsilonY{epsilonY}, epsilonZ{epsilonZ} 
{
    AddRequirements({drive});
}

/**
 * Runs once when command is started
 */
void DriveWithPID::Initialize()
{
    pidX.SetTolerance(epsilonX);
    pidY.SetTolerance(epsilonY);
    pidZ.SetTolerance(epsilonZ);
    drive->ResetEncoders();
}

/**
 * Called continously until command is ended
 */
void DriveWithPID::Execute()
{
    drive->XBotMotorControl(0.0,
    std::clamp(pidY.Calculate(drive->GetAverageEncoderY(), setPointY), -0.5, 0.5),
    std::clamp(pidZ.Calculate(drive->GetYaw(), setPointZ), -0.5, 0.5));
}

/**
 * Called when the command is told to end or is interrupted
 */
void DriveWithPID::End(bool interrupted)
{
    drive->XBotMotorControl(0.0, 0.0, 0.0);
}

/**
 * Creates an isFinished condition if needed
 */
bool DriveWithPID::IsFinished()
{
    return pidY.AtSetpoint();
}