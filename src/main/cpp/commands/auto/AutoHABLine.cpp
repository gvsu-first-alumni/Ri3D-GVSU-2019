/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auto/AutoHABLine.h"

#include "Robot.h"

AutoHABLine::AutoHABLine() {
  // Use Requires() here to declare subsystem dependencies
  m_drive = Robot::driveSubsystem;
  Requires(m_drive.get());
}

// Called just before this Command runs the first time
void AutoHABLine::Initialize() {
  m_startTime = m_timer.GetFPGATimestamp();
}

// Called repeatedly when this Command is scheduled to run
void AutoHABLine::Execute() {
  // Drive sequence to cross line
  m_drive->TankDrive(1, 1);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoHABLine::IsFinished() {
   return m_timer.GetFPGATimestamp() - m_startTime > 3; 
}

// Called once after isFinished returns true
void AutoHABLine::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoHABLine::Interrupted() {}
