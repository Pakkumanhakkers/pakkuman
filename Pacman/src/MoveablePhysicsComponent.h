/**
 * @file MoveablePhysicsComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef MOVEABLEPHYSICSCOMPONENT_H_
#define MOVEABLEPHYSICSCOMPONENT_H_

/**
 * Hanterar fysiken för rörliga objekt
 */
class MoveablePhysicsComponent
{
public:
  virtual ~MoveablePhysicsComponent();
  virtual void update(Moveable&, GameEngine&);
};


#endif /* MOVEABLEPHYSICSCOMPONENT_H_ */
