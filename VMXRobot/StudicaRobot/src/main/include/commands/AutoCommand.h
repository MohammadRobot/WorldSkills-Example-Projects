/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrain.h"


/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCommand : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutoCommand> 
{
 public:
  /**
   * Creates a new AutoCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit AutoCommand(DriveTrain* driveTrain);

 private:
  DriveTrain* m_subsystem_driveTrain;
};
