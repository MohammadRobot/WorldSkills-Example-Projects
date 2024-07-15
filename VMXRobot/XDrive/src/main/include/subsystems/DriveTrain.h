#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>
#include <frc/DigitalOutput.h>
#include "Constants.h"
#include "studica/TitanQuad.h"
#include "studica/TitanQuadEncoder.h"
#include "AHRS.h"
#include <math.h>
#include "studica/Lidar.h"


class DriveTrain : public frc2::SubsystemBase
{
    public:
        DriveTrain();
        void Periodic() override;
        double GetFrontLeftEncoder(void);
        double GetBackLeftEncoder(void);
        double GetFrontRightEncoder(void);
        double GetBackRightEncoder(void);
        double GetAverageEncoderY(void);
        void ResetEncoders(void);
        double GetYaw(void);
        double GetAngle(void);
        bool GetStartButton(void);
        bool GetStopButton(void);
        void SetRunningLED(bool on);
        void SetStoppedLED(bool on);
        void ResetYaw(void);
        void StackMotorControl(double x, double y);
        void TwoWheelMotorControl(double x, double y);
        void SixWheelMotorControl(double x, double y);
        void MecanumMotorControl(double x, double y, double z);
        void XBotMotorControl(double x, double y, double z);

        // Lidar
        void LidarStop(void);
        void LidarStart(void);
        bool lidarRunning = true;
        float frontLidarDistance[5];

    private:
        studica::TitanQuad frontLeftMotor{constant::TITAN_ID, constant::FRONT_LEFT_MOTOR};
        studica::TitanQuad backLeftMotor{constant::TITAN_ID, constant::BACK_LEFT_MOTOR};
        studica::TitanQuad frontRightMotor{constant::TITAN_ID, constant::FRONT_RIGHT_MOTOR};
        studica::TitanQuad backRightMotor{constant::TITAN_ID, constant::BACK_RIGHT_MOTOR};
        studica::TitanQuadEncoder frontLeftEncoder{frontLeftMotor, constant::FRONT_LEFT_MOTOR, constant::DIST_PER_TICK};
        studica::TitanQuadEncoder backLeftEncoder{backLeftMotor, constant::BACK_LEFT_MOTOR, constant::DIST_PER_TICK};
        studica::TitanQuadEncoder frontRightEncoder{frontRightMotor, constant::FRONT_RIGHT_MOTOR, constant::DIST_PER_TICK};
        studica::TitanQuadEncoder backRightEncoder{backRightMotor, constant::BACK_RIGHT_MOTOR, constant::DIST_PER_TICK};
        AHRS navX{frc::SPI::Port::kMXP};

        frc::DigitalInput startButton{constant::START_BUTTON};
        frc::DigitalInput stopButton{constant::E_STOP_BUTTON};
        frc::DigitalOutput runningLED{constant::RUNNING_LED};
        frc::DigitalOutput stoppedLED{constant::STOPPED_LED};

        // Lidar
        studica::Lidar lidar{studica::Lidar::Port::kUSB1};
        studica::Lidar::ScanData scanData;

        // Holonomic Variables
        double front_left = 0;
        double back_left = 0;
        double front_right = 0;
        double back_right = 0;
        double denomonator = 0;
};