/**
 * @file DefaultPhysicsComponent.h
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#ifndef DEFAULTPHYSICSCOMPONENT_H_
#define DEFAULTPHYSICSCOMPONENT_H_

#include "Moveable.h"

class GameEngine;
class GameObject;
class Map;


class DefaultPhysicsComponent : public Component
{
public:
  DefaultPhysicsComponent();

  virtual void
  update(GameEngine*, Moveable*);

  static bool
  isWallAhead(Map*, GameObject*, Direction);
  static bool
  isWallAhead(Map*, double, double, Direction);
  static bool
  isAvailable(Map*, double, double);
  static bool
  canMove(Map*, Moveable*, Direction);
};

#endif /* DEFAULTPHYSICSCOMPONENT_H_ */
