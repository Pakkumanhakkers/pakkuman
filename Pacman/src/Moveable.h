/**
 * @file Moveable.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_
class Graphics;

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

  virtual
  ~Moveable();
  Moveable(MoveableInputComponent* input, MoveablePhysicsComponent* physics,
      MoveableGraphicsComponent* graphics);

  virtual void
  update(GameEngine&);
  virtual void
  draw(Graphics&);

  Direction
  getDirection();
  void
  setDirection(Direction direction);
  double
  getSpeed();
  void
  setSpeed(double speed);

protected:
  MoveableInputComponent* input_;
  MoveablePhysicsComponent* physics_;
  MoveableGraphicsComponent* graphics_;

private:
  double speed_;
  Direction direction_;
};


#endif /* MOVEABLE_H_ */
