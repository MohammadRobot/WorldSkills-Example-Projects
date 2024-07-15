#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Lidar360.h"
#include "gamepad/OI.h"

class LidarStartStop : public frc2::CommandHelper<frc2::CommandBase, LidarStartStop> 
{
    public:
        explicit LidarStartStop(Lidar360* lidar, OI* oi);

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private:
        Lidar360* lidar;
        OI* oi;
};