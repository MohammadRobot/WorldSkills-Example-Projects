#include "subsystems/DriveTrain.h"

#define DEBUG true

DriveTrain::DriveTrain()
{
    ResetEncoders();
    ResetYaw();

    //Motor Invert flags
    frontLeftMotor.SetInverted(false);
    backLeftMotor.SetInverted(false);
    frontRightMotor.SetInverted(true);
    backRightMotor.SetInverted(true);

    //Motor Invert Flags comment out when needed
    //frontLeft.InvertRPM();
    // frontLeftEncoder.SetReverseDirection();

    //backLeft.InvertRPM();
    // backLeftEncoder.SetReverseDirection();

    //frontRight.InvertRPM();
    //frontRightEncoder.SetReverseDirection();

    //backRight.InvertRPM();
    //backRightEncoder.SetReverseDirection();
}

double DriveTrain::GetYaw()
{
    return navX.GetYaw();
}

double DriveTrain::GetAngle()
{
    return navX.GetAngle();
}

void DriveTrain::ResetYaw()
{
    navX.ZeroYaw();
}

bool DriveTrain::GetStartButton()
{
    return startButton.Get();
}

bool DriveTrain::GetStopButton()
{
    return stopButton.Get();
}

void DriveTrain::SetRunningLED(bool on)
{
    runningLED.Set(on);
}

void DriveTrain::SetStoppedLED(bool on)
{
    stoppedLED.Set(on);
}

void DriveTrain::LidarStop()
{
    // if (!lidarRunning)
    // {
    //     lidar.Start();
    //     lidarRunning = true;
    // }
}

void DriveTrain::LidarStart()
{
    // if (lidarRunning)
    // {
    //     lidar.Stop();
    //     lidarRunning = false;
    // }
}

void DriveTrain::StackMotorControl(double x, double y)
{
    frontLeftMotor.Set(y + x);
    backLeftMotor.Set(y + x);
    frontRightMotor.Set(y - x);
    backRightMotor.Set(y - x);
}

void DriveTrain::TwoWheelMotorControl(double x, double y)
{
    frontLeftMotor.Set(y + x);
    frontRightMotor.Set(y - x);
}

void DriveTrain::SixWheelMotorControl(double x, double y)
{
    frontLeftMotor.Set(y + x);
    backLeftMotor.Set(y + x);
    frontRightMotor.Set(y - x);
    backRightMotor.Set(y - x);
}

void DriveTrain::MecanumMotorControl(double x, double y, double z)
{
    denomonator = fmax(fabs(y) + fabs(x) + fabs(z), 1.0);
    frontLeftMotor.Set(y + (x) + z / denomonator);
    backLeftMotor.Set(y - (x) + z / denomonator);
    frontRightMotor.Set(y - (x) - z / denomonator);
    backRightMotor.Set(y + (x) - z / denomonator);
}

void DriveTrain::XBotMotorControl(double x, double y, double z)
{
    denomonator = fmax(fabs(y) + fabs(x) + fabs(z), 1.0);
    frontLeftMotor.Set(y + (x) + z / denomonator);
    backLeftMotor.Set(y - (x) + z / denomonator);
    frontRightMotor.Set(y - (x) - z / denomonator);
    backRightMotor.Set(y + (x) - z / denomonator);
}

void DriveTrain::Periodic()
{
    if (lidarRunning){
        scanData = lidar.GetData(); // Update scanData struct
        
        for (int i=0 ; i<5;i++){
            if (scanData.distance[268+i] > 10.0){
                frontLidarDistance[i] = scanData.distance[268+i];
            }else
            {
                frontLidarDistance[i] = 5000;
            }
        }
        int n = sizeof(frontLidarDistance) / sizeof(frontLidarDistance[0]);
        std::sort(frontLidarDistance,frontLidarDistance + n);
    }

    #if DEBUG
        frc::SmartDashboard::PutNumber("Yaw", GetYaw());
        frc::SmartDashboard::PutNumber("Angle", GetAngle());
        // frc::SmartDashboard::PutNumber("Front Left Encoder", GetFrontLeftEncoder());
        // frc::SmartDashboard::PutNumber("Back Left Encoder", GetBackLeftEncoder());
        // frc::SmartDashboard::PutNumber("Front Right Encoder", GetFrontRightEncoder());
        // frc::SmartDashboard::PutNumber("Back Right Encoder", GetBackRightEncoder());
        // frc::SmartDashboard::PutNumber("Front Left RPM", frontLeft.GetRPM());
        // frc::SmartDashboard::PutNumber("Back Left RPM", backLeft.GetRPM());
        // frc::SmartDashboard::PutNumber("Front Right RPM", frontRight.GetRPM());
        // frc::SmartDashboard::PutNumber("Back Right RPM", backRight.GetRPM());
        frc::SmartDashboard::PutBoolean("Start Button", startButton.Get());
        frc::SmartDashboard::PutBoolean("Stop Button", stopButton.Get());
        frc::SmartDashboard::PutBoolean("Lidar", lidarRunning);
        frc::SmartDashboard::PutNumber("Front Distance", frontLidarDistance[0]);
    #endif
}




////
//Encoders 
////////////////////////////

void DriveTrain::ResetEncoders()
{
    frontLeftEncoder.Reset();
    backLeftEncoder.Reset();
    frontRightEncoder.Reset();
    backRightEncoder.Reset();
}


double DriveTrain::GetFrontLeftEncoder()
{
    return frontLeftEncoder.GetEncoderDistance();
}

double DriveTrain::GetBackLeftEncoder()
{
    return backLeftEncoder.GetEncoderDistance();
}

double DriveTrain::GetFrontRightEncoder()
{
    return frontRightEncoder.GetEncoderDistance();
}

double DriveTrain::GetBackRightEncoder()
{
    return backRightEncoder.GetEncoderDistance();
}

double DriveTrain::GetAverageEncoderY()
{
    return (((GetFrontLeftEncoder() + GetBackLeftEncoder()) / 2) + ((GetFrontRightEncoder() + GetBackRightEncoder()) / 2)) / 2;
}

