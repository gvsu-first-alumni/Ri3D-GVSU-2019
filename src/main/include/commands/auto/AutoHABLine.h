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


class AutoHABLine : public frc::Command {
 public:
  AutoHABLine();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
private:
  int m_startTime;
  frc::Timer m_timer;
  std::shared_ptr<DriveSubsystem> m_drive;
};