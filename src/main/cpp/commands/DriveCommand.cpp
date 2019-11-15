#include "commands/DriveCommand.h"
#include <cmath>
#include "Robot.h"

DriveCommand::DriveCommand() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::driveSubsystem.get());
}

// Called just before this Command runs the first time
void DriveCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
double alpha = .55; //0.5 //0.74;
double alpham1 = 1 - alpha;

void DriveCommand::Execute() {
    if (Robot::driveSubsystem->GetSafetyModeStatus()) {
        Robot::driveSubsystem->SetLED(kSafetyOn);
    } else {
        Robot::driveSubsystem->SetLED(kSafetyOff);
    }

    double leftValue = -1 * Robot::m_oi.driveStick.GetRawAxis(1);
    //[\]leftValue *= leftValue;
    double rightValue = Robot::m_oi.driveStick.GetRawAxis(5);
    //rightValue *= rightValue;
    double leftOutput = (alpha * leftValue) + (alpham1 * this->lastLeftOutput);
    double rightOutput = (alpha * rightValue) + (alpham1 * this->lastRightOutput);
    
    if (std::abs(leftOutput) <= 0.05) {
        leftOutput = (1 * leftValue);
    }

    if (std::abs(rightOutput) <= 0.05) {
        rightOutput = (1 * rightValue);
    }

    Robot::driveSubsystem->TankDrive(leftValue, rightValue);
    std::cout << leftValue << " " << rightValue << std::endl;

    this->lastLeftOutput = leftValue;
    this->lastRightOutput = rightValue;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveCommand::End() {
    Robot::driveSubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted() {
    DriveCommand::End();
}