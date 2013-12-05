/**
 * @file Moveable.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "Moveable.h"

#include "MoveableGraphicsComponent.h"
#include "MoveableInputComponent.h"
#include "MoveablePhysicsComponent.h"


void Moveable::update(GameEngine& gameEngine)
{
  input_->update(*this, gameEngine);
  physics_->update(*this, gameEngine);
  graphics_->update(*this);
}

void Moveable::draw(Graphics& graphics)
{
}

