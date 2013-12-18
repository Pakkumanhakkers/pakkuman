/**
 * @file Direction.cpp
 *
 *  Created on: 18 dec 2013
 * @author ivar
 */

#include "Direction.h"

/**
 * Sant om riktningen är horisontell.
 * @param direction riktning
 * @return horisontell
 */
bool
isHorizontalDirection(Direction direction)
{
  return direction % 2 == 0;
}

/**
 * Sant om riktningen är i positiv led.
 * @param direction riktning
 * @return positiv
 */
bool
isPositiveDirection(Direction direction)
{
  return direction / 2 == 0;
}

/**
 * Ger motsatt riktning
 * @return
 */
Direction
getOppositeDirection(Direction first)
{
  return Direction((first + 2) % 4);
}
