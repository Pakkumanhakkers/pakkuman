/**
 * @file PhysicsComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef PHYSICSCOMPONENT_H_
#define PHYSICSCOMPONENT_H_
class Moveable;

class GameEngine;

/**
 * Hanterar fysiken för rörliga objekt
 */
class PhysicsComponent
{
public:
  virtual
  ~PhysicsComponent();
  virtual void
  update(Moveable*, GameEngine*) = 0;

  static bool
  isWallAhead(Map*, double x, double y, Moveable::Direction);
  static bool
  canTurn(Map*, Moveable*, Moveable::Direction);

};


#endif /* PHYSICSCOMPONENT_H_ */
