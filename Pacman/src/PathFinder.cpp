/**
 * @file PathFinder.cpp
 *
 *  Created on: 6 dec 2013
 * @author Erik & Ph
 */

#include "PathFinder.h"

#include <cstdlib>
//#include <iostream>
//#include <random>

#include "Direction.h"
#include "Map.h"
//#include "Moveable.h"


using namespace std;

PathFinder::PathFinder(Map* map): internalMap{map}
{
}

//PathFinder tar in en ghost och en target-position och retunerar en giltlig direction
Direction PathFinder::getDirection(Moveable* gh, int target_x, int target_y)
{
Direction prevDirection = gh->getDirection();
int direction_x;
int direction_y;
int ghost_x = gh->getX();
int ghost_y = gh->getY();

direction_x = ghost_x - target_x;
direction_y = ghost_y - target_y;

if (abs(direction_x) >= abs(direction_y) && direction_x > 0)
	{
		if (prevDirection != Direction::LEFT && internalMap->isWall(ghost_x -1, ghost_y))
		{
			return (Direction::LEFT);
		}
		else if(direction_y > 0 && internalMap->isWall(ghost_x, ghost_y -1) && prevDirection != Direction::DOWN)
		{
			return (Direction::DOWN);
		}
		else if(internalMap->isWall(ghost_x, ghost_y +1) && prevDirection != Direction::UP)
		{
			return (Direction::UP);
		}
		else 
		return (Direction::RIGHT );
	}
if (abs(direction_x) > abs(direction_y) && direction_x <= 0)
	{
		if(prevDirection != Direction::RIGHT && internalMap->isWall(ghost_x +1, ghost_y))
		{
			return (Direction::RIGHT);
		}
		else if(direction_y > 0 && internalMap->isWall(ghost_x, ghost_y -1) && prevDirection != Direction::DOWN)
		{
			return (Direction::DOWN);
		}
		else if(internalMap->isWall(ghost_x, ghost_y +1) && prevDirection != Direction::UP)
		{
			return (Direction::UP);
		}
		else 
		return (Direction::LEFT);
	}
	
if (abs(direction_x) < abs(direction_y) && direction_y < 0)
	{
		if(prevDirection != Direction::UP && internalMap->isWall(ghost_x, ghost_y + 1))
		{
			return (Direction::UP);
		}
		else if(direction_x > 0 && internalMap->isWall(ghost_x-1, ghost_y) && prevDirection != Direction::LEFT)
		{
			return (Direction::LEFT);
		}
		else if(internalMap->isWall(ghost_x + 1, ghost_y) && prevDirection != Direction::RIGHT)
		{
			return (Direction::RIGHT);
		}
		else 
		return (Direction::DOWN);
	}
//if (direction_x < direction_y && direction_y => 0) BORDE INTE BEH�VAS V�L?
//	{
		if(prevDirection != Direction::DOWN && internalMap->isWall(ghost_x, ghost_y + 1))
		{
			return (Direction::DOWN);
		}
		else if(direction_x > 0 && internalMap->isWall(ghost_x-1, ghost_y) && prevDirection != Direction::LEFT)
		{
			return (Direction::LEFT);
		}
		else if(internalMap->isWall(ghost_x + 1, ghost_y) && prevDirection != Direction::RIGHT)
		{
			return (Direction::RIGHT);
		}
		else 
		return (Direction::UP);
	//}
  return Direction::UP;

	
}
