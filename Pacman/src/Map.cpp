/**
 * @file Map.cpp
 *
 *  Created on: 12 dec 2013
 * @author Erik N inte philip iallafall
 */
 
#include <ifstream>
#inluce <iostream>
#include <Map.h>
using namespace std;
 
//Konstruktor
Map::Map(SDL_Renderer* sent_renderer)
{
	MapRenderer = sent_renderer;
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

TileType Map::getTileType(int x, int y)
{
	return MapArray[x][y];
}
void drawMapArray()
{
	for(int cor_y = 0;cor_y<20;++cor_y)
	{
		for(int cor_x = 0;cor_x<15;cor_x++)
		{
			switch (MapArray{cor_x][cor_y])
			case "#":
			GraphicEngine->DrawSprite(WallSprite,cor_x,cor_y,0);
			case ".":
			GraphicEngine->DrawSprite(FloorSprite,cor_x,cor_y,0);
			case "p":
			GraphicEngine->DrawSprite(FloorSprite,cor_x,cor_y,0);
			case "g":
			GraphicEngine->DrawSprite(FloorSprite,cor_x,cor_y,0);
			case "c":
			GraphicEngine->DrawSprite(FloorSprite,cor_x,cor_y,0);
			case "0":
			GraphicEngine->DrawSprite(FloorSprite,cor_x,cor_y,0);
		}
	}
}
void initMapArray() 	//Fyller på en array utifrån Map.txt
{
	int cor_x;
	int cor_y;
	char TempChar;
	ifstream inputMap;
	inputMap.open("Map.txt");
	 for(cor_y=0;cor_y<20;++cor_y)
	{
		for(cor_x=0;cor_x<15;cor_x++) 
		{
			inputMap >> TempChar;
			switch (TempChar)
			case "#":
			MapArray[cor_x][cor_y] = WALL;
			case ".":
			MapArray[cor_x][cor_y] = DOT;
			case "p":
			MapArray[cor_x][cor_y] = PACMAN_SPAWN;
			case "g":
			MapArray[cor_x][cor_y] = GHOST_SPAWN;
			case "c":
			MapArray[cor_x][cor_y] = CHERRY;
			case "0":
			MapArray[cor_x][cor_y] = FLOOR;
		}
	}
}
