/**
 * @file KeyboardInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef KEYBOARDINPUTCOMPONENT_H_
#define KEYBOARDINPUTCOMPONENT_H_

#include "Moveable.h"
#include "Component.h"
#include "Direction.h"
class GameEngine;

/**
 * Styr rörliga objekt med tangentbordet
 */
class KeyboardInputComponent : public Component
{
public:
  KeyboardInputComponent();
  virtual void update(GameEngine*, Moveable*);

private:
  enum Direction next_direction_;
};


#endif /* KEYBOARDINPUTCOMPONENT_H_ */
