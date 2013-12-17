/**
 * @file GameEngine.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#include "GameEngine.h"

#include <SDL_timer.h>
//#include <vector>

#include "AiInputComponent.h"
#include "Command.h"
//#include "CommandManager.h"
//#include "DefaultPhysicsComponent.h"
//#include "EaterPhysicsComponent.h"
#include "Ghost.h"
//#include "GhostGraphicComponent.h"
//#include "GraphicEngine.h"
//#include "KeyboardInputComponent.h"
//#include "Map.h"
#include "Pacman.h"
//#include "PathFinder.h"
//#include "Score.h"
//#include "Settings.h"
#include "Sprite.h"
#include "SuperFood.h"
//#include "Timer.h"

GameEngine::GameEngine() :
  currentTime_{0},
  gameState_{0},

  points {},

  settings_{},
  graphics_{},
  commandManager_{},
  gameInstance_{},

  // init sprites for shared use
  spritePacman{"Pacman.png"},
  spriteGhost{"Ghost.png"},
  spriteSickGhost{"sickGhost.png"},
  spriteBlinkGhost{"blinkGhost.png"},
  spriteEyes{"eyes.png"},
  spriteWall{"Wall.png"},
  spriteFloor{"Floor.png"},
  spriteDot{"Dot.png"},
  spriteCherry{"Cherry.png"},

  // init components for shared use
  keyboardInputComponent{},
  defaultPhysicsComponent{},
  eaterPhysicsComponent{},

  ghostGraphicComponent{&spriteGhost,
      &spriteSickGhost, &spriteBlinkGhost, &spriteEyes},

  // init map
  map_{&spriteWall, &spriteFloor},
  pathFinder_{&map_}
{
  map_.loadFile("Map.txt");
}

void GameEngine::initGame()
{
  // kan ta hand om tidigare gameInstance och rensa ghostAi
  int px = map_.getPacmanX();
  int py = map_.getPacmanY();
  int gx = map_.getGhostX();
  int gy = map_.getGhostY();

  // init game objects
  Pacman* pacman = new Pacman{double(px), double(py), &spritePacman};
  pacman->addComponent(&keyboardInputComponent);
  pacman->addComponent(&defaultPhysicsComponent);
  pacman->addComponent(&eaterPhysicsComponent);

  gameInstance_.pacman = pacman;

  for (int i = 0; i < settings_.ghostCount; ++i)
  {
    Ghost* ghost = new Ghost{double(gx), double(gy), &spriteDot};
    AiInputComponent* ai = new AiInputComponent(getMap(),getPathFinder());
    ghostAi.push_back(ai);

    ghost->addComponent(ai);
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
        f = new Food{double(food.x), double(food.y),
          &spriteDot, settings_.scoreDot};
        break;
      case Map::CHERRY:
        f = new SuperFood{double(food.x), double(food.y),
          &spriteCherry, settings_.scoreFruit};
        break;
      default:
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

GameEngine::~GameEngine()
{
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

  publishCommand(new SickGhostCommand(&gameInstance_,
      - gameInstance_.ghosts.at(0)->getSickness()));
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
