/**
 * @file DefaultGraphicsComponent.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "DefaultGraphicsComponent.h"

DefaultGraphicsComponent::DefaultGraphicsComponent(MoveableSprite* sprite) :
sprite_{sprite}
{
}

DefaultGraphicsComponent::~DefaultGraphicsComponent()
{
}

void
DefaultGraphicsComponent::update(GameEngine* gameEngine, Moveable* moveable)
{
  if (sprite_->getDirection() != moveable->getDirection())
  {
    sprite_->setDirection(moveable->getDirection());
  }

  if (moveable->getSprite() != sprite_)
  {
    moveable->setSprite(sprite_);
  }
}
