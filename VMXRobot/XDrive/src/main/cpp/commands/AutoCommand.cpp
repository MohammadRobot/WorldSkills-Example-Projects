#include "commands/AutoCommand.h"
#include "commands/Navigation.h"
#include <frc2/command/ParallelRaceGroup.h>

AutoCommand::AutoCommand(DriveTrain* drive)
{
    AddCommands
    (
        Navigation(drive).WithTimeout(10.0_s) // Timeout after 10 min
    );
}