/**
 * @file AiInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef AIINPUTCOMPONENT_H_
#define AIINPUTCOMPONENT_H_
#include "Ghost.h"
#include "Moveable.h"


/**
 * Styr rÃ¶rliga objekt med AI
 * Måste includea AiType:s och Directions på något vis!!
 * Finns i ghost och i moveable
 */
class AiInputComponent : Moveable, GameEngine
{
public:
  void update(Moveable&, GameEngine&);
  Direction updateDirection(AiType Ai, int ghost_x, int ghost_y, int target_x, int target_y);

private:
    bool Valid(int ghost_x, int ghost_y,int direction);
	Direction getRandom(int ghost_x, int ghost_y);
};


#endif /* AIINPUTCOMPONENT_H_ */
