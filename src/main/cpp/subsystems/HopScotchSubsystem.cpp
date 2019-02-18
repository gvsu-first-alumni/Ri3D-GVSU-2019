#include "subsystems/HopScotchSubssytem.h"

HopScotchSubsystem::HopScotchSubsystem() : frc::Subsystem("HopScotch") {}

void HopScotchSubsystem::InitDefaultCommand() {}

void HopScotchSubsystem::GoUp() {
    this->leftSolenoid.Set(true);
    this->rightSolenoid.Set(true);
}

void HopScotchSubsystem::GoDown() {
    this->leftSolenoid.Set(false);
    this->rightSolenoid.Set(false);
}