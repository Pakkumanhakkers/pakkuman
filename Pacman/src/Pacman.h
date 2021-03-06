/**
 * @file Pacman.h
 *
 *  Created on: 10 dec 2013
 * @author ivar
 */

#ifndef PACMAN_H_
#define PACMAN_H_
#include "Moveable.h"
class GameEngine;
class Sprite;

/**
 * Pacman som äter allt.
 */
class Pacman : public Moveable
{
public:
  enum Health
  {
    ALIVE, DEAD
  };

  virtual ~Pacman();
  Pacman();
  Pacman(double x, double y, Sprite* sprite);

  virtual int getState();
  virtual void setState(int);

  void die(GameEngine*);
  void spawn(GameEngine*, int x, int y);
private:
  Health health_;
};



#endif /* PACMAN_H_ */
