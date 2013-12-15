/**
 * @file CommandManager.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#include "CommandManager.h"

CommandManager::~CommandManager()
{
  clear();
}

CommandManager::CommandManager()
{
  currentCommand_ = commands_.begin();
}

void CommandManager::add(Command* command)
{
  if (currentCommand_ != commands_.end())
  {
      remove(currentCommand_, commands_.end());
      currentCommand_ = commands_.end();
  }

  command->setTimestamp(currentTime_);
  commands_.push_back(command);
}

void CommandManager::add(Timer* timer)
{
  if (currentCommand_ != commands_.end())
  {
      remove(currentCommand_, commands_.end());
      currentCommand_ = commands_.end();
  }

  timer->setTimestamp(currentTime_);
  activeTimers_.push_back(timer);
}

void CommandManager::setCurrentTime(int time)
{
  currentTime_ = time;
}

void CommandManager::clear()
{
  remove(commands_.begin(), commands_.end());
}

bool CommandManager::canRedo()
{
  return currentCommand_ != commands_.end();
}

bool CommandManager::canUndo()
{
  return currentCommand_ != commands_.begin();
}

void CommandManager::redo()
{
  if (!canRedo())
    return;

  (*currentCommand_)->execute();
  ++currentCommand_;
}

void CommandManager::undo()
{
  if (!canUndo())
    return;

  --currentCommand_;
  (*currentCommand_)->undo();
}

void CommandManager::remove(std::list<Command*>::iterator start,
    std::list<Command*>::iterator end)
{
  for (std::list<Command*>::iterator i = start; i != end; ++i)
  {
    delete *i;
  }

  commands_.erase(start, end);
}
