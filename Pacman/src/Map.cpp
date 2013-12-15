/**
 * @file Map.cpp
 *
 *  Created on: 12 dec 2013
 * @author Erik N inte philip iallafall
 */
 
#include <fstream>
#include <iostream>
#include <Map.h>
using namespace std;
 
//Konstruktor
Map::Map()
{
}

int Map::getWidth()
{
	return 15;
}

int Map::getWidth()
{
	return 20;
}

bool Map::isWall(int x, int y)
{
	return (MapArray[x][y] == WALL);
}

Map::TileType Map::getTileType(int x, int y)
{
	return MapArray[x][y];
}
void Map::drawMapArray()
{
	for(int cor_y = 0;cor_y<20;++cor_y)
	{
		for(int cor_x = 0;cor_x<15;cor_x++)
		{
			switch (Map::MapArray[cor_x][cor_y])
			case Map::WALL:
				graphicengine->DrawSprite(*WallSprite, (double) cor_x, (double) cor_y,0);
			case Map::FLOOR:
				graphicengine->DrawSprite(*FloorSprite, (double) cor_x, (double) cor_y,0);
			case Map::DOT:
				graphicengine->DrawSprite(*FloorSprite, (double) cor_x, (double) cor_y,0);
			case Map::GHOST_SPAWN:
				graphicengine->DrawSprite(*FloorSprite, (double) cor_x, (double) cor_y,0);
			case Map::CHERRY:
				graphicengine->DrawSprite(*FloorSprite, (double) cor_x, (double) cor_y,0);
			case Map::PACMAN_SPAWN:
				graphicengine->DrawSprite(*FloorSprite, (double) cor_x, (double) cor_y,0);
		}
	}
}
void initMapArray() 	//Fyller på en array utifrån Map.txt
{
	int cor_x;
	int cor_y;
	char TempChar;
	ifstream inputMap;
	inputMap.open("Map.txt", ifstream::in);
	 for(cor_y=0;cor_y<20;++cor_y)
	{
		for(cor_x=0;cor_x<15;cor_x++) 
		{
			inputMap >> TempChar;
			switch (TempChar)
			case "#":
				Map::MapArray[cor_x][cor_y] = Map::WALL;
			case ".":
				Map::MapArray[cor_x][cor_y] = Map::DOT;
			case "p":
				Map::MapArray[cor_x][cor_y] = Map::PACMAN_SPAWN;
			case "g":
				Map::MapArray[cor_x][cor_y] = Map::GHOST_SPAWN;
			case "c":
				Map::MapArray[cor_x][cor_y] = Map::CHERRY;
			case "0":
				Map::MapArray[cor_x][cor_y] = Map::FLOOR;
		}
	}
}
