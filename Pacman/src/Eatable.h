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
    EATEN, DOT, CHERRY, STRAWBERRY, KEY, GHOST, SICK_GHOST
  };

  ~Eatable() {}
  Eatable(FoodType foodtype) : foodType_{foodtype}, eaten_{false} {}

  void eat();
  void spawn();

  void setFoodType(FoodType foodType) {foodType_ = foodType;}
  FoodType getFoodType() {if (eaten_) return EATEN; else return foodType_;}

private:
  FoodType foodType_;
  bool eaten_;
};

#endif /* EATABLE_H_ */
