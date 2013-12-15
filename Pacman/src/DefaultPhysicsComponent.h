/**
 * @file DefaultPhysicsComponent.h
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#ifndef DEFAULTPHYSICSCOMPONENT_H_
#define DEFAULTPHYSICSCOMPONENT_H_

#include "DefaultPhysicsComponent.h"

class DefaultPhysicsComponent : public PhysicsComponent
{
public:
  DefaultPhysicsComponent();

  virtual void
  update(Moveable*, GameEngine*);
};

#endif /* DEFAULTPHYSICSCOMPONENT_H_ */
