/**
 * @file Moveable.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_
class GraphicEngine;

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
    // ordningen är viktig för hjälpfunktionerna
    RIGHT, DOWN, LEFT, UP
  };

  virtual
  ~Moveable();
  Moveable();

  void
  addComponent(Component*);

  virtual void
  update(GameEngine*);

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
  std::list<Component*> components_;

private:
  double speed_;
  Direction direction_;
};


#endif /* MOVEABLE_H_ */
