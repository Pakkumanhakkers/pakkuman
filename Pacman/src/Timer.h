/**
 * @file Timer.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Event.h"


class Timer
{
public:
  Timer(Event& event, int tics) : trigger_event_(event), tics_(tics) {}
  void tic();
  void trigger();

private:
  int tics_;
  Event* trigger_event_;
};


#endif /* TIMER_H_ */
