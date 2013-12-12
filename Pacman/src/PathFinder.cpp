/**
 * @file PathFinder.cpp
 *
 *  Created on: 6 dec 2013
 * @author Erik & Ph
 */

#include "Moveable.h"
#include <random>
#include <iostream>
using namespace std;

PathFinder::Direction getDirection(pointTarget)
{

int intDirection;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 3);
Direction direction_;
intDirection = dis(gen)
switch(int_direction)
{
case(0):
return direction_= LEFT;
case(1)
return direction_ = RIGHT;
case(2)
return direction_ = UP;
case(3)
return direction_ = DOWN;
}
}