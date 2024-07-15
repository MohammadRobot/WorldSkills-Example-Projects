/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoCommand.h"
#include "commands/Navigation.h"
#include <frc2/command/ParallelRaceGroup.h>


AutoCommand::AutoCommand(DriveTrain* driveTrain)
{
    AddCommands
    (
        Navigation(driveTrain).WithTimeout(60.0_s) // Timeout after 600.0_s = 10 min  
    );
}
