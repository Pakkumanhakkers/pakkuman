/**
 * @file Pacman.cpp
 *
 *  Created on: 16 dec 2013
 * @author ivar
 */

#include "Pacman.h"

#include "Command.h"
#include "GameEngine.h"
#include <iostream>
Pacman::~Pacman()
{
}

Pacman::Pacman() :
  health_{ALIVE}
{
}

Pacman::Pacman(double x, double y, Sprite* sprite) :
  health_{ALIVE}
{
  setX(x);
  setY(y);
  setSprite(sprite);
}

void
Pacman::setState(int state)
{
  health_ = Pacman::Health(state);
}

int
Pacman::getState()
{
  return health_;
}

void
Pacman::die(GameEngine* gameEngine)
{
  gameEngine->publishCommand(new StateCommand(this, Pacman::DEAD));
}

void
Pacman::spawn(GameEngine* gameEngine, int x, int y)
{
  gameEngine->publishCommand(new StateCommand(this, Pacman::ALIVE));
  gameEngine->publishCommand(new MoveCommand(this, x, y));
}
