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
  enum GameState
  {
    PLAY, PAUSE, GAME_OVER
  };

  virtual ~GameEngine(); 
  
  void initGame();
  void gameLoop();

  void publishCommand(Command*);
  void publishTimer(Timer*);
  //void publishSound(Sound*);
  //void publishSFX(Effect*);

  Map* getMap();
  GameInstance* getGame();
  PathFinder* getPathFinder();
  Settings* getSettings();

private:
  void updateGame();
  void drawGame();
  void lifeLost();
  void gameOver();
  void nextLife();

  Settings settings_;
  GraphicEngine graphics_;
  CommandManager commandManager_;
  GameInstance gameInstance_;
  Map map_;
  PathFinder pathFinder_;
  
  Score points;
  
  Sprite spritePacman;
  Sprite spriteGhost;
  Sprite spriteSickGhost;
  Sprite spriteWall;
  Sprite spriteFloor;
  Sprite spriteDot;
  Sprite spriteCherry;

  int currentTime_;
  int game_state_;
};

#endif /* GAMEENGINE_H */
