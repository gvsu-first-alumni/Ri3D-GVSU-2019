/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoBall.h"

#include "Robot.h"

AutoBall::AutoBall() {
  Requires(Robot::m_cameraSubsystem.get());
  Requires(Robot::m_clawSubsystem.get());
  Requires(Robot::driveSubsystem.get());
}

// Called just before this Command runs the first time
void AutoBall::Initialize() {
    
}

// Called repeatedly when this Command is scheduled to run
void AutoBall::Execute() {
  // Drive sequence to front of hatch
  // Align with hatch line
  // Drive forward? drop ball
  // Move out of way?
}

// Make this return true when this Command no longer needs to run execute()
bool AutoBall::IsFinished() { return false; }

// Called once after isFinished returns true
void AutoBall::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBall::Interrupted  () {}
