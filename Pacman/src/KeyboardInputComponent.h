/**
 * @file KeyboardInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef KEYBOARDINPUTCOMPONENT_H_
#define KEYBOARDINPUTCOMPONENT_H_
class GameEngine;

#include "Moveable.h"

/**
 * Styr rörliga objekt med tangentbordet
 */
class KeyboardInputComponent : public InputComponent
{
public:
  KeyboardInputComponent();
  virtual void update(Moveable*, GameEngine*);

private:
  Moveable::Direction next_direction_;
};


#endif /* KEYBOARDINPUTCOMPONENT_H_ */
