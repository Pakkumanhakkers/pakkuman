/**
 * @file GhostInputComponent.cpp
 *
 *  Created on: 17 dec 2013
 * @author ivar
 */

#include "GhostInputComponent.h"

GhostInputComponent::GhostInputComponent(AiInputComponent ai) : ai_{ai}
{
}

GhostInputComponent::~GhostInputComponent()
{
}

void
GhostInputComponent::update(GameEngine* gameEngine,
    Moveable* ghost)
{
  AiInputComponent::AiType nextAi;

  switch (ghost->getState())
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

  if (nextAi != ai_.getAi())
  {
    ai_.setAi(nextAi);
    Moveable::Direction next = ai_.updateDirection(nextAi, ghost, gameEngine);
    gameEngine->publishCommand(new DirectCommand(ghost, next));
  }
}
