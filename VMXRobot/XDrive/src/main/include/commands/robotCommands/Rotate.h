#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

#include "subsystems/DriveTrain.h"
#include "RobotContainer.h"

class Rotate : public frc2::CommandHelper<frc2::CommandBase, Rotate>
{
    public:
        Rotate(DriveTrain* drive);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
        float setAngle;

    private: 
        DriveTrain* drive;
        
        double kP = 1;
        double kI = 0;
        double kD = 0;

        frc2::PIDController pid{kP, kI, kD};
};