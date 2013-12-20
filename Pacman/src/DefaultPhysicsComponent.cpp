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
#include <cmath>

DefaultPhysicsComponent::DefaultPhysicsComponent()
{
}

void
DefaultPhysicsComponent::update(GameEngine* gameEngine, Moveable* moveable)
{
  Direction direction = moveable->getDirection();
  Map* map = gameEngine->getMap();

  double sign = 2 * isPositiveDirection(direction) - 1;
  double hori = isHorizontalDirection(direction);

  double x = moveable->getX();
  double y = moveable->getY();
  double speed = moveable->getSpeed();
  // is object centered in ortigonal direction?
  if ((fabs(x - round(x)) * (1.0 - hori) < speed * 0.75 &&
      fabs(y - round(y)) * hori < speed * 0.75))
  {
    // is target position available?
    if (canMove(map, moveable, direction))
    {
      double newX = round(x) * (1.0 - hori) + hori * (x + sign * speed);
      double newY = round(y) * hori + (1.0 - hori) * (y + sign * speed);

      gameEngine->publishCommand(new MoveCommand(moveable, newX, newY));
    }
    else if (x != round(x) || y != round(y))
    {
      // center object
      //gameEngine->publishCommand(new MoveCommand(moveable, round(x), round(y)));
    }
  }
}

/**
 * Sant om koordinaterna inte inkräktar på någon närliggande vägg.
 * @param map
 * @param x
 * @param y
 * @return
 */
bool
DefaultPhysicsComponent::isAvailable(Map* map, double x, double y)
{
  return !(map->isWall(int(x), int(y)) ||
      map->isWall(int(ceil(x)), int(y)) ||
      map->isWall(int(ceil(x)), int(ceil(y))) ||
      map->isWall(int(x), int(ceil(y))));
}

/**
 * Sant om nästa position är tillgänglig enligt isAvailable.
 * @param map
 * @param moveable
 * @param direction
 * @return
 */
bool
DefaultPhysicsComponent::canMove(Map* map, Moveable* moveable,
    Direction direction)
{
  double delta = moveable->getSpeed();
  if (!isPositiveDirection(direction))
  {
    delta = -delta;
  }

  switch (direction)
  {
  case Direction::LEFT:
  case Direction::RIGHT:
    return isAvailable(map, moveable->getX() + delta, round(moveable->getY()));
  case Direction::DOWN:
  case Direction::UP:
    return isAvailable(map, round(moveable->getX()), moveable->getY() + delta);
  }
  // build warning prevention
  return false;
}
