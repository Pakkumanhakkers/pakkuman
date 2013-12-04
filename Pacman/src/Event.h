/*
 * Event.h
 *
 *  Created on: 4 dec 2013
 *      Author: tor
 */

#ifndef EVENT_H_
#define EVENT_H_

/**
 * En händelse som ska utföras
 */
class Event
{
public:
  virtual ~Event() {}
  virtual void execute() = 0;
  virtual void undo() = 0;
};

class MoveObjectEvent : public Event
{
public:
  MoveObjectEvent(GameObject object, double x, double y) :
    object_(object), x_(x), y_(y) {}

  void execute();
  void undo();
private:
  GameObject object_;
  double x_;
  double y_;
};

class EatObjectEvent : public Event
{
public:
  EatObjectEvent();
};

#endif /* EVENT_H_ */
