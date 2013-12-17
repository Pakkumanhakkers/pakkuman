/**
 * @file GameEngine.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#include "GameEngine.h"

#include <SDL_timer.h>
#include <vector>

#include "AiInputComponent.h"
#include "Command.h"
#include "CommandManager.h"
#include "DefaultPhysicsComponent.h"
#include "EaterPhysicsComponent.h"
#include "Ghost.h"
#include "GhostGraphicComponent.h"
#include "GhostInputComponent.h"
#include "GraphicEngine.h"
#include "KeyboardInputComponent.h"
#include "Map.h"
#include "Pacman.h"
#include "PathFinder.h"
#include "Score.h"
#include "Settings.h"
#include "Sprite.h"
#include "SuperFood.h"
#include "Timer.h"

GameEngine::GameEngine()
{
  currentTime_ = 0;
  game_state_ = GameEngine::PLAY;

  points = Score();

  settings_ = Settings();
  graphics_ = GraphicEngine();
  commandManager_ = CommandManager();
  gameInstance_ = GameInstance();

  // init sprites for shared use
  spriteCherry = Sprite("Cherry.png");
  spriteDot = Sprite("Dot.png");
  spriteWall =  Sprite("Wall.png");
  spriteFloor =  Sprite("Floor.png");
  spritePacman =  Sprite("Pacman.png");
  spriteGhost = Sprite("Ghost.png");
  spriteSickGhost =  Sprite("sickGhost.png");
  spriteBlinkGhost = Sprite("blinkGhost.png");
  spriteEyes = Sprite("eyes.png");

  // init components for shared use
  keyboardInputComponent{KeyboardInputComponent{}};
  ghostInputComponent{GhostInputComponent{AiInputComponent{&map_,
      &pathFinder_}}};
  defaultPhysicsComponent{DefaultPhysicsComponent{}};
  eaterPhysicsComponent{EaterPhysicsComponent{}};
  ghostGraphicComponent{GhostGraphicComponent{&spriteGhost,
      &spriteSickGhost, &spriteBlinkGhost, &spriteEyes}};

  // init map
  map_ = Map{&spriteWall, &spriteFloor};
  map_.loadFile("Map.txt");

  pathFinder_ = PathFinder(&map_);
}

void GameEngine::initGame()
{
  int px = map_.getPacmanX();
  int py = map_.getPacmanY();
  int gx = map_.getGhostX();
  int gy = map_.getGhostY();

  // init game objects
  Pacman* pacman = new Pacman{px, py, &spritePacman};
  pacman->addComponent(&keyboardInputComponent);
  pacman->addComponent(&defaultPhysicsComponent);
  pacman->addComponent(&eaterPhysicsComponent);

  gameInstance_.pacman = pacman;

  for (int i = 0; i < settings_.ghostCount; ++i)
  {
    Ghost* ghost{new Ghost{gx, gy, &spriteGhost}};
    ghost->addComponent(&ghostInputComponent);
    ghost->addComponent(&defaultPhysicsComponent);
    ghost->addComponent(&ghostGraphicComponent);

    gameInstance_.ghosts.push_back(ghost);
  }

  for (Map::FoodInfo& food : *(map_.getFoodInfo()))
  {
    Food* f{nullptr};

    switch (food.type)
    {
      case Map::DOT:
        f = new Food{food.x, food.y, &spriteDot, settings_.scoreDot};
        break;
      case Map::CHERRY:
        f = new SuperFood{food.x, food.y, &spriteCherry, settings_.scoreFruit};
        break;
    }

    if (f != nullptr)
    {
      gameInstance_.food.push_back(f);
    }
  }
}

void
GameEngine::gameLoop()
{
  int newTime = SDL_GetTicks();
  while (currentTime_ < newTime)
  {
    commandManager_.setCurrentTime(currentTime_);
    commandManager_.checkTimer();
    updateGame();
    currentTime_ += settings_.frameTime;
  }

  drawGame();
}

void
GameEngine::updateGame()
{
  int preLives = gameInstance_.lives;
  gameInstance_.pacman->update(this);

  for (Moveable* moveable : gameInstance_.ghosts)
  {
    moveable->update(this);
  }

  if (gameInstance_.lives < preLives)
  {
    lifeLost();
  }
}

void
GameEngine::drawGame()
{
  graphics_.setCurrentTime(currentTime_);

  map_.draw(&graphics_);

  for (Food* object : gameInstance_.food)
  {
    object->draw(&graphics_);
  }

  for (Moveable* object : gameInstance_.ghosts)
  {
    object->draw(&graphics_);
  }

  gameInstance_.pacman->draw(&graphics_);
}

GameEngine::~GameEngine() {

	delete GraphicEngine;
}


void
GameEngine::lifeLost()
{
  if (gameInstance_.lives <= 0)
  {
    gameOver();
  }
  else
  {
    nextLife();
  }
}

void
GameEngine::gameOver()
{
// TODO
}

void
GameEngine::nextLife()
{
  commandManager_.clearFutureTimers();

  gameInstance_.pacman->spawn(this, map_.getPacmanX(), map_.getPacmanY());

  int sleepMultiplier{0};
  int sleepTime{settings_.ghostSleep};

  for (Ghost* ghost : gameInstance_.ghosts)
  {
    ghost->spawn(this, map_.getGhostX(), map_.getGhostY());

    if (sleepMultiplier > 0)
    {
      publishCommand(new StateCommand(ghost, Ghost::SLEEP));
      publishTimer(new Timer(
        new StateCommand(ghost, Ghost::NORMAL), sleepMultiplier * sleepTime));
    }
    ++sleepMultiplier;
  }
}

void
GameEngine::publishCommand(Command* command)
{
  commandManager_.add(command);
  command->execute();
}

void
GameEngine::publishTimer(Timer* timer)
{
  commandManager_.add(timer);
}

Map*
GameEngine::getMap()
{
  return &map_;
}

GameInstance*
GameEngine::getGame()
{
  return &gameInstance_;
}

PathFinder*
GameEngine::getPathFinder()
{
  return &pathFinder_;
}

Settings*
GameEngine::getSettings()
{
  return &settings_;
}
