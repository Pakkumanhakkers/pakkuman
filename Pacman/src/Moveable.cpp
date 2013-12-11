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

Moveable::~Moveable()
{
}

Moveable::Moveable(MoveableInputComponent* input, MoveablePhysicsComponent* physics,
      MoveableGraphicsComponent* graphics) :
    input_{input}, physics_{physics}, graphics_{graphics},
    speed_{0}, direction_{Direction::LEFT} {}

/**
 * Uppdaterar internt tillstånd genom kommandon.
 * @param gameEngine spelmotorn
 */
void
Moveable::update(GameEngine& gameEngine)
{
  input_->update(*this, gameEngine);
  physics_->update(*this, gameEngine);
  graphics_->update(*this);
}

/**
 * Ritar ut objektet.
 * @param graphics grafikmotor
 */
void
Moveable::draw(Graphics& graphics)
{
}

/**
 * Ger objektets riktning.
 * @return direction
 */
Moveable::Direction
Moveable::getDirection()
{
  return direction_;
}

/**
 * Sätter objektets riktning.
 * @param direction
 */
void
Moveable::setDirection(Direction direction)
{
  direction_ = direction;
}

/**
 * Ger objektets fart.
 * @return speed
 */
double
Moveable::getSpeed()
{
  return speed_;
}

/**
 * Sätter objektets fart.
 * @param speed
 */
void
Moveable::setSpeed(double speed)
{
  speed_ = speed;
}
