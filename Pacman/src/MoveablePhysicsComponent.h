/**
 * @file MoveablePhysicsComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef MOVEABLEPHYSICSCOMPONENT_H_
#define MOVEABLEPHYSICSCOMPONENT_H_
class GameEngine;
class Moveable;

/**
 * Hanterar fysiken för rörliga objekt
 */
class MoveablePhysicsComponent
{
public:
  void update(Moveable&, GameEngine&);
};


#endif /* MOVEABLEPHYSICSCOMPONENT_H_ */
