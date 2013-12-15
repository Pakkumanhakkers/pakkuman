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
 * Styr rörliga objekt med AI
 * M�ste includea AiType:s och Directions p� n�got vis!!
 * Finns i ghost och i moveable
 */
class AiInputComponent : Moveable, GameEngine
{
public:
	enum AiType
	{
		CHASE, RANDOM, SCATTER, HOME
	};
	void update(Moveable*, GameEngine*);
	Moveable::Direction updateDirection(AiInputComponent::AiType Ai, Moveable* ghost, int target_x, int target_y);
	void setAi(AiType);
	AiType getAi();
	AiInputComponent(Map*, PathFinder*);

private:
    bool Valid(int ghost_x, int ghost_y,int direction);
	Moveable::Direction getRandom(int ghost_x, int ghost_y);
	PathFinder *pathfinder;
	AiType CurrentAi = CHASE;
	Map* internalMap;

};



#endif /* AIINPUTCOMPONENT_H_ */
