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
  Timer(Command* command, int duration) :
    timestamp_{0}, trigger_command_{command}, duration_{duration} {}

  void setTimestamp();
  int getTimestamp() {return timestamp_;};
  bool hasElapsed(int time);
  Command* getCommand() {return trigger_command_;};

private:
  int timestamp_;
  int duration_;
  Command* trigger_command_;
};


#endif /* TIMER_H_ */
