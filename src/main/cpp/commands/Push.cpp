/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Push.h"

#include "Robot.h"

Push::Push(bool open) {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_clawSubsystem.get());
  m_open = open;
}

// Called just before this Command runs the first time
void Push::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Push::Execute() 
{
    Robot::m_clawSubsystem->Push(m_open);
}

// Make this return true when this Command no longer needs to run execute()
bool Push::IsFinished() { return true; }

// Called once after isFinished returns true
void Push::End() 
{
    //Robot::m_clawSubsystem->Push(!m_open);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Push::Interrupted() {}
