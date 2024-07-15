/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "commands/ManualDrive.h"
#include "subsystems/DriveTrain.h"
#include "gamepad/OI.h"
#include "commands/DriveLengthOfCourt.h"
#include "commands/CleaningPad.h"
#include "commands/AutoCommand.h"



/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  
  //Subsystems
  DriveTrain drive;

 private:
  OI oi;
  //Commands
  DriveLengthOfCourt m_lengthOfCourt{&drive};
  CleaningPad m_cleaningPad{&drive};
  AutoCommand m_autoCmd{&drive};

  //Auto Chooser
  frc::SendableChooser<frc2::Command*> chooser;
};
