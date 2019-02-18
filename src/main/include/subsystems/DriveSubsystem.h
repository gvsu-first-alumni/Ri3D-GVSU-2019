#pragma once

#include "AHRS.h"
#include <frc/WPILib.h>
#include "commands/DriveCommand.h"
#include <rev/CANSparkMax.h>
#include <frc/commands/Subsystem.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>
#include <cmath>

class DriveSubsystem : public frc::Subsystem {
 public:
  DriveSubsystem();
  void InitDefaultCommand() override;
  void TankDrive(double left, double right);
  void Stop();
  AHRS* GetNavX();
  double GetHeading();
  void ResetHeading();
  int GetLeftEncoder();
  int GetRightEncoder();
  void ResetEncoders();
  void ResetPosition();
  void UpdatePosition();
  double GetX();
  double GetY();
  double GetLeftPosition();
  double GetRightPosition();

 private:
  rev::CANSparkMax frontLeft{6, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax backLeft{5, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax frontRight{3, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax backRight{4, rev::CANSparkMax::MotorType::kBrushless};
  frc::SpeedControllerGroup left{frontLeft, backLeft};
  frc::SpeedControllerGroup right{frontRight, backRight};
  frc::DifferentialDrive robotDrive{left, right};
  AHRS navX{frc::SPI::Port::kMXP};

  int leftOffset;
  int rightOffset;
  double headingOffset;
  double x;
  double y;
  int lastLeftValue;
  int lastRightValue;

  const double LIMITER = 0.95;
  const double TICKS_PER_INCH = 23.8;

  DriveCommand* driveCommand;
};
