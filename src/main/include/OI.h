/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Joystick.h>     //Driving w/ Joystick
#include <frc/buttons/JoystickButton.h>

class OI {
 public:
  OI();
  frc::Joystick driveStick{0};

  private:
  // see "Running commands on Joystick input" on WPIlib
	frc::JoystickButton* ClawOpen = new frc::JoystickButton(&this->driveStick, 1);
	frc::JoystickButton* ClawClose = new frc::JoystickButton(&this->driveStick, 2);
  frc::JoystickButton* goUp = new frc::JoystickButton(&this->driveStick, 9);
	frc::JoystickButton* goDown = new frc::JoystickButton(&this->driveStick, 10);
  frc::JoystickButton* pusher = new frc::JoystickButton(&this->driveStick, 3);
  frc::JoystickButton* raiseEl = new frc::JoystickButton(&this->driveStick, 6);
  frc::JoystickButton* lowerEl = new frc::JoystickButton(&this->driveStick, 5);
  frc::JoystickButton* launch = new frc::JoystickButton(&this->driveStick, 4);

  //  Button functions for controller
  frc::JoystickButton* HatchOpen;   //Set Claw position to prepare to pick up Hatch
  frc::JoystickButton* HatchClose;  //Set Claw position to secure hatch
  frc::JoystickButton* CargoOpen;   //Set Claw position to prepare to pick up Cage
  frc::JoystickButton* CargoClose;  //Set Claw position to secure Cargo
  frc::JoystickButton* ClawRelease; //Trigger Solinoid to release vertical claw at start of match
  frc::JoystickButton* Align;       //Initiallize Autonomous system to align robot to ship/rocket
  frc::JoystickButton* Height1;     //Set Claw Height to Lv1 (1'7")
  frc::JoystickButton* Height2;	    //Set Claw Height to Lv2 (3'11")
  frc::JoystickButton* Height3;	    //Set Claw Height to Lv3 (6'3")
};
