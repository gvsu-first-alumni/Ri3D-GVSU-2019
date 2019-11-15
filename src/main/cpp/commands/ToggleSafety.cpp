/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ToggleSafety.h"

#include "Robot.h"
#include "RobotMap.h"

ToggleSafety::ToggleSafety() {
  Requires(Robot::driveSubsystem.get());
}

// Called just before this Command runs the first time
void ToggleSafety::Initialize() {
  Robot::driveSubsystem.get()->ToggleSafetyModeStatus();
}

// Called repeatedly when this Command is scheduled to run
void ToggleSafety::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ToggleSafety::IsFinished() { return true; }

// Called once after isFinished returns true
void ToggleSafety::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleSafety::Interrupted() {}
