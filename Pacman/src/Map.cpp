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

Map::Map(Sprite* wall, Sprite* floor) :
  wallSprite_{wall}, floorSprite_{floor}, ghostX_{0}, ghostY_{0},
  pacmanX_{0}, pacmanY_{0}
{
}

int Map::getWidth()
{
  return 15;
}

int Map::getHeight()
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

void Map::draw(Graphics* g)
{
  for(int cor_y = 0;cor_y<20;++cor_y)
  {
    for(int cor_x = 0;cor_x<15;cor_x++)
    {
      switch (MapArray[cor_x][cor_y])
      {
      case "#":
        g->drawSprite(wallSprite_,cor_x,cor_y);
        break;
      default:
        g->drawSprite(floorSprite_,cor_x,cor_y);
        break;
      }
    }
  }
}

void Map::loadFile(string fileName) 	//Fyller på en array utifrån Map.txt
{
  int cor_x;
  int cor_y;
  char TempChar;
  ifstream inputMap;
  inputMap.open(fileName.c_str(), ifstream::in);
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

  initMapExtras();
}

void
Map::initMapExtras()
{
  int width = getWidth();
  int height = getHeight();

  for (int i = 0; i < width; ++i)
  {
    for (int j = 0; j < height; ++j)
    {
      switch (getTileType(i, j))
      {
      case Map::TileType::DOT:
        foodInfo_.push_back(FoodInfo{i, j, DOT});
        break;
      case Map::TileType::CHERRY:
        foodInfo_.push_back(FoodInfo{i, j, CHERRY});
        break;
      case Map::TileType::PACMAN_SPAWN:
        pacmanX_ = i;
        pacmanY_ = j;
        break;
      case Map::TileType::GHOST_SPAWN:
        ghostX_ = i;
        ghostY_ = j;
        break;
      }
    }
  }
}

int Map::getPacmanX()
{
  return pacmanX_;
}

int Map::getPacmanY()
{
  return pacmanX_;
}

int Map::getGhostX()
{
  return ghostX_;
}

int Map::getGhostY()
{
  return ghostX_;
}

std::vector<Map::FoodInfo>* Map::getFoodInfo()
{
  return foodInfo_;
}
