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

//Pathfinder tar in ghosts position och en target-position och retunerar en giltlig direction
Direction PathFinder::getDirection(ghost_x,ghost_y, target_x, target_y)
{
Direction prevDirection = getDirection();
int direction_x;
int direction_y;
direction_x = ghost_x - target_x;
direction_y = ghost_y - target_y;

if (direction_x >= direction_y && direction_x > 0)
	{
		if(prevDirection != LEFT && isWall(ghost_x -1, ghost_y)
		{
			setDirection(LEFT);
		}
		else if(direction_y > 0 && isWall(ghost_x, ghost_y -1) && prevDirection != DOWN)
		{
			setDirection(DOWN);
		}
		else if(isWall(ghost_x, ghost_y +1) && prevDirection != UP)
		{
			setDirection(UP);
		}
		else 
		setDirection(RIGHT );
	}
if (direction_x >= direction_y && direction_x < 0)
	{
		if(prevDirection != RIGHT && isWall(ghost_x +1, ghost_y)
		{
			setDirection(prefDirection);
		}
		else if(direction_y > 0 && isWall(ghost_x, ghost_y -1) && prevDirection != DOWN)
		{
			setDirection(DOWN);
		}
		else if(isWall(ghost_x, ghost_y +1) && prevDirection != UP)
		{
			setDirection(UP);
		}
		else 
		setDirection(LEFT);
	}
	
if (direction_x <= direction_y && direction_y < 0)
	{
		if(prevDirection != UP && isWall(ghost_x, ghost_y + 1)
		{
			setDirection(UP);
		}
		else if(direction_x > 0 && isWall(ghost_x-1, ghost_y) && prevDirection != LEFT)
		{
			setDirection(LEFT);
		}
		else if(isWall(ghost_x + 1, ghost_y) && prevDirection != RIGHT)
		{
			setDirection(RIGHT);
		}
		else 
		setDirection(DOWN);
	}
if (direction_x <= direction_y && direction_y > 0)
	{
		if(prevDirection != DOWN && isWall(ghost_x, ghost_y + 1)
		{
			setDirection(DOWN);
		}
		else if(direction_x > 0 && isWall(ghost_x-1, ghost_y) && prevDirection != LEFT)
		{
			setDirection(LEFT);
		}
		else if(isWall(ghost_x + 1, ghost_y) && prevDirection != RIGHT)
		{
			setDirection(RIGHT);
		}
		else 
		setDirection(UP);
	}
	
}
