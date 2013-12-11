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
  virtual void update(GameEngine&);
};



#endif /* FOOD_H_ */
