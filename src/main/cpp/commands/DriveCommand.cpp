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
    double leftValue = -1 * Robot::m_oi.driveStick.GetRawAxis(1);
    leftValue *= leftValue;
    double rightValue = Robot::m_oi.driveStick.GetRawAxis(5);
    rightValue *= rightValue;
    double leftOutput = (alpha * leftValue) + (alpham1 * this->lastLeftOutput);
    double rightOutput = (alpha * rightValue) + (alpham1 * this->lastRightOutput);
    
    if (std::abs(leftOutput) <= 0.15) {
        leftOutput = (1 * leftValue);
    }

    if (std::abs(rightOutput) <= 0.15) {
        rightOutput = (1 * rightValue);
    }

    Robot::driveSubsystem->TankDrive(1 * leftOutput, 1 * rightOutput);
    std::cout << leftOutput << " " << rightOutput << std::endl;

    this->lastLeftOutput = leftOutput;
    this->lastRightOutput = rightOutput;
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