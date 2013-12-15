
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

  void clear();
  bool canRedo();
  bool canUndo();
  void undo();
  void redo();
private:
  void remove(std::list<Command*>::iterator start,
      std::list<Command*>::iterator end);

  int currentTime_{0};

  std::list<Command*>::iterator currentCommand_;
  std::list<Command*> commands_;
  std::list<Timer*> activeTimers_;
  std::list<Timer*> elapsedTimers;
};


#endif /* COMMANDMANAGER_H_ */
