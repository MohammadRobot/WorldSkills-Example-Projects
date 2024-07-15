#include "commands/CleaningPad.h"
#include "commands/robotCommands/Rotate.h"
#include <frc2/command/ParallelRaceGroup.h>


CleaningPad::CleaningPad(DriveTrain* drive)
{
    AddCommands
    (
        Rotate(drive).WithTimeout(15.0_s)
    );
}