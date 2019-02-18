/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "commands/Ascend.h"

Ascend::Ascend() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_hopscotchSubsystem.get());
}

// Called just before this Command runs the first time
void Ascend::Initialize() {
  Robot::m_hopscotchSubsystem->GoUp();
}

// Called repeatedly when this Command is scheduled to run
void Ascend::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool Ascend::IsFinished() { return false; }

// Called once after isFinished returns true
void Ascend::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Ascend::Interrupted() {}
