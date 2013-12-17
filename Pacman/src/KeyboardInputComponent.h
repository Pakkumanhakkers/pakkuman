/**
 * @file KeyboardInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef KEYBOARDINPUTCOMPONENT_H_
#define KEYBOARDINPUTCOMPONENT_H_

#include "Moveable.h"
#include "GameEngine.h"

/**
 * Styr rörliga objekt med tangentbordet
 */
class KeyboardInputComponent : public Component
{
public:
  KeyboardInputComponent();
  virtual void update(GameEngine*, Moveable*);

private:
  Moveable::Direction next_direction_;
};


#endif /* KEYBOARDINPUTCOMPONENT_H_ */
