/**
 * @file AiInputComponent.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "AiInputComponent.h"

//#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Pathfinder.h"

class GameEngine;
class Moveable;

//konstruktor
AiInputComponent::AiInputComponent(Map* map, PathFinder* inpathfinder)
{
	internalMap = map;
	pathfinder = inpathfinder;
}

void AiInputComponent::update(Moveable* moveable, GameEngine* gameengine)
{
	AiInputComponent::AiType Ai = CurrentAi; //erik är bäst
	//Det vi egentligen vill gÃ¶ra Ã¤r att fÃ¥ koordinaterna till pacman
	updateDirection(Ai,moveable, gameengine);
}

AiInputComponent::AiType AiInputComponent::getAi()
{
	return CurrentAi;
}

void AiInputComponent::setAi(AiType ai)
{
	CurrentAi = ai;
}

Moveable::Direction AiInputComponent::updateDirection(AiInputComponent::AiType Ai, Moveable* ghost, GameEngine* gameengine)
{
	int target_x{0};
	int target_y{0};
	int slump;
	if (Ai == AiInputComponent::AiType::CHASE)
	{
		target_x = gameengine->getGame()->pacman->getX();
		target_y = gameengine->getGame()->pacman->getY();
		return (pathfinder->getDirection(ghost,target_x,target_y));
	}
	else if (Ai == AiInputComponent::AiType::RANDOM)
		return getRandom(ghost->getX(), ghost->getY());
	else if (Ai == AiInputComponent::AiType::HOME)
	{
		target_x = internalMap->getGhostX();
		target_y = internalMap->getGhostY();
		return (pathfinder->getDirection(ghost,target_x,target_y));
	}
	else //if (Ai == AiInputComponent::AiType::SCATTER)
		//slumpar mellan RANDOM och 5*(pacmans position)
	{
		srand (time(NULL));
		slump = rand() % 1;
		if (slump == 0)
			return getRandom(ghost->getX(), ghost->getY());
		else
		{
			target_x = 5*gameengine->getGame()->pacman->getX();
			target_y = 5*gameengine->getGame()->pacman->getY();
			return (pathfinder->getDirection(ghost,target_x,target_y));
		}
	}
}
	

bool AiInputComponent::Valid(int ghost_x, int ghost_y, int direction) // isWall måste kallas med ett mapobjekt??
{
	if (direction == 0 && internalMap->isWall(ghost_x - 1, ghost_y))
		return false;
	else if (direction == 1 && internalMap->isWall(ghost_x + 1, ghost_y))
		return false;
	else if (direction == 2 && internalMap->isWall(ghost_x, ghost_y +1))
		return false;
	else if (direction == 3 && internalMap->isWall(ghost_x, ghost_y -1))
		return false;
	else
	return true;
}

Moveable::Direction AiInputComponent::getRandom(int ghost_x, int ghost_y)
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
			return Moveable::LEFT;
			case(1):
			return Moveable::RIGHT;
			case(2):
			return Moveable::UP;
			case(3):
			return Moveable::DOWN;
		}
}
