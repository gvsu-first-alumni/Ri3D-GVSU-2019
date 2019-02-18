/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AlignHatch.h"

#include "Robot.h"
#include "RobotMap.h"

AlignHatch::AlignHatch() {
  // Use Requires() here to declare subsystem dependencies
  m_drive = Robot::driveSubsystem;
  m_vision = Robot::m_visionSubsystem;
  Requires(m_drive.get());
  Requires(m_vision.get());
}

// Called just before this Command runs the first time
void AlignHatch::Initialize() {
 // m_pid = FangvPIDController(100, -100, kP, kI, kD, 0);
}

// Called repeatedly when this Command is scheduled to run
void AlignHatch::Execute() {
  double pv = m_vision->getDistance();
  double output = m_pid.Process(0.0, pv);

  if (abs(pv) < 2) 
  {
    m_tolerable = true;
    m_timestamp = m_timer.GetFPGATimestamp();
  }
  else 
  {
    m_tolerable = false;
  }

  // Needs to match PID direction
  m_drive->TankDrive(output / 2.0, -output / 2.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AlignHatch::IsFinished() { 
  return m_tolerable && m_timer.GetFPGATimestamp() - m_timestamp > 2;
}

// Called once after isFinished returns true
void AlignHatch::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignHatch::Interrupted() {}
