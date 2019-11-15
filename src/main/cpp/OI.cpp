/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <frc/livewindow/LiveWindow.h> 
#include <frc/Joystick.h> 

#include "commands/Clamp.h"
#include "commands/UnClamp.h"
#include "commands/Ascend.h"
#include "commands/Descend.h"
#include "commands/Push.h"
#include "commands/RaiseElevator.h"
#include "commands/LowerElevator.h"
#include "commands/ToggleSafety.h"
#include "commands/Launch.h"
#include "commands/SwitchCam.h"

OI::OI() {
  // Eventually, buttons will go here.
  this->ClawClose->WhenPressed(new Clamp());
  this->ClawOpen->WhenPressed(new UnClamp());
  this->goUp->WhenPressed(new Ascend());
  this->goDown->WhenPressed(new Descend());
  this->pusher->WhileHeld(new Push(true));
  this->pusher->WhenReleased(new Push(false));
  this->raiseEl->WhileHeld(new RaiseElevator());
  this->lowerEl->WhenActive(new LowerElevator());
  this->safety->ToggleWhenPressed(new ToggleSafety());
  this->launch->WhenPressed(new Launch());
  this->switchCam->WhenPressed(new SwitchCam());
}
