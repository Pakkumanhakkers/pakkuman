/**
 * @file Moveable.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "Moveable.h"

#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"

Moveable::~Moveable()
{
}

Moveable::Moveable(InputComponent* input, PhysicsComponent* physics,
      GraphicsComponent* graphics) :
    input_{input}, physics_{physics}, graphics_{graphics},
    speed_{0}, direction_{Direction::LEFT} {}

/**
 * Uppdaterar internt tillstånd genom kommandon.
 * @param gameEngine spelmotorn
 */
void
Moveable::update(GameEngine* gameEngine)
{
  input_->update(this, gameEngine);
  physics_->update(this, gameEngine);
  graphics_->update(this);
}

/**
 * Ritar ut objektet.
 * @param graphics grafikmotor
 */
void
Moveable::draw(Graphics* graphics)
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

/**
 * Sant om objektet är mitt på en ruta.
 * @return
 */
bool
Moveable::isCentered()
{
  double h = isHorizontalDirection(direction_);

  return (abs(x_ - round(x_))*(1.0 - h) <= speed_ &&
      abs(y_ - round(y_))*h <= speed_);
}

/**
 * Sant om riktningen är horisontell.
 * @param direction riktning
 * @return horisontell
 */
static bool
Moveable::isHorizontalDirection(Moveable::Direction direction)
{
  return direction % 2 == 0;
}

/**
 * Sant om riktningen är i positiv led.
 * @param direction riktning
 * @return positiv
 */
static bool
Moveable::isPositiveDirection(Moveable::Direction direction)
{
  return direction / 2 == 0;
}
