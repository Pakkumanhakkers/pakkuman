/**
 * @file Timer.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#include "Timer.h"


void Timer::tic()
{
  if (!hasElapsed())
    --tic;
}

bool Timer::hasElapsed()
{
  return tic == 0;
}


Command* Timer::getCommand()
{
  return trigger_command_;
}
