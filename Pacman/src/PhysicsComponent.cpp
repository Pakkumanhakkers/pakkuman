/**
 * @file PhysicsComponent.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "PhysicsComponent.h"


PhysicsComponent::~PhysicsComponent()
{
}

bool
PhysicsComponent::isWallAhead(Map* map, double x, double y,
    Moveable::Direction direction)
{
  int p = Moveable::isPositiveDirection(direction);
  int h = Moveable::isHorizontalDirection(direction);

  return map->isWall(int{x + 0.5 * double{!h}} + h * p,
    int{y + 0.5 * double{h}} + !h * p);
  }
}

bool
PhysicsComponent::canTurn(Map* map, Moveable* moveable,
    Moveable::Direction direction)
{
  return moveable->isCentered() && !isWallAhead(map,
      moveable->getX(), moveable->getY(), direction);
}
