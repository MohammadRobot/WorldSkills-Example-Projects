#include "commands/robotCommands/Rotate.h"

Rotate::Rotate(DriveTrain* drive) : drive{drive}
{
    AddRequirements({drive});
}

/**
 * Runs once when command is started
 */
void Rotate::Initialize()
{
    pid.SetTolerance(1.0);
    drive->ResetYaw();
}

/**
 * Called continously until command is ended
 */
void Rotate::Execute()
{
    drive->XBotMotorControl(0.0,
    0.0,
    std::clamp(pid.Calculate(drive->GetAngle(), setAngle), -0.5, 0.5));
}

/**
 * Called when the command is told to end or is interrupted
 */
void Rotate::End(bool interrupted)
{
    drive->XBotMotorControl(0.0, 0.0, 0.0);
}

/**
 * Creates an isFinished condition if needed
 */
bool Rotate::IsFinished()
{
    return pid.AtSetpoint();
}