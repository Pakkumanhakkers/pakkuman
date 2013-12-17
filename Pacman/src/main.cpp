/*
 * main.cpp
 *
 *  Created on: 2 dec 2013
 *      Author: tor
 */
/* Ska inte main se ut typ s�h�r? */


#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

  GameEngine gameEngine = GameEngine();

  gameEngine.initGame();

  gameEngine.gameLoop();

  return 0;
}
