/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer()
{
  drive.SetDefaultCommand(ManualDrive(&drive, &oi));
  

  //Add Commands to the auto chooser
  chooser.AddOption("Drive Lenght of Court", &m_lengthOfCourt);
  chooser.AddOption("Rotate", &m_cleaningPad);
  chooser.AddOption("Auto Command", &m_autoCmd);

  frc::Shuffleboard::GetTab("Autonomous Options").Add(chooser);

}

frc2::Command* RobotContainer::GetAutonomousCommand()
{
  return chooser.GetSelected();
}
