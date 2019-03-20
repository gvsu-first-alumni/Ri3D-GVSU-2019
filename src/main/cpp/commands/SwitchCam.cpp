/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SwitchCam.h"
#include "Robot.h"

SwitchCam::SwitchCam() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_cameraSubsystem.get());
}

// Called just before this Command runs the first time
void SwitchCam::Initialize() {
  if (Robot::m_cameraSubsystem->IsClawCam())
    Robot::m_cameraSubsystem->UseLineCamera();
  else
  
    Robot::m_cameraSubsystem->UseClawCamera();
}

// Called repeatedly when this Command is scheduled to run
void SwitchCam::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool SwitchCam::IsFinished() { return true; }

// Called once after isFinished returns true
void SwitchCam::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchCam::Interrupted() {}
