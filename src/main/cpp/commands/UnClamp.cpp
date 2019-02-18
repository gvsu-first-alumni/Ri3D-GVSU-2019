/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/UnClamp.h"
#include "Robot.h"

UnClamp::UnClamp() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_clawSubsystem.get());
}

// Called just before this Command runs the first time
void UnClamp::Initialize() {
  Robot::m_clawSubsystem->SetOpen();
}

// Called repeatedly when this Command is scheduled to run
void UnClamp::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool UnClamp::IsFinished() { return false; }

// Called once after isFinished returns true
void UnClamp::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UnClamp::Interrupted() {}
