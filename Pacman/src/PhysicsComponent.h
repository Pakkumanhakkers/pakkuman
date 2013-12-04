/**
 * @file PhysicsComponent.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef PHYSICSCOMPONENT_H_
#define PHYSICSCOMPONENT_H_
class GameEngine;
class GameObject;

/**
 * Ser till att spelobjektet lyder GameEngine och dess restriktioner
 */
class PhysicsComponent
{
public:
  virtual ~PhysicsComponent();
  virtual void update(GameObject&, GameEngine&);
};


#endif /* PHYSICSCOMPONENT_H_ */
