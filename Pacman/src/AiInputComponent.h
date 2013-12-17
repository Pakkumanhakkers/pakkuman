/**
 * @file AiInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef AIINPUTCOMPONENT_H_
#define AIINPUTCOMPONENT_H_

#include "Ghost.h"
#include "Map.h"
#include "Moveable.h"

class PathFinder;
/**
 * Styr rÃ¶rliga objekt med AI
 * Måste includea AiType:s och Directions på något vis!!
 * Finns i ghost och i moveable
 */
class AiInputComponent
{
public:
	enum AiType
	{
		CHASE, RANDOM, SCATTER, HOME
	};
	void update(GameEngine*, Moveable*);
	Moveable::Direction updateDirection(AiInputComponent::AiType Ai, Moveable* ghost, GameEngine* gameengine);
	void setAi(AiType);
	AiType getAi();
	AiInputComponent(Map*, PathFinder*);

private:
    bool Valid(int ghost_x, int ghost_y,int direction);
	Moveable::Direction getRandom(int ghost_x, int ghost_y);
	PathFinder* pathfinder;
	AiType CurrentAi = CHASE;
	Map* internalMap;

};



#endif /* AIINPUTCOMPONENT_H_ */
