/**
 * @file GameObject.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Drawable.h"
//#include "GameEngine.h"
//#include "GraphicEngine.h"
//#include "Sprite.h"

class GraphicEngine;
class Sprite;

/**
 * Representerar ett object på spelplanen.
 */
class GameObject : public Drawable
{
public:
  virtual
  ~GameObject() = 0;
  GameObject();
  GameObject(double x, double y, Sprite* sprite);

  double
  getX();
  void
  setX(double x);
  double
  getY();
  void
  setY(double y);

  virtual int
  getState();
  virtual void
  setState(int);

  Sprite*
  getSprite();
  void
  setSprite(Sprite* sprite);

  virtual void
  draw(GraphicEngine*);

private:
  double x_;
  double y_;

  Sprite* sprite_;
};


#endif /* GAMEOBJECT_H_ */
