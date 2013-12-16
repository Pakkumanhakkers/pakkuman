/**
 * @file Moveable.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "Moveable.h"

#include <cmath>
#include <cstdlib>

Moveable::~Moveable()
{
}

Moveable::Moveable() :
    speed_{0}, direction_{Direction::LEFT} {}

/**
 * Lägger till en komponent för uppdatering av objektet.
 * @param component
 */
void
Moveable::addComponent(Component* component)
{
  components_.push_back(component);
}

/**
 * Uppdaterar internt tillstånd genom kommandon.
 * @param gameEngine spelmotorn
 */
void
Moveable::update(GameEngine* gameEngine)
{
  for (Component* component : components_)
  {
    component->update(gameEngine, this);
  }
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
