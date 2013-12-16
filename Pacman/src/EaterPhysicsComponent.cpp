/**
 * @file EaterPhysicsComponent.cpp
 *
 *  Created on: 15 dec 2013
 * @author tor
 */

#include "EaterPhysicsComponent.h"

#include <cmath>

#include "Food.h"
#include "GameEngine.h"
#include "GameInstance.h"
#include "Ghost.h"
#include "Moveable.h"
#include "Pacman.h"

class GameEngine;
class Moveable;

using namespace std;

EaterPhysicsComponent::EaterPhysicsComponent()
{
}

virtual void
EaterPhysicsComponent::update(GameEngine* gameEngine, Moveable* moveable)
{
  for (Food* e : gameEngine->getGame()->food)
  {
    processEatable(gameEngine, moveable, e, e);
  }

  for (Ghost* e : gameEngine->getGame()->ghosts)
  {
    if (moveable->getState != Pacman::Health::ALIVE)
    {
      break;
    }

    processEatable(gameEngine, moveable, e, e);
  }
}

void
EaterPhysicsComponent::processEatable(GameEngine* gameEngine,
    Moveable* moveable, GameObject* pos, Eatable* eat)
{
  if (abs(moveable->getX() - pos->getX()) < 0.5 &&
      abs(moveable->getY() - pos->getY()))
  {
    eat->eat(gameEngine);
  }
}
