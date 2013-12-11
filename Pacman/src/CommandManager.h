/**
 * @file CommandManager.h
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#ifndef COMMANDER_H_
#define COMMANDER_H_

/**
 * Hanterar Command och Event för spelning och stegning längs tidsaxeln.
 */
class CommandManager
{
public:
  void addCommand(Command*);
  void addTimer(Timer*);

  bool next();
  bool prev();

private:
  int time_;
  std::list<Command*> commands_;
  std::list<Timer*> active_timers_;
  std::list<Timer*> elapsed_timers_;

};



#endif /* COMMANDER_H_ */
