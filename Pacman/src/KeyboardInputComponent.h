/**
 * @file KeyboardInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef KEYBOARDINPUTCOMPONENT_H_
#define KEYBOARDINPUTCOMPONENT_H_
class GameEngine;
class Moveable;

/**
 * Styr rörliga objekt med tangentbordet
 */
class KeyboardInputComponent
{
public:
  void update(Moveable&, GameEngine&);
};


#endif /* KEYBOARDINPUTCOMPONENT_H_ */
