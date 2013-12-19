/**
 * @file AiInputComponent.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "AiInputComponent.h"

//#include <stdlib.h>
#include <time.h>
#include <cstdlib>

#include "Command.h"
#include "DefaultPhysicsComponent.h"
#include "GameEngine.h"
#include "GameInstance.h"
#include "Ghost.h"
#include "Map.h"
#include "Moveable.h"
#include "Pacman.h"
#include "PathFinder.h"
#include "Direction.h"
#include <iostream>
#include <cmath>
//konstruktor
AiInputComponent::AiInputComponent(Map* map, PathFinder* inpathfinder, AiType inputAi)
{
  internalMap = map;
  pathfinder = inpathfinder;
  CurrentAi = inputAi;
}


void AiInputComponent::update(GameEngine* gameEngine, Moveable* moveable)
{
	//std::cout << moveable->getX() << std::endl;
	if (round(gameEngine->getGame()->pacman->getX()) == round(moveable->getX()) &&
			round(gameEngine->getGame()->pacman->getY()) == round(moveable->getY()))
	{
		gameEngine->getGame()->pacman->die(gameEngine);
	}
  if (moveable->isCentered())
  {
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
    }

    Direction next = updateDirection(moveable, gameEngine);

    if (next != moveable->getDirection())
    {
      gameEngine->publishCommand(new DirectCommand(moveable, next));
    }
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

Direction AiInputComponent::updateDirection(Moveable* ghost,
    GameEngine* gameengine)
{
  int target_x{0};
  int target_y{0};
  int slump;

  if (CurrentAi == AiInputComponent::CHASE)
  {
    target_x = gameengine->getGame()->pacman->getX();
    target_y = gameengine->getGame()->pacman->getY();
    return (pathfinder->getDirection(ghost,target_x,target_y));

  }
  else if (CurrentAi == AiInputComponent::RANDOM)
    return getRandom(ghost);
  else if (CurrentAi == AiInputComponent::HOME)
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

Direction AiInputComponent::getRandom(Moveable* moveable)
{
  Direction direction;
  srand (time(NULL));
  do
  {
    direction = Direction(rand() % 4);
  }
  while (!DefaultPhysicsComponent::canTurn(internalMap, moveable, direction) ||
		  getOppositeDirection(direction) == moveable->getDirection());

  return direction;
}
