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
  enum Health
  {
    NORMAL, EATEN
  };

  Food(double x, double y, Sprite* sprite, int score);

  virtual int getState();
  virtual void setState(int);

  virtual void
  eat(GameEngine*);

private:
  int score_;
  Health health_;
};



#endif /* FOOD_H_ */
