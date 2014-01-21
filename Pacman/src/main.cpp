/*
 * main.cpp
 *
 *  Created on: 2 dec 2013
 *      Author: tor
 */

#include <cmath>
#include <iostream>

#include "DefaultPhysicsComponent.h"
#include "Direction.h"
#include "GameEngine.h"
#include "Map.h"
#include "Pacman.h"

using namespace std;


void moveTest(Map& map, double x, double y)
{
  Pacman go1(x, y, nullptr);
  go1.setSpeed(0.25);

  cout << "Walls:" << endl;
  for (double dy = -1.0; dy < 2.0; dy += 1.0)
  {
    for (double dx = -1.0; dx < 2.0; dx += 1.0)
    {
      cout << (map.isWall(int(x + dx), int(y + dy)) ? "#" : ".");
    }
    cout << endl;
  }

  //cout << x << ", " << y << " is wall: " << map.isWall(x, y) << endl;
  cout << "Can move right, down, left, up:" << endl;
  cout << DefaultPhysicsComponent::canMove(&map, &go1, Direction::RIGHT);
  cout << DefaultPhysicsComponent::canMove(&map, &go1, Direction::DOWN);
  cout << DefaultPhysicsComponent::canMove(&map, &go1, Direction::LEFT);
  cout << DefaultPhysicsComponent::canMove(&map, &go1, Direction::UP);
  cout << endl;
}


void test()
{
  Map map(nullptr, nullptr);
  map.loadFile("R/Map.txt");
  moveTest(map, 1.0, 1.0);
  moveTest(map, 6.0, 6.0);
  moveTest(map, 5.75, 6.0);
  moveTest(map, 5.875, 6.0);
  moveTest(map, 5.875, 5.875);

  cout << abs(0.1) << abs(-0.1) << round(0.1);
}

int main(int argc, char* argv[]) {
  //test();
  //return 0;

  GameEngine gameEngine = GameEngine();

  gameEngine.initGame();

  while (true)
    gameEngine.gameLoop();

  return 0;
}
