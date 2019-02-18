/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoHatch.h"

#include "Robot.h"

AutoHatch::AutoHatch() {
  Requires(Robot::driveSubsystem.get());
  Requires(Robot::m_cameraSubsystem.get()); // Maybe
  Requires(Robot::m_clawSubsystem.get());
}

// Called just before this Command runs the first time
void AutoHatch::Initialize() {
  // Drive sequence to front of hatch
  // Align with hatch line
  // Drive forward? drop hatch
  // Move out of way?
}

// Called repeatedly when this Command is scheduled to run
void AutoHatch::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool AutoHatch::IsFinished() { return false; }

// Called once after isFinished returns true
void AutoHatch::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoHatch::Interrupted() {}
