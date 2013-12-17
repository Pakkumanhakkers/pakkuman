/**
 * GameEngine.h
 *
 *  Created on: 2 dec 2013
 *      Author: tor
 */

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>

#include "CommandManager.h"
#include "DefaultPhysicsComponent.h"
#include "EaterPhysicsComponent.h"
#include "GameInstance.h"
#include "GhostGraphicComponent.h"
#include "GraphicEngine.h"
#include "KeyboardInputComponent.h"
#include "Map.h"
#include "PathFinder.h"
#include "Score.h"
#include "Settings.h"
#include "Sprite.h"
#include "Timer.h"

class AiInputComponent;

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
  GameEngine();

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

  int currentTime_;
  int gameState_;

  Score points;

  Settings settings_;
  GraphicEngine graphics_;
  CommandManager commandManager_;
  GameInstance gameInstance_;

  Sprite spritePacman;
  Sprite spriteGhost;
  Sprite spriteSickGhost;
  Sprite spriteBlinkGhost;
  Sprite spriteEyes;
  Sprite spriteWall;
  Sprite spriteFloor;
  Sprite spriteDot;
  Sprite spriteCherry;

  KeyboardInputComponent keyboardInputComponent;
  DefaultPhysicsComponent defaultPhysicsComponent;
  EaterPhysicsComponent eaterPhysicsComponent;

  std::vector<AiInputComponent*> ghostAi;
  GhostGraphicComponent ghostGraphicComponent;

  Map map_;
  PathFinder pathFinder_;
};

#endif /* GAMEENGINE_H */
