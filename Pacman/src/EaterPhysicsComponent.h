/**
 * @file EaterPhysicsComponent.h
 *
 *  Created on: 15 dec 2013
 * @author tor
 */

#ifndef EATERPHYSICSCOMPONENT_H_
#define EATERPHYSICSCOMPONENT_H_

#include "DefaultPhysicsComponent.h"

class EaterPhysicsComponent : public Component
{
public:
  EaterPhysicsComponent();
  virtual void
  update(GameEngine*, Moveable*);
private:
  void processEatable(GameEngine*, Moveable*, GameObject*, Eatable*);
};

#endif /* EATERPHYSICSCOMPONENT_H_ */
