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

AiInputComponent::AiInputComponent(Map* map, PathFinder* inpathfinder, AiType inputAi)
{
  internalMap = map;
  pathfinder = inpathfinder;
  CurrentAi = inputAi;
}

void AiInputComponent::update(GameEngine* gameEngine, Moveable* moveable)
{
  // could make up some other Ghost component
  Settings* settings = gameEngine->getSettings();
  double speed;

  switch (moveable->getState())
  {
  case Ghost::EATABLE:
  case Ghost::EATABLE_BLINK:
    speed = settings->ghostSickSpeed / settings->fps;
    break;
  default:
    speed = settings->ghostSpeed / settings->fps;
    break;
  }

  if (speed != moveable->getSpeed())
  {
    gameEngine->publishCommand(new SpeedCommand(moveable, speed));
  }

  if (moveable->isCentered() && moveable->getState() == Ghost::EATEN &&
          round(moveable->getX()) == gameEngine->getMap()->getGhostX() &&
          round(moveable->getY()) == gameEngine->getMap()->getGhostY())
      {
        gameEngine->publishCommand(new StateCommand(moveable, Ghost::NORMAL));
      }

  // AI starts here
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
  else
  {
    return getRandom(ghost);
  }
}

Direction AiInputComponent::getRandom(Moveable* moveable)
{
  Direction direction;
  srand (time(NULL));

  int count = 0;
  bool opposite = false;

  for (int i{0}; i < 4; ++i)
  {
    if (DefaultPhysicsComponent::canMove(internalMap, moveable, Direction(i)))
    {
      ++count;
      if (Direction(i) == getOppositeDirection(moveable->getDirection()))
      {
        opposite = true;
      }
    }
  }

  if (count == 0)
  {
    return Direction::LEFT;
  }
  else if (count == 1 && opposite)
  {
    return getOppositeDirection(moveable->getDirection());
  }

  do
  {
    direction = Direction(rand() % 4);
  }
  while (!DefaultPhysicsComponent::canMove(internalMap, moveable, direction) ||
      direction == getOppositeDirection(moveable->getDirection()));

  return direction;
}
