/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include <frc/Timer.h>

#include "subsystems/DriveSubsystem.h"
#include "subsystems/VisionSystem.h"
#include "libraries/FangvPIDController.h"

class AlignHatch : public frc::Command {
 public:
  AlignHatch();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
private:
  std::shared_ptr<DriveSubsystem> m_drive;
  std::shared_ptr<Camera::AligmentCamera> m_vision;

  FangvPIDController m_pid{100, -100, 0.0, 0.0, 0.0, 0};
  frc::Timer m_timer;
  double m_timestamp;
  bool m_tolerable;
};