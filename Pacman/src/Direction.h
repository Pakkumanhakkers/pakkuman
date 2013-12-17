/**
 * @file Direction.h
 *
 *  Created on: 18 dec 2013
 * @author ivar
 */

#ifndef DIRECTION_H_
#define DIRECTION_H_



enum Direction
{
// ordningen är viktig för hjälpfunktionerna
  RIGHT, DOWN, LEFT, UP
};

bool
isHorizontalDirection(Direction);
bool
isPositiveDirection(Direction);

#endif /* DIRECTION_H_ */
