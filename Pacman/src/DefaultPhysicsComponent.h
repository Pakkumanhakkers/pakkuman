/**
 * @file DefaultPhysicsComponent.h
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#ifndef DEFAULTPHYSICSCOMPONENT_H_
#define DEFAULTPHYSICSCOMPONENT_H_

#include "DefaultPhysicsComponent.h"

class DefaultPhysicsComponent : public Component
{
public:
  DefaultPhysicsComponent();

  virtual void
  update(GameEngine*, Moveable*);

  static bool
  isWallAhead(Map*, GameObject*, Moveable::Direction);
  static bool
  canTurn(Map*, Moveable*, Moveable::Direction);

};

#endif /* DEFAULTPHYSICSCOMPONENT_H_ */
