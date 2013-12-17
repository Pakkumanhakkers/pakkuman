/**
 * @file GameInstance.cpp
 *
 *  Created on: 17 dec 2013
 * @author ivar
 */

#include "GameInstance.h"

#include <iterator>

#include "Ghost.h"
#include "Pacman.h"


GameInstance::GameInstance() :
lives{0}, score{0}, ghostsEaten{}, pacman{nullptr}, ghosts{}, food{}
{
}

GameInstance::~GameInstance()
{
  for (auto itr = ghosts.begin(); itr < ghosts.end();)
  {
    delete *itr;
    itr = ghosts.erase(itr);
  }

  for (auto itr = ghosts.begin(); itr < ghosts.end();)
  {
    delete *itr;
    itr = ghosts.erase(itr);
  }

  delete pacman;
}
