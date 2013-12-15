/**
 * @file AiInputComponent.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AiInputComponent.h"

class GameEngine;
class Moveable;

void AiInputComponent::update(Moveable& moveable, GameEngine& gameengine)
{
	AiType Ai = moveable->getAiType(); //erik är bäst
	ghost_x = moveable->getX();
	ghost_y = moveable->getY();
	target_x = gameengine->Wherespacman_x();
	taget_y = gameengine->Wherespacman_y();	//Det vi egentligen vill gÃ¶ra Ã¤r att fÃ¥ koordinaterna till pacman
	updateDirection(Ai)
}

Direction AiInputComponent::updateDirection(AiType Ai, int ghost_x, int ghost_y, int target_x, int target_y)
{
	if (Ai == CHASE)
	return pathfinder->getDirection(ghost_x,ghost_y,target_x,target_y);
	else if (Ai == RANDOM)
	return getRandom(ghost_x, ghost_y);
}
	

bool AiInputComponent::Valid(int ghost_x, int ghost_y, int direction) // isWall måste kallas med ett mapobjekt??
{
	if (direction == 0 && isWall(ghost_x - 1, ghost_y))
		return false;
	else if (direction == 1 && isWall(ghost_x + 1, ghost_y))
		return false;
	else if (direction == 2 && isWall(ghost_x, ghost_y +1)
		return false;
	else if (direction == 3 && isWall(ghost_x, ghost_y -1)
		return false;
	else
	return true;
}

Direction AiInputComponent::getRandom(int ghost_x, int ghost_y)
{
	int direction;
	srand (time(NULL));
	while (!Valid(ghost_x,ghost_y,direction))
	{
		direction = rand() % 3 + 0;
	}	
		switch(direction)
		{
			case(0):
			return LEFT;
			case(1):
			return RIGHT;
			case(2):
			return UP;
			case(3):
			return DOWN;
		}
}
