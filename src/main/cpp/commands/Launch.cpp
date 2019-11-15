/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Launch.h"
#include "commands/Push.h"
#include "commands/UnClamp.h"
#include "commands/Delay.h"

Launch::Launch() {
  AddSequential(new UnClamp());
  AddSequential(new Delay(.04));
  AddSequential(new Push(true));
  AddSequential(new Delay(.5));
  AddSequential(new Push(false));
}