/**
 * @file GameObject.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
class GameEngine;
class Sprite;

#include "Drawable.h"

/**
 * Representerar ett object på spelplanen.
 */
class GameObject : public Drawable
{
public:
  virtual ~GameObject() {}
  GameObject() : x_(0), y_(0), sprite_(nullptr) {}

  virtual void update(GameEngine&) = 0;
  void draw();

  double getX() {return x_;}
  void setX(double x) {x_ = x;}
  double getY() {return y_;}
  void setY(double y) {y_ = y;}

  Sprite* getSprite() {return sprite_;}
  void setSprite(Sprite* sprite) {sprite_ = sprite;}

private:
  double x_;
  double y_;

  Sprite* sprite_;
};


#endif /* GAMEOBJECT_H_ */
