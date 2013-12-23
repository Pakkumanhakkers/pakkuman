/**
 * @file PathFinder.cpp
 *
 *  Created on: 6 dec 2013
 * @author Erik & Ph
 */

#include "PathFinder.h"

#include <cstdlib>
#include <iostream>
//#include <random>

#include "Direction.h"
#include "Map.h"
#include <cmath>
#include "Moveable.h"
#include "GameEngine.h"


using namespace std;

PathFinder::PathFinder(Map* map): internalMap{map}
{
}

Direction PathFinder::getDirection2(Moveable* gh, GameEngine* gameengine)
{
	int pacx = gameengine->getGame()->pacman->getX();
	int pacy = gameengine->getGame()->pacman->getY();
	Direction pacmanDirection = gameengine->getGame()->pacman->getDirection();
	if (pacmanDirection == RIGHT)
		return getDirection(gh, pacx + 10, pacy - 5);
		else if (pacmanDirection == LEFT)
			return getDirection(gh, pacx - 10, pacy + 5);
		else if (pacmanDirection == UP)
			return getDirection(gh, pacx - 5, pacy - 10);
		else
			return getDirection(gh, pacx + 5, pacy + 10);
}


//PathFinder tar in en ghost och en target-position och retunerar en giltlig direction
Direction PathFinder::getDirection(Moveable* gh, int target_x, int target_y)
{
Direction prevDirection = gh->getDirection();
int direction_x;
int direction_y;
if (fabs((gh->getX() - round(gh->getX()))) >0.05 || fabs((gh->getY() - round(gh->getY()))) >0.05 )
	return prevDirection;
int ghost_x = round(gh->getX());
int ghost_y = round(gh->getY());
direction_x = ghost_x - target_x;
direction_y = ghost_y - target_y;

if (abs(direction_x) > abs(direction_y) && direction_x >= 0)
	{
		if (prevDirection != Direction::RIGHT && !internalMap->isWall(ghost_x -1, ghost_y))
		{
			return (Direction::LEFT);
		}
		else if(direction_y < 0 && !internalMap->isWall(ghost_x, ghost_y +1) && prevDirection != Direction::UP)
		{
			return (Direction::DOWN);
		}
		else if(!internalMap->isWall(ghost_x, ghost_y - 1) && prevDirection != Direction::DOWN)
		{
			return (Direction::UP);
		}
		else 
		return (Direction::RIGHT );
	}
if (abs(direction_x) > abs(direction_y) && direction_x <= 0)
	{
		if(prevDirection != Direction::LEFT && !internalMap->isWall(ghost_x +1, ghost_y))
		{
			return (Direction::RIGHT);
		}
		else if(direction_y < 0 && !internalMap->isWall(ghost_x, ghost_y +1) && prevDirection != Direction::UP)
		{
			return (Direction::DOWN);
		}
		else if(!internalMap->isWall(ghost_x, ghost_y- 1) && prevDirection != Direction::DOWN)
		{
			return (Direction::UP);
		}
		else if (!internalMap->isWall(ghost_x -1, ghost_y))
		{
		return (Direction::LEFT);
		}
	}
if (abs(direction_x) <= abs(direction_y) && direction_y >= 0)
	{
		if(prevDirection != Direction::DOWN && !internalMap->isWall(ghost_x, ghost_y - 1))
		{
			return (Direction::UP);
		}
		else if(direction_x > 0 && !internalMap->isWall(ghost_x-1, ghost_y) && prevDirection != Direction::RIGHT)
		{
			return (Direction::LEFT);
		}
		else if(!internalMap->isWall(ghost_x + 1, ghost_y) && prevDirection != Direction::LEFT)
		{
			return (Direction::RIGHT);
		}
		else if (!internalMap->isWall(ghost_x, ghost_y+1))
				{
		return (Direction::DOWN);
				}
	}
//if (direction_x < direction_y && direction_y => 0) BORDE INTE BEH�VAS V�L?
//	{
		if(prevDirection != Direction::UP && !internalMap->isWall(ghost_x, ghost_y + 1))
		{
			return (Direction::DOWN);
		}
		else if(direction_x > 0 && !internalMap->isWall(ghost_x-1, ghost_y) && prevDirection != Direction::RIGHT)
		{
			return (Direction::LEFT);
		}
		else if(!internalMap->isWall(ghost_x + 1, ghost_y) && prevDirection != Direction::LEFT)
		{
			return (Direction::RIGHT);
		}
		else 
		{
		 if (!internalMap->isWall(ghost_x, ghost_y - 1))
		 {
			 return (Direction::UP);
		 }
		else if (!internalMap->isWall(ghost_x, ghost_y + 1))
		{
			return (Direction::DOWN);
		}
		else if (!internalMap->isWall(ghost_x + 1, ghost_y))
		{
			return (Direction::RIGHT);
		}
		else return (Direction::LEFT);
		}
}
