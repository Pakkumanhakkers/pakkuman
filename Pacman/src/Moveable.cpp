/**
 * @file Moveable.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "Moveable.h"

#include <cmath>

#include "Direction.h"
#include "GraphicEngine.h"

Moveable::~Moveable()
{
}

Moveable::Moveable() :
    speed_{0}, direction_{Direction::LEFT}
{
}

/**
 * Lägger till en komponent för uppdatering av objektet.
 * @param component
 */
void
Moveable::addComponent(Component* component)
{
  components_.push_back(component);
}

void
Moveable::draw(GraphicEngine* graphics)
{
  graphics->DrawSprite(getSprite(), getX(), getY(), getDirection());
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
Direction
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
 * @returnround’ was not d
 */
bool
Moveable::isCentered()
{
  return (fabs(getX() - round(getX())) < speed_ * 0.75) &&
      (fabs(getY() - round(getY())) < speed_ * 0.75);
}
