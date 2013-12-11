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

class Pacman;

/**
 * Representerar data för en spelomgång
 */
struct GameInstance
{
  int lives;
  int score;
  std::vector<Moveable*> moveables;
  std::vector<Food*> food;
  Pacman* pacman;
};

#endif /* GAMEINSTANCE_H */
