/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

//#include "commands/ExampleCommand.h"
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "commands/ManualDrive.h"
#include "commands/AutoCommand.h"
//#include "subsystems/Training.h"
#include "subsystems/Joystick.h"
#include "subsystems/DriveTrain.h"

//#include "subsystems/ExampleSubsystem.h"



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

 private:
  // The robot's subsystems and commands are defined here...
  //ExampleSubsystem m_subsystem;
  //ExampleCommand m_autonomousCommand;
  AutoCommand m_autoCommand{&m_subsystem_driveTrain};

  
  //Training m_subsystem_training;
  DriveTrain m_subsystem_driveTrain;
  Joystick m_subsystem_joystick;

  void ConfigureButtonBindings();
};
