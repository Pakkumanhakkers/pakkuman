/**
 * @file GhostGraphicComponent.cpp
 *
 *  Created on: 17 dec 2013
 * @author ivar
 */

#include "GhostGraphicComponent.h"

GhostGraphicComponent::GhostGraphicComponent(Sprite* normal, Sprite* sick,
    Sprite* blink, Sprite* dead) :
    normal_{normal}, sick_{sick}, blink_{blink}, dead_{dead}
{
}

GhostGraphicComponent::~GhostGraphicComponent()
{
}

void
GhostGraphicComponent::update(GameEngine* gameEngine, Moveable* ghost)
{
  Sprite* next;

  switch (ghost->getState())
  {
    case Ghost::EATABLE:
      next = sick_;
      break;
    case Ghost::EATABLE_BLINK:
      next = blink_;
      break;
    case Ghost::EATEN:
      next = dead_;
      break;
    default:
      next = normal_;
      break;
  }

  if (next != ghost->getSprite())
  {
    gameEngine->publishCommand(new SpriteCommand(ghost, next));
  }
}
