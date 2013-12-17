/*
 * GameInstance.h
 *
 *  Created on: 2 dec 2013
 *      Author: tor
 */

#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <vector>

#include "Food.h"
#include "Moveable.h"
#include "Ghost.h"
#include "Pacman.h"

/**
 * Representerar data för en spelomgång
 */
struct GameInstance
{
  GameInstance();
  ~GameInstance();

  int lives;
  int score;
  int ghostsEaten;

  Pacman* pacman;
  std::vector<Ghost*> ghosts;
  std::vector<Food*> food;
};

#endif /* GAMEINSTANCE_H */
