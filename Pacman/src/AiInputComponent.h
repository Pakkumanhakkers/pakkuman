/**
 * @file AiInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef AIINPUTCOMPONENT_H_
#define AIINPUTCOMPONENT_H_

//#include "Component.h"
//#include "Ghost.h"
//#include "Map.h"

#include "Component.h"
#include "Direction.h"

class Moveable;
class Map;
class PathFinder;
class GameObject;
class GameEngine;

//#include "PathFinder.h"

/**
 * Styr rörliga objekt med AI
 * M�ste includea AiType:s och Directions p� n�got vis!!
 * Finns i ghost och i moveable
 */
class AiInputComponent : public Component
{
public:
	enum AiType
	{
		CHASE, RANDOM, SCATTER, HOME
	};

        AiInputComponent(Map*, PathFinder*);

        // TODO uppdatera bara vid korsningar, endast en (1) gång
	void update(GameEngine*, Moveable*);

	void setAi(AiType);
	AiType getAi();

private:
  //bool Valid(int ghost_x, int ghost_y,int direction);
  Direction updateDirection(Moveable* ghost, GameEngine* gameengine);
  Direction getRandom(GameObject*);
  PathFinder* pathfinder;
  AiType CurrentAi = CHASE;
  Map* internalMap;

};



#endif /* AIINPUTCOMPONENT_H_ */
