/**
 * @file AiInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef AIINPUTCOMPONENT_H_
#define AIINPUTCOMPONENT_H_
class GameEngine;
class Moveable;

/**
 * Styr rörliga objekt med AI
 */
class AiInputComponent
{
public:
  void update(Moveable&, GameEngine&);
};


#endif /* AIINPUTCOMPONENT_H_ */
