/**
 * GameEngine.h
 *
 *  Created on: 2 dec 2013
 *      Author: tor
 */

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "GameInstance.h"

class Map;
class Sound;

/**
 * Är samordnare för spelvärlden och menyn.
 */
class GameEngine
{
public:
  void loop();

  void publishCommand(Command*);
  void publishTimer(Timer*);
  //void publishSound(Sound*);
  //void publishSFX(Effect*);

  Map* getMap();
  GameInstance* getGame();

private:
  void update();
  void draw();

  CommandManager command_manager_;
  GameInstance game_instance_;
  Map map_;
};

#endif /* GAMEENGINE_H */
