/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClawSubsystem.h"

namespace Claw
{
ClawSubsystem::ClawSubsystem() : Subsystem("Claw Subsystem"),
    m_leftPID(m_leftElevator.GetPIDController()), m_rightPID(m_rightElevator.GetPIDController()),
    m_leftEnc(m_leftElevator.GetEncoder()), m_rightEnc(m_rightElevator.GetEncoder())
{
    m_leftPID.SetP(kP);
    m_leftPID.SetI(kI);
    m_leftPID.SetD(kD);
    m_leftPID.SetIZone(100);
    m_leftPID.SetFF(0);
    m_leftPID.SetOutputRange(-100, 100);

    m_rightPID.SetP(kP);
    m_rightPID.SetI(kI);
    m_rightPID.SetD(kD);
    m_rightPID.SetIZone(100);
    m_rightPID.SetFF(0);
    m_rightPID.SetOutputRange(-100, 100);
}

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
    m_leftPID.SetReference(height, rev::ControlType::kPosition);
    m_rightPID.SetReference(height, rev::ControlType::kPosition);
}

void ClawSubsystem::Push(bool open) {
    pushSolenoid.Set(open ? frc::DoubleSolenoid::Value::kForward : frc::DoubleSolenoid::Value::kReverse);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

} // namespace Claw