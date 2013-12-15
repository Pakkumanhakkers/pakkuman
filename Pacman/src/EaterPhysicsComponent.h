/**
 * @file EaterPhysicsComponent.h
 *
 *  Created on: 15 dec 2013
 * @author tor
 */

#ifndef EATERPHYSICSCOMPONENT_H_
#define EATERPHYSICSCOMPONENT_H_

#include "DefaultPhysicsComponent.h"

class EaterPhysicsComponent : public DefaultPhysicsComponent
{
public:
  EaterPhysicsComponent();
  virtual void
  update(Moveable*, GameEngine*);
private:
  void processEatable(Moveable*, GameObject*, Eatable*, GameEngine*);
};

#endif /* EATERPHYSICSCOMPONENT_H_ */
