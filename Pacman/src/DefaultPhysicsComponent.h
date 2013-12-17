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
  canTurn(Map*, Moveable*, Direction);

};

#endif /* DEFAULTPHYSICSCOMPONENT_H_ */
