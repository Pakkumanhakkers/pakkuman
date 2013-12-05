/**
 * @file Moveable.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_
class GraphicsComponent;
class InputComponent;
class PhysicsComponent;

#include "GameObject.h"

/**
 * Ett flyttbart spelobject.
 */
class Moveable : public GameObject
{
public:
  enum Direction {
    LEFT, RIGHT, UP, DOWN
  };

  virtual ~Moveable() {};
  Moveable(InputComponent* input, PhysicsComponent* physics,
      GraphicsComponent* graphics) :
    graphics_(graphics), input_(input), physics_(physics),
    speed_(0), direction_(Direction::LEFT) {}

  virtual void update(GameEngine&);

  virtual Direction getDirection();
  virtual void setDirection(Direction);
  virtual double getSpeed();
  virtual void setSpeed(double);

protected:
  MoveableInputComponent* input_;
  MoveablePhysicsComponent* physics_;
  MoveableGraphicsComponent* graphics_;

  double speed_;
  Direction direction_;
};


#endif /* MOVEABLE_H_ */
