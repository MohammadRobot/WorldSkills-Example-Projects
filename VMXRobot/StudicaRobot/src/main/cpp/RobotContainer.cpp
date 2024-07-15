/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() 
{
  // Initialize all of your commands and subsystems here
  
  //m_subsystem_training.SetDefaultCommand(ManualDrive(&m_subsystem_training, &m_subsystem_oi));
  m_subsystem_driveTrain.SetDefaultCommand(ManualDrive(&m_subsystem_driveTrain, &m_subsystem_joystick));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autoCommand;
}
