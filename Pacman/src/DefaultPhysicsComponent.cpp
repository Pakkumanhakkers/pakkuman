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

virtual void
DefaultPhysicsComponent::update(Moveable* moveable, GameEngine* gameEngine)
{
  Moveable::Direction direction = moveable->getDirection();
  Map* map = gameEngine->getMap();

  double p = 2 * Moveable::isPositiveDirection(direction) - 1;
  double h = Moveable::isHorizontalDirection(direction);

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
