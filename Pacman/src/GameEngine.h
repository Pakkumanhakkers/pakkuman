/**
 * GameEngine.h
 *
 *  Created on: 2 dec 2013
 *      Author: tor
 */

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "GameInstance.h"

/**
 * Är samordnare för spelvärlden och menyn.
 */
class GameEngine
{
public:
  void loop();
  void get();
private:
  void update();
  void draw();
  GameInstance game_instance_;
};

#endif /* GAMEENGINE_H */
