/**
 * @file MoveableInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef MOVEABLEINPUTCOMPONENT_H_
#define MOVEABLEINPUTCOMPONENT_H_

/**
 * Hanterar indata för rörliga objekt
 */
class MoveableInputComponent
{
public:
  virtual ~MoveableInputComponent();
  virtual void update(Moveable&, GameEngine&);
};


#endif /* MOVEABLEINPUTCOMPONENT_H_ */
