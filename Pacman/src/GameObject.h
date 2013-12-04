/*
 * GameObject.h
 *
 *  Created on: 4 dec 2013
 *      Author: tor
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Point.h"

/**
 * Representerar ett object på spelplanen.
 */
class GameObject : public Drawable
{
public:
  Point position_;

  GameObject(GraphicsComponent* graphics) : graphics_(graphics) {}

protected:
  GraphicsComponent* graphics_;
};


#endif /* GAMEOBJECT_H_ */
