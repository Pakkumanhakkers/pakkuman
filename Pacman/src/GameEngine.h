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
  Sprite spriteDot = Sprite(nullptr, "", 0, 0);

  void initGame();
  void gameLoop();

  void publishCommand(Command*);
  void publishTimer(Timer*);
  //void publishSound(Sound*);
  //void publishSFX(Effect*);

  Map* getMap();
  GameInstance* getGame();

private:
  void updateGame();
  void drawGame();
  void gameOver();

  Settings settings_;
  Graphics graphics_;
  CommandManager commandManager_;
  GameInstance gameInstance_;
  Map map_;

  int currentTime_;
};

#endif /* GAMEENGINE_H */
