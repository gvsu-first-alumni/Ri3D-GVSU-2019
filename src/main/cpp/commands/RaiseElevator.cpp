/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RaiseElevator.h"
#include "Robot.h"

RaiseElevator::RaiseElevator() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_clawSubsystem.get());
}

// Called just before this Command runs the first time
void RaiseElevator::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RaiseElevator::Execute() {
  Robot::m_clawSubsystem->SetHeight(-.25); // TODO: Find value
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseElevator::IsFinished() { return true; }

// Called once after isFinished returns true
void RaiseElevator::End() {
  Robot::m_clawSubsystem->SetHeight(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseElevator::Interrupted() {}
