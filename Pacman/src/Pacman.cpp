/**
 * @file Pacman.cpp
 *
 *  Created on: 16 dec 2013
 * @author ivar
 */

#include "Pacman.h"

Pacman::~Pacman()
{
}

Pacman::Pacman() :
  health_{ALIVE}
{
}

void
Pacman::setState(int state)
{
  health_ = state;
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
