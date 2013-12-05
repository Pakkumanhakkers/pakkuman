/**
 * @file Moveable.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_
class GameEngine;
class MoveableGraphicsComponent;
class MoveableInputComponent;
class MoveablePhysicsComponent;

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
  enum Direction
  {
    LEFT, RIGHT, UP, DOWN
  };

  virtual ~Moveable() {};
  Moveable(MoveableInputComponent* input, MoveablePhysicsComponent* physics,
      MoveableGraphicsComponent* graphics) :
    input_(input), physics_(physics), graphics_(graphics),
    speed_(0), direction_(Direction::LEFT) {}

  virtual void update(GameEngine&);
  virtual void draw(Graphics&);

  virtual Direction getDirection() {return direction_;}
  virtual void setDirection(Direction direction) {direction_ = direction;}
  virtual double getSpeed() {return speed_;}
  virtual void setSpeed(double speed) {speed_ = speed;}

protected:
  MoveableInputComponent* input_;
  MoveablePhysicsComponent* physics_;
  MoveableGraphicsComponent* graphics_;

  double speed_;
  Direction direction_;
};


#endif /* MOVEABLE_H_ */
