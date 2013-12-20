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

CommandManager::CommandManager() :
    currentTime_{0}
{
  currentCommand_ = commands_.begin();
}

/**
 * Add command to timeline and execute.
 * @param command
 */
void CommandManager::add(Command* command)
{
  if (currentCommand_ != commands_.end())
  {
      remove(commands_, currentCommand_, commands_.end());
      currentCommand_ = commands_.end();
  }

  command->setTimestamp(currentTime_);
  commands_.push_back(command);
}

/**
 * Add timer to timeline.
 * @param timer
 */
void CommandManager::add(Timer* timer)
{
  if (currentCommand_ != commands_.end())
  {
      remove(commands_, currentCommand_, commands_.end());
      currentCommand_ = commands_.end();
  }

  timer->setTimestamp(currentTime_);
  futureTimers_.push_back(timer);
}

/**
 * Update time.
 * @param time
 */
void CommandManager::setCurrentTime(int time)
{
  currentTime_ = time;
}

/**
 * Execute elapsed timer commands.
 */
void CommandManager::checkTimer()
{
  for (auto itr = futureTimers_.begin(); itr != futureTimers_.end();)
  {
    if ((*itr)->hasElapsed(currentTime_))
    {
      Command* command{(*itr)->getCommand()};
      add(command);
      command->execute();

      pastTimers_.push_back((*itr));
      itr = futureTimers_.erase(itr);
    }
    else
    {
      ++itr;
    }
  }
}

/**
 * Wipes all commands and timers from timeline.
 */
void CommandManager::clear()
{
  remove(commands_, commands_.begin(), commands_.end());
  remove(futureTimers_, futureTimers_.begin(), futureTimers_.end());
  remove(pastTimers_, pastTimers_.begin(), pastTimers_.end());

  commands_.clear();
  futureTimers_.clear();
  pastTimers_.clear();
}

/**
 * Wipes all future timers from timeline.
 */
void CommandManager::clearFutureTimers()
{
  remove(futureTimers_, futureTimers_.begin(), futureTimers_.end());

  futureTimers_.clear();
}

/**
 * Is there a future command in timeline?
 * @return
 */
bool CommandManager::canRedo()
{
  return currentCommand_ != commands_.end();
}

/**
 * Is there a previous command in timeline?
 * @return
 */
bool CommandManager::canUndo()
{
  return currentCommand_ != commands_.begin();
}

/**
 * Redo last command. One step ahead the timeline.
 */
void CommandManager::redo()
{
  if (!canRedo())
    return;

  (*currentCommand_)->execute();
  ++currentCommand_;
}

/**
 * Undo the last command, takes one step back in timeline.
 */
void CommandManager::undo()
{
  if (!canUndo())
    return;

  --currentCommand_;
  (*currentCommand_)->undo();
}

/**
 * Removes commands in specified range.
 * @param lst
 * @param start
 * @param end
 */
void CommandManager::remove(std::list<Command*> lst,
    std::list<Command*>::iterator start, std::list<Command*>::iterator end)
{
  for (std::list<Command*>::iterator i = start; i != end; ++i)
  {
    delete *i;
    i = lst.erase(i);
  }
}

/**
 * Removes timers in specified range.
 * @param lst
 * @param start
 * @param end
 *
 */
void CommandManager::remove(std::list<Timer*> lst,
    std::list<Timer*>::iterator start, std::list<Timer*>::iterator end)
{
  for (std::list<Timer*>::iterator i = start; i != end;)
  {
    delete *i;
    i = lst.erase(i);
  }
}

/**
 * Updates timeline after time travel to prevent duplicate versions of things.
 */
void CommandManager::updateTimeline()
{
  // remove timers after time travel
  for (auto itr = futureTimers_.begin(); itr != futureTimers_.end();)
  {
    // remove if timer was born in future
    if ((*itr)->getTimestamp() > currentTime_)
    {
      itr = futureTimers_.erase(itr);
    }
    else
    {
      ++itr;
    }
  }

  // refresh past timers and move to future if needed
  for (auto itr = pastTimers_.begin(); itr != pastTimers_.end();)
  {
    // remove if timer was born in future
    if ((*itr)->getTimestamp() > currentTime_)
    {
      itr = pastTimers_.erase(itr);
    }
    else if (!(*itr)->hasElapsed(currentTime_))
    {
      add((*itr)->getCommand());
      futureTimers_.push_back((*itr));
      itr = pastTimers_.erase(itr);
    }
    else
    {
      ++itr;
    }
  }
}
