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
    // ordningen är viktig!
    RIGHT, DOWN, LEFT, UP
  };

  virtual
  ~Moveable();
  Moveable(InputComponent* input, PhysicsComponent* physics,
      GraphicsComponent* graphics);

  virtual void
  update(GameEngine*);
  virtual void
  draw(Graphics*);

  Direction
  getDirection();
  void
  setDirection(Direction direction);
  double
  getSpeed();
  void
  setSpeed(double speed);

  bool
  isCentered();

  static bool
  isHorizontalDirection(Direction);
  static bool
  isPositiveDirection(Direction);

protected:
  InputComponent* input_;
  PhysicsComponent* physics_;
  GraphicsComponent* graphics_;

private:
  double speed_;
  Direction direction_;
};


#endif /* MOVEABLE_H_ */
