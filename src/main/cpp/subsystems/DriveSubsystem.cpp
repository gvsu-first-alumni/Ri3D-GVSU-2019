#include "subsystems/DriveSubsystem.h"
#include "RobotMap.h"

DriveSubsystem::DriveSubsystem() : frc::Subsystem("DriveSubsystem") {
    this->leftOffset = 0;
    this->rightOffset = 0;
    this->headingOffset = 0;
    this->backRight.SetInverted(true);
    this->frontRight.SetInverted(true);
}

void DriveSubsystem::InitDefaultCommand() {
  SetDefaultCommand(new DriveCommand());
}

void DriveSubsystem::TankDrive(double left, double right) {
    this->robotDrive.TankDrive(left * LIMITER, right * LIMITER);
}

void DriveSubsystem::Stop() {
    this->robotDrive.TankDrive(0, 0);
}

double DriveSubsystem::GetHeading() {
    return this->navX.GetYaw() - this->headingOffset;
}

void DriveSubsystem::ResetHeading() {
    this->headingOffset = this->navX.GetYaw();
}

int DriveSubsystem::GetLeftEncoder() {
    return this->frontLeft.GetEncoder().GetPosition() - this->leftOffset;
}

int DriveSubsystem::GetRightEncoder() {
    return this->frontRight.GetEncoder().GetPosition() - this->rightOffset;
}

void DriveSubsystem::ResetEncoders() {
    this->leftOffset = this->frontLeft.GetEncoder().GetPosition();
    this->rightOffset = this->frontRight.GetEncoder().GetPosition();
    this->lastLeftValue = 0;
    this->lastRightValue = 0;
}

void DriveSubsystem::ResetPosition() {
    this->x = 0;
    this->y = 0;
}

void DriveSubsystem::UpdatePosition() {
    int leftValue = this->GetLeftEncoder();
    int rightValue = this->GetRightEncoder();
    int leftDelta = leftValue - this->lastLeftValue;
    int rightDelta = rightValue - this->lastRightValue;
    double deriv = (leftDelta + rightDelta) / 2;
    double heading = (this->GetHeading() * M_PI) / 180;
    this->x += deriv * cos(heading);
    this->y += deriv * sin(heading);
    this->lastLeftValue = leftValue;
    this->lastRightValue = rightValue;
}

double DriveSubsystem::GetX() {
    return this->x / TICKS_PER_INCH;
}

double DriveSubsystem::GetY() {
    return this->y / TICKS_PER_INCH;
}

double DriveSubsystem::GetLeftPosition() {
    return this->GetLeftEncoder() / TICKS_PER_INCH;
}

double DriveSubsystem::GetRightPosition() {
    return this->GetRightEncoder() / TICKS_PER_INCH;
}

AHRS* DriveSubsystem::GetNavX() {
    return &this->navX;
}