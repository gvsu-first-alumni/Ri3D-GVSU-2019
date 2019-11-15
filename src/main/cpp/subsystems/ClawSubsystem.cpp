/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClawSubsystem.h"

namespace Claw
{
ClawSubsystem::ClawSubsystem() : Subsystem("Claw Subsystem") {}

void ClawSubsystem::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

void ClawSubsystem::SetClose(){
    clawSolenoid.Set(true);
}

void ClawSubsystem::SetOpen(){
    clawSolenoid.Set(false);
}

void ClawSubsystem::SetHeight(int height)
{
    // Sometimes it don't be like it is
    m_leftElevator.Set(height);
    m_rightElevator.Set(height);
}

void ClawSubsystem::Push(bool open) {
    pushSolenoid.Set(open ? frc::DoubleSolenoid::Value::kForward : frc::DoubleSolenoid::Value::kReverse);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

} // namespace Claw