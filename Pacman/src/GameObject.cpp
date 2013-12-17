/**
 * @file GameObject.cpp
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#include "GameObject.h"

GameObject::GameObject() :
x_{0}, y_{0}, sprite_{nullptr}
{
}

GameObject::GameObject(double x, double y, Sprite* sprite) :
x_{x}, y_{y}, sprite_{sprite}
{
}

/**
 * Ger x-koordinaten för objektets position på spelplanen.
 * @return x koordinat
 */
double
GameObject::getX()
{
  return x_;
}

/**
 * Sätter x-koordinat.
 * @param x koordinat
 */
void
GameObject::setX(double x)
{
  x_ = x;
}

/**
 * Ger y-koordinaten för objektets position på spelplanen.
 * @return y koordinat
 */
double
GameObject::getY()
{
  return y_;
}

/**
 * Sätter y-koordinat.
 * @param y koordinat
 */
void
GameObject::setY(double y)
{
  y_ = y;
}

/**
 * Ger state för objekt, nullvariant.
 * @return
 */
int
GameObject::getState()
{
  return 0;
}

/**
 * Sätter state, nullvariant.
 * @param state
 */
void
GameObject::setState(int)
{
}

/**
 * Ger grafik för objektet.
 * @return sprite grafik
 */
Sprite*
GameObject::getSprite()
{
  return sprite_;
}

/**
 * Sätter grafik för objektet.
 * @param sprite grafik
 */
void
GameObject::setSprite(Sprite* sprite)
{
  sprite_ = sprite;
}

void
GameObject::draw(GraphicEngine* graphics)
{
  graphics->Draw(getSprite(), getX(), getY());
}
