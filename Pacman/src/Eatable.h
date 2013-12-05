/**
 * @file Eatable.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef EATABLE_H_
#define EATABLE_H_


class Eatable
{
public:
  enum FoodType
  {
    DOT, CHERRY, STRAWBERRY, KEY, GHOST, NONE
  };

  ~Eatable() {}
  Eatable() {}
  void setFoodType(FoodType foodType) {foodType_ = foodType;}
  FoodType getFoodType() {return foodType_;}

private:
  FoodType foodType_;
};


#endif /* EATABLE_H_ */
