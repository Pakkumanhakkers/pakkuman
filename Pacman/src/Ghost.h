/**
 * @file Ghost.h
 *
 *  Created on: 10 dec 2013
 * @author ivar
 */

#ifndef GHOST_H_
#define GHOST_H_

#include "Eatable.h"
#include "Moveable.h"

class Sprite;

class GameEngine;

class Ghost : public Moveable, public Eatable
{
public:
  enum Health
  {
        NORMAL, EATABLE, EATABLE_BLINK, EATEN, SLEEP
  };

  virtual ~Ghost();
  Ghost();
  Ghost(double x, double y, Sprite* sprite);

  virtual int getState();
  virtual void setState(int);

  void changeSickness(int);
  int getSickness();

  void eat(GameEngine*);
  void die(GameEngine*);
  void spawn(GameEngine*, int x, int y);

private:
  Health health_;
  int sickness_;
  int score_;
};



#endif /* GHOST_H_ */
