/**
 * @file InputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef INPUTCOMPONENT_H_
#define INPUTCOMPONENT_H_

/**
 * Hanterar indata för rörliga objekt
 */
class InputComponent
{
public:
  virtual ~InputComponent() {};
  virtual void update(Moveable*, GameEngine*) = 0;
};


#endif /* INPUTCOMPONENT_H_ */
