#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrain.h"
#include "subsystems/Joystick.h"

class ManualDrive : public frc2::CommandHelper<frc2::CommandBase, ManualDrive> 
{
    public:
        explicit ManualDrive(DriveTrain* driveTrain, Joystick* joystick);

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private:
        double inputLeftY = 0;
        double inputLeftX = 0;
        double inputRightY = 0;
        double inputRightX = 0;

        double deltaLeftY = 0;
        double deltaLeftX = 0;
        double deltaRightX = 0;
        double deltaRightY = 0;
        double prevRightX = 0;
        double prevRightY = 0;
        double prevLeftX = 0;
        double prevLeftY = 0;

        static constexpr double RAMP_UP = 0.05;

        static constexpr double RAMP_DOWN = 0.05;

        static constexpr double DELTA_LIMIT = 0.075;

        DriveTrain* m_subsystem_driveTrain;
        Joystick* m_subsystem_joystick;
};