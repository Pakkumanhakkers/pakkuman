/**
 * @file GameEngine.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#include "GameEngine.h"

#include "SDL2/SDL_timer.h"
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
  gameState_{PLAY},

  points {},

  settings_{},
  graphics_{},
  commandManager_{},
  gameInstance_{},

  // init sprites for shared use
  spritePacman{"img/Pacman.png"},
  spriteGhost{"img/Ghost.png"},
  spriteSickGhost{"img/sickGhost.png"},
  spriteBlinkGhost{"img/blinkGhost.png"},
  spriteEyes{"img/eyes.png"},
  spriteWall{"img/Wall.png"},
  spriteFloor{"img/Floor.png"},
  spriteDot{"img/Dot.png"},
  spriteCherry{"img/Cherry.png"},

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
  map_.loadFile("img/Map.txt");
}

void GameEngine::initGame()
{
  // kan ta hand om tidigare gameInstance och rensa ghostAi
  int px = map_.getPacmanX();
  int py = 12;
  int gx = 7;
  int gy = 10;

  // init game objects
  Pacman* pacman = new Pacman{double(px), double(py), &spritePacman};
  pacman->addComponent(&keyboardInputComponent);
  pacman->addComponent(&defaultPhysicsComponent);
  pacman->addComponent(&eaterPhysicsComponent);
  pacman->setSpeed(2.0 / settings_.fps);

  gameInstance_.pacman = pacman;

  for (int i = 0; i <1; ++i)
  {
    AiInputComponent* ai = new AiInputComponent(getMap(),getPathFinder());
    ghostAi.push_back(ai);

    Ghost* ghost = new Ghost{double(gx), double(gy), &spriteDot};
    ghost->addComponent(ai);
    ghost->addComponent(&defaultPhysicsComponent);
    ghost->addComponent(&ghostGraphicComponent);
    ghost->setSpeed(1.6 / settings_.fps);

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

  currentTime_ = SDL_GetTicks();
}

void
GameEngine::gameLoop()
{
  int newTime = SDL_GetTicks();
  int oldTime = currentTime_;

  while (currentTime_ < newTime)
  {
    commandManager_.setCurrentTime(currentTime_);
    commandManager_.checkTimer();
    updateGame();
    currentTime_ += settings_.frameTime;
  }

  if (oldTime < currentTime_)
  {
    drawGame();
  }

  SDL_Delay(1);
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
  graphics_.update();

  graphics_.setCurrentTime(currentTime_);

  map_.draw(&graphics_);

  for (Food* object : gameInstance_.food)
  {
    if (object->getState() != int(Food::EATEN))
    {
      object->draw(&graphics_);
    }
  }

  for (Moveable* object : gameInstance_.ghosts)
  {
    object->draw(&graphics_);
  }

  gameInstance_.pacman->draw(&graphics_);

  graphics_.show();
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
  gameState_ = GAME_OVER;
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
/*
    if (sleepMultiplier > 0)
    {
      publishCommand(new StateCommand(ghost, Ghost::SLEEP));
      publishTimer(new Timer(
        new StateCommand(ghost, Ghost::NORMAL), sleepMultiplier * sleepTime));
    }
    ++sleepMultiplier;
    */
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
