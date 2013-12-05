/*
 * GameObject.h
 *
 *  Created on: 4 dec 2013
 *      Author: tor
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
class GameEngine;

// TODO: Ta bort senare
struct Sprite {};

/**
 * Representerar ett object på spelplanen.
 */
class GameObject : public Drawable
{
public:
  virtual ~GameObject() {}
  GameObject() : x_(0), y_(0) {}

  virtual void update(GameEngine&);

  double getX();
  void setX(double x);
  double getY();
  void setY(double y);

private:
  double x_;
  double y_;

  Sprite* current_sprite_;
};


#endif /* GAMEOBJECT_H_ */
