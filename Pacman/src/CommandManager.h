
/**
 * @file CommandManager.h
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#ifndef COMMANDMANAGER_H_
#define COMMANDMANAGER_H_

#include <list>

#include "Command.h"

/**
 * Hanterar återkallerliga kommandon i sekvens
 */
class CommandManager
{
public:
  ~CommandManager();
  CommandManager();
  void add(Command*);
  void add(Timer*);
  void setCurrentTime(int);
  void checkTimer();

  void clearFutureTimers();
  void clear();
  bool canRedo();
  bool canUndo();
  void undo();
  void redo();
private:
  void remove(std::list<Command*> lst,
      std::list<Command*>::iterator start,
      std::list<Command*>::iterator end);
  void remove(std::list<Timer*> lst,
      std::list<Timer*>::iterator start,
      std::list<Timer*>::iterator end);
  void updateTimeline();

  int currentTime_{0};

  std::list<Command*>::iterator currentCommand_;
  std::list<Command*> commands_;
  std::list<Timer*> futureTimers_;
  std::list<Timer*> pastTimers_;
};


#endif /* COMMANDMANAGER_H_ */
