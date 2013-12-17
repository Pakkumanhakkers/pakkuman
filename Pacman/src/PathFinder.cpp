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

PathFinder::PathFinder(Map* map): internalMap{map}
{
}

//PathFinder tar in en ghost och en target-position och retunerar en giltlig direction
Moveable::Direction PathFinder::getDirection(Moveable* gh, int target_x, int target_y)
{
Moveable::Direction prevDirection = gh->getDirection();
int direction_x;
int direction_y;
int ghost_x = gh->getX();
int ghost_y = gh->getY();

direction_x = ghost_x - target_x;
direction_y = ghost_y - target_y;

if (abs(direction_x) >= abs(direction_y) && direction_x > 0)
	{
		if (prevDirection != Moveable::LEFT && internalMap->isWall(ghost_x -1, ghost_y))
		{
			return (Moveable::LEFT);
		}
		else if(direction_y > 0 && internalMap->isWall(ghost_x, ghost_y -1) && prevDirection != Moveable::DOWN)
		{
			return (Moveable::DOWN);
		}
		else if(internalMap->isWall(ghost_x, ghost_y +1) && prevDirection != Moveable::UP)
		{
			return (Moveable::UP);
		}
		else 
		return (Moveable::RIGHT );
	}
if (abs(direction_x) > abs(direction_y) && direction_x <= 0)
	{
		if(prevDirection != Moveable::RIGHT && internalMap->isWall(ghost_x +1, ghost_y))
		{
			return (Moveable::RIGHT);
		}
		else if(direction_y > 0 && internalMap->isWall(ghost_x, ghost_y -1) && prevDirection != Moveable::DOWN)
		{
			return (Moveable::DOWN);
		}
		else if(internalMap->isWall(ghost_x, ghost_y +1) && prevDirection != Moveable::UP)
		{
			return (Moveable::UP);
		}
		else 
		return (Moveable::LEFT);
	}
	
if (abs(direction_x) < abs(direction_y) && direction_y < 0)
	{
		if(prevDirection != Moveable::UP && internalMap->isWall(ghost_x, ghost_y + 1))
		{
			return (Moveable::UP);
		}
		else if(direction_x > 0 && internalMap->isWall(ghost_x-1, ghost_y) && prevDirection != Moveable::LEFT)
		{
			return (Moveable::LEFT);
		}
		else if(internalMap->isWall(ghost_x + 1, ghost_y) && prevDirection != Moveable::RIGHT)
		{
			return (Moveable::RIGHT);
		}
		else 
		return (Moveable::DOWN);
	}
//if (direction_x < direction_y && direction_y => 0) BORDE INTE BEH�VAS V�L?
//	{
		if(prevDirection != Moveable::DOWN && internalMap->isWall(ghost_x, ghost_y + 1))
		{
			return (Moveable::DOWN);
		}
		else if(direction_x > 0 && internalMap->isWall(ghost_x-1, ghost_y) && prevDirection != Moveable::LEFT)
		{
			return (Moveable::LEFT);
		}
		else if(internalMap->isWall(ghost_x + 1, ghost_y) && prevDirection != Moveable::RIGHT)
		{
			return (Moveable::RIGHT);
		}
		else 
		return (Moveable::UP);
	//}
  return Moveable::UP;

	
}
