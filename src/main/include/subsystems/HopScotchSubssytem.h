#pragma once

#include "frc/WPILib.h"

class HopScotchSubsystem : public frc::Subsystem {
    public:
        HopScotchSubsystem();
        void InitDefaultCommand() override;
        void GoUp();
        void GoDown();
    
    private:
        frc::Solenoid leftSolenoid{ 0, 0 };
        frc::Solenoid rightSolenoid{ 0, 1 };
};