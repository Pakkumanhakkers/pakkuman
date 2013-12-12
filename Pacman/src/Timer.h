/**
 * @file Timer.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef TIMER_H_
#define TIMER_H_
class Command;


class Timer
{
public:
  Timer(Command*, int);

  void setTimestamp(int);
  int getTimestamp();
  bool hasElapsed(int);
  Command* getCommand();

private:
  int timestamp_;
  int duration_;
  Command* trigger_command_;
};


#endif /* TIMER_H_ */
