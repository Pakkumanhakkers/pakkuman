/**
 * @file EaterPhysicsComponent.cpp
 *
 *  Created on: 15 dec 2013
 * @author tor
 */

#include "EaterPhysicsComponent.h"

#include <vector>

#include "Eatable.h"

class GameEngine;
class Moveable;

using namespace std;

EaterPhysicsComponent::EaterPhysicsComponent()
{
}

virtual void
EaterPhysicsComponent::update(Moveable* moveable, GameEngine* gameEngine)
{
  DefaultPhysicsComponent::update(moveable, gameEngine);

  for (Food* e : gameEngine->getGame()->food)
  {
    processEatable(moveable, e, e, gameEngine);
  }

  for (Ghost* e : gameEngine->getGame()->ghosts)
  {
    processEatable(moveable, e, e, gameEngine);
  }
}

void
EaterPhysicsComponent::processEatable(Moveable* moveable, GameObject* pos, Eatable* eat, GameEngine* gameEngine)
{
  if (abs(moveable->getX() - pos->getX()) < 0.5 && abs(moveable->getY() - pos->getY()))
  {
    eat->eat(gameEngine);
  }
}
