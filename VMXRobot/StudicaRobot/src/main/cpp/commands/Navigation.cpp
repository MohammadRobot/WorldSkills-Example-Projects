#include "commands/Navigation.h"

Navigation::Navigation(DriveTrain* driveTrain) : m_subsystem_driveTrain{driveTrain}
{
    AddRequirements({driveTrain});
}

void Navigation::Initialize()
{
    m_subsystem_driveTrain->SetRunningLED(true);
    m_subsystem_driveTrain->ResetYaw();
    sequence = 1;
}

void Navigation::Execute()
{ 
    if (sequence == 1 && m_subsystem_driveTrain->frontLidarDistance[0]> 500){
         m_subsystem_driveTrain->XBotMotorControl(0.0, 0.2, 0.0); // Move forward at 20%
    } else if (sequence == 1 && m_subsystem_driveTrain->frontLidarDistance[0]< 500){
        sequence = 2;
    }else if (sequence == 2 && m_subsystem_driveTrain->GetYaw() < 90){
        m_subsystem_driveTrain->XBotMotorControl(0.0, 0.0, 0.2); // Turn Robot
    }else if (sequence == 2 && m_subsystem_driveTrain->GetYaw() > 90){
        sequence = 1;
        m_subsystem_driveTrain->ResetYaw();
        m_subsystem_driveTrain->XBotMotorControl(0.0, 0.0, 0.0); // Stop
    }else{
        sequence = 0;
        m_subsystem_driveTrain->SetRunningLED(false);
        m_subsystem_driveTrain->XBotMotorControl(0.0, 0.0, 0.0); // Stop
    }
    
}

void Navigation::End(bool interrupted)
{
    m_subsystem_driveTrain->XBotMotorControl(0.0, 0.0, 0.0); // Stop
}

bool Navigation::IsFinished()
{
    // if (m_subsystem_driveTrain->frontLidarDistance[0]< 50)
    //     return true;
    // else
        return false;
}