/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <memory>
#include <frc/WPILib.h>
#include <mutex>

#include "OI.h"
#include "commands/ExampleCommand.h"
#include "commands/MyAutoCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/CameraSubsystem.h"
#include "subsystems/ClawSubsystem.h"
#include "subsystems/VisionSystem.h"
#include "subsystems/HopScotchSubssytem.h"

class Robot : public frc::TimedRobot {
 public:
  static std::shared_ptr<ExampleSubsystem> m_subsystem;
  static std::shared_ptr<DriveSubsystem> driveSubsystem;
  static std::shared_ptr<Camera::CameraSubsystem> m_cameraSubsystem;
  static std::shared_ptr<Claw::ClawSubsystem> m_clawSubsystem;
  static std::shared_ptr<Camera::AligmentCamera> m_visionSubsystem;
  static std::shared_ptr<HopScotchSubsystem> m_hopscotchSubsystem;
  static OI m_oi;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc::Command* m_autonomousCommand = nullptr;
  ExampleCommand m_defaultAuto;
  MyAutoCommand m_myAuto;
  frc::SendableChooser<frc::Command*> m_chooser;
  static void VisionThread();
};
