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
  Timer(Command* command, int tics) : trigger_command_(command), tics_(tics) {}
  void tic();
  bool hasElapsed();
  Command* getCommand();

private:
  int tics_;
  Command* trigger_command_;
};


#endif /* TIMER_H_ */
