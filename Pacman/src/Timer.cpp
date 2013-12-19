/**
 * @file Timer.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#include "Timer.h"
#include "Command.h"

Timer::Timer(Command* command, int duration) :
    timestamp_{0}, duration_{duration}, trigger_command_{command} {}

Timer::~Timer()
{
  delete trigger_command_;
}

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
