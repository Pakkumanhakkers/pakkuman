/**
 * @file Food.h
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#ifndef FOOD_H_
#define FOOD_H_

class Food : public GameObject, public Eatable
{
public:
  Food(double x, double y, Sprite* sprite, int score);
  virtual void eat(GameEngine*);

private:
  int score_;
};



#endif /* FOOD_H_ */
