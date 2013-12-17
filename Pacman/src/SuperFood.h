/**
 * @file SuperFood.h
 *
 *  Created on: 16 dec 2013
 * @author ivar
 */

#ifndef SUPERFOOD_H_
#define SUPERFOOD_H_

#include "Food.h"

class GameEngine;
class Sprite;

class SuperFood : public Food
{
public:
  SuperFood(double x, double y, Sprite* sprite, int score);

  virtual void eat(GameEngine*);
};

#endif /* SUPERFOOD_H_ */
