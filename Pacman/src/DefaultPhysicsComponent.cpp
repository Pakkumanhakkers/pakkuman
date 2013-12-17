/**
 * @file DefaultPhysicsComponent.cpp
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#include "DefaultPhysicsComponent.h"

#include "GameEngine.h"
#include "Map.h"
#include "Moveable.h"
#include <math.h>

DefaultPhysicsComponent::DefaultPhysicsComponent()
{
}

void
DefaultPhysicsComponent::update(GameEngine* gameEngine, Moveable* moveable)
{
  Direction direction = moveable->getDirection();
  Map* map = gameEngine->getMap();

  double p = 2 * isPositiveDirection(direction) - 1;
  double h = isHorizontalDirection(direction);

  double x = moveable->getX();
  double y = moveable->getY();
  double speed = moveable->getSpeed();

  if (canTurn(map, moveable, direction))
  {
    double newX = round(x) * (1.0 - h) + h * (x + p * speed);
    double newY = round(y) * h + (1.0 - h) * (y + p * speed);

    gameEngine->publishCommand(new MoveCommand(moveable, newX, newY));
  }
}


bool
DefaultPhysicsComponent::isWallAhead(Map* map, GameObject* object,
    Direction direction)
{
  int p = isPositiveDirection(direction);
  int h = isHorizontalDirection(direction);

  return map->isWall(int(object->getX() + 0.5 * double(!h)) + h * p,
    int(object->getY() + 0.5 * double(h)) + !h * p);
}

bool
DefaultPhysicsComponent::canTurn(Map* map, Moveable* moveable,
    Direction direction)
{
  return moveable->isCentered() && !isWallAhead(map,
      moveable, direction);
}
