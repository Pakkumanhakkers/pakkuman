/**
 * @file Timer.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#include "Timer.h"

Timer::Timer(Command* command, int duration) :
    timestamp_{0}, trigger_command_{command}, duration_{duration} {}

void
Timer::setTimestamp(int time)
{
  timestamp_ = time;
}

int
Timer::getTimestamp()
{
  return timestamp_;
}

bool
Timer::hasElapsed(int time)
{
  return timestamp_ + duration_ <= time;
}

Command*
Timer::getCommand()
{
  return trigger_command_;
}
