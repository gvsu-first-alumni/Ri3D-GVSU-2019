/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Descend.h"
#include "Robot.h"

Descend::Descend() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_hopscotchSubsystem.get());
}

// Called just before this Command runs the first time
void Descend::Initialize() {
  Robot::m_hopscotchSubsystem->GoDown();
}

// Called repeatedly when this Command is scheduled to run
void Descend::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool Descend::IsFinished() { return false; }

// Called once after isFinished returns true
void Descend::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Descend::Interrupted() {}
