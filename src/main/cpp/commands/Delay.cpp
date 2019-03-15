/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Delay.h"
#include <iostream>

Delay::Delay(double time) {
  m_time = time;
}

// Called just before this Command runs the first time
void Delay::Initialize()
{
  m_init = m_timer.GetFPGATimestamp();
}

// Called repeatedly when this Command is scheduled to run
void Delay::Execute() {
  std::cout << "Delaying" << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool Delay::IsFinished() { return m_timer.GetFPGATimestamp() > m_init + m_time; }

// Called once after isFinished returns true
void Delay::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Delay::Interrupted() {}
