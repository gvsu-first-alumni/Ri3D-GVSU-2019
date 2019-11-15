/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

//Definitions of buttons on a single controller
constexpr int kLeftMotor = 1;
constexpr int kRightMotor = 5;
constexpr int kSqButton = 0;
constexpr int kTriButton = 3;
constexpr int kCircleButton = 2;
constexpr int kXButon = 1;
constexpr int kLTrigger = 6;
constexpr int kLBunmper = 4;
constexpr int kRTrigger = 7;
constexpr int kRBumper = 5;
constexpr int kSafetyToggle = 6;

// Safety
constexpr float kSafetyOn = -.65;
constexpr float kSafetyOff = -.89; //-.67

//Definition of motors on robot (6 motors)
constexpr int kTopLeftMotor = 1;
constexpr int kTopRightMotor = 2;
constexpr int kBottomLeftMotor = 3;
constexpr int kBottomRightMotor = 4;
constexpr int kElevMotor1 = 5;
constexpr int kElevMotor2 = 6;

// Solenoids
constexpr int kLeftHopper = 0;
constexpr int kRightHopper = 1;
constexpr int kClawForward = 3;
constexpr int kClawBackward= 2;
constexpr int kPusher = 4;

// Camera
constexpr int kFPSLimit = 20;
constexpr int kResolutionX = 320;
constexpr int kResolutionY = 240;

// PID Constants
constexpr double kP = 1.0;
constexpr double kI = 0.0;
constexpr double kD = 0.0;

constexpr double kPI = 3.14159265;