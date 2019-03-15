/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Solenoid.h> 
#include <frc/DoubleSolenoid.h> 
#include <rev/CANSparkMax.h>
#include "RobotMap.h"

namespace Claw
{
  class ClawSubsystem : public frc::Subsystem{
    public:
      ClawSubsystem();
      void InitDefaultCommand() override;
      
      void SetOpen();
      void SetClose();
      void SetHeight(int height);
      void Push(bool open);

    private:
      frc::Solenoid clawSolenoid{ 0, 4 };               //Pusher should only be powered out to kick ball
      frc::DoubleSolenoid pushSolenoid{ 3, 2 };         //Claw should be powered in and out, not pusher

      rev::CANSparkMax m_leftElevator{2, rev::CANSparkMax::MotorType::kBrushless};
      rev::CANSparkMax m_rightElevator{1, rev::CANSparkMax::MotorType::kBrushless};

      rev::CANPIDController m_leftPID;
      rev::CANPIDController m_rightPID;

      rev::CANEncoder m_leftEnc;
      rev::CANEncoder m_rightEnc;
  };
}