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
  current_command_ = commands_.begin();
}

void CommandManager::add(Command* command)
{
  if (current_command_ != commands_.end())
  {
      remove(current_command_, commands_.end());
      current_command_ = commands_.end();
  }

  command->execute();
  commands_.push_back(command);
}

void CommandManager::clear()
{
  remove(commands_.begin(), commands_.end());
}

bool CommandManager::canRedo()
{
  return current_command_ != commands_.end();
}

bool CommandManager::canUndo()
{
  return current_command_ != commands_.begin();
}

void CommandManager::redo()
{
  if (!canRedo())
    return;

  (*current_command_)->execute();
  ++current_command_;
}

void CommandManager::undo()
{
  if (!canUndo())
    return;

  --current_command_;
  (*current_command_)->undo();
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
