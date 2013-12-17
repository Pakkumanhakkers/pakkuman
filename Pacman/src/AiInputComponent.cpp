/**
 * @file AiInputComponent.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "AiInputComponent.h"

#include <stdlib.h>
#include <time.h>

#include "Command.h"
#include "GameEngine.h"
#include "GameInstance.h"
#include "Pacman.h"
#include "PathFinder.h"
#include "GameEngine.h"
#include "Moveable.h"

//konstruktor
AiInputComponent::AiInputComponent(Map* map, PathFinder* inpathfinder)
{
	internalMap = map;
	pathfinder = inpathfinder;
}

void AiInputComponent::update(GameEngine* gameEngine, Moveable* moveable)
{
  /*
  Moveable::Direction direction;
  DefaultPhysicsComponent::canTurn(internalMap, moveable, direction);
  */
  AiInputComponent::AiType nextAi;

  switch (moveable->getState())
  {
    case Ghost::EATABLE:
    case Ghost::EATABLE_BLINK:
      nextAi = AiInputComponent::SCATTER;
      break;
    case Ghost::EATEN:
      nextAi = AiInputComponent::HOME;
      break;
    default:
      nextAi = AiInputComponent::CHASE;
      break;
  }

  if (nextAi != getAi())
  {
    setAi(nextAi);
    Moveable::Direction next = updateDirection(moveable, gameEngine);
    gameEngine->publishCommand(new DirectCommand(moveable, next));
  }
}

AiInputComponent::AiType AiInputComponent::getAi()
{
	return CurrentAi;
}

void AiInputComponent::setAi(AiType ai)
{
	CurrentAi = ai;
}

Moveable::Direction AiInputComponent::updateDirection(Moveable* ghost,
    GameEngine* gameengine)
{
	int target_x{0};
	int target_y{0};
	int slump;
	if (CurrentAi == AiInputComponent::AiType::CHASE)
	{
		target_x = gameengine->getGame()->pacman->getX();
		target_y = gameengine->getGame()->pacman->getY();
		return (pathfinder->getDirection(ghost,target_x,target_y));
	}
	else if (CurrentAi == AiInputComponent::AiType::RANDOM)
		return getRandom(ghost);
	else if (CurrentAi == AiInputComponent::AiType::HOME)
	{
		target_x = internalMap->getGhostX();
		target_y = internalMap->getGhostY();
		return (pathfinder->getDirection(ghost,target_x,target_y));
	}
	else //if (Ai == AiInputComponent::AiType::SCATTER)
		//slumpar mellan RANDOM och 5*(pacmans position)
	{
		srand (time(NULL));
		slump = rand() % 1;
		if (slump == 0)
			return getRandom(ghost);
		else
		{
			target_x = 5*gameengine->getGame()->pacman->getX();
			target_y = 5*gameengine->getGame()->pacman->getY();
			return (pathfinder->getDirection(ghost,target_x,
			    target_y));
		}
	}
}
	
/* använder isWallAhead från DefaultPhysicsComponent istället
bool AiInputComponent::Valid(int ghost_x, int ghost_y, int direction)
// isWall m�ste kallas med ett mapobjekt??
{
	if (direction == 0 && internalMap->isWall(ghost_x - 1, ghost_y))
		return false;
	else if (direction == 1 && internalMap->isWall(ghost_x + 1, ghost_y))
		return false;
	else if (direction == 2 && internalMap->isWall(ghost_x, ghost_y +1))
		return false;
	else if (direction == 3 && internalMap->isWall(ghost_x, ghost_y -1))
		return false;
	else
	return true;
}*/

Moveable::Direction AiInputComponent::getRandom(GameObject* moveable)
{
	Moveable::Direction direction;
	srand (time(NULL));
	do
	{
		direction = Moveable::Direction(rand() % 3);
	}
	while (!DefaultPhysicsComponent::isWallAhead(
	            internalMap, moveable, direction));

        switch(direction)
        {
                case(0):
                return Moveable::LEFT;
                case(1):
                return Moveable::RIGHT;
                case(2):
                return Moveable::UP;
                case(3):
                return Moveable::DOWN;
        }
    return Moveable::UP;
}
