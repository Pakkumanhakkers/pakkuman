/*
 * main.cpp
 *
 *  Created on: 2 dec 2013
 *      Author: tor
 */
/* Ska inte main se ut typ såhär? */


#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

	GameEngine* main = new GameEngine();

	GameEngine->GameLoop();

	delete main;


	return 0;
}
