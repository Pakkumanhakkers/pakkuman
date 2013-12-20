/**
 * @file GameEngine.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#include "GameEngine.h"

#include "SDL2/SDL_timer.h"
#include <vector>

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
#include <iostream>
//#include "Timer.h"

GameEngine::GameEngine() :
  currentTime_{0},
  gameState_{PLAY},

  settings_{},
  graphics_{},
  commandManager_{},
  gameInstance_{},

  // init sprites for shared use
  spritePacman{"R/Pacman.png"},
  spriteGhost{"R/Ghost.png"},
  spriteSickGhost{"R/sickGhost.png"},
  spriteBlinkGhost{"R/blinkGhost.png"},
  spriteEyes{"R/eyes.png"},
  spriteWall{"R/Wall.png"},
  spriteFloor{"R/Floor.png"},
  spriteDot{"R/Dot.png"},
  spriteCherry{"R/Cherry.png"},

  // init components for shared use
  keyboardInputComponent{},
  defaultPhysicsComponent{},
  eaterPhysicsComponent{},

  ghostGraphicComponent{&spriteGhost, &spriteSickGhost, &spriteBlinkGhost,
    &spriteEyes},

  // init map
  map_{&spriteWall, &spriteFloor},
  pathFinder_{&map_}
{
  map_.loadFile("R/Map.txt");


  gameInstance_.lives = settings_.initLives;

  int px = map_.getPacmanX();
  int py = map_.getPacmanY();
  int gx = map_.getGhostX();
  int gy = map_.getGhostY();

  Pacman* pacman = new Pacman{double(px), double(py), &spritePacman};
  pacman->addComponent(&keyboardInputComponent);
  pacman->addComponent(&defaultPhysicsComponent);
  pacman->addComponent(&eaterPhysicsComponent);
  pacman->setSpeed(settings_.pacmanSpeed / settings_.fps);

  gameInstance_.pacman = pacman;

  for (int i{0}; i < settings_.ghostCount; ++i)
  {
    AiInputComponent::AiType aiType;

    if (i == 0)
    {
      aiType = AiInputComponent::RANDOM;
    }
    else
    {
      aiType = AiInputComponent::CHASE;
    }

    AiInputComponent* ai = new AiInputComponent(getMap(), getPathFinder(),
        aiType);
    ghostAi.push_back(ai);

    Ghost* ghost = new Ghost{double(gx), double(gy), &spriteDot};
    ghost->addComponent(ai);
    ghost->addComponent(&defaultPhysicsComponent);
    ghost->addComponent(&ghostGraphicComponent);
    ghost->setSpeed(settings_.ghostSpeed / settings_.fps);

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

GameEngine::~GameEngine()
{
}

void GameEngine::initGame()
{
  currentTime_ = SDL_GetTicks();
  nextLevel();
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

  int foodLeft{0};
  for (Food* food : gameInstance_.food)
  {
    if (food->getState() == Food::NORMAL)
    {
      ++foodLeft;
    }
  }

  if (!foodLeft)
  {
    nextLevel();
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

  //Points should be drawn, I put it here.
  points_.setScore(gameInstance_.score);
  points_.draw(&graphics_);

  graphics_.show();
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
  gameInstance_.score = 0;
  nextLevel();
}

void
GameEngine::nextLife()
{
  commandManager_.clearFutureTimers();

  gameInstance_.pacman->spawn(this, map_.getPacmanX(), map_.getPacmanY());

  Ghost* first{nullptr};

  for (Ghost* ghost : gameInstance_.ghosts)
  {
    if (first == nullptr)
    {
      first = ghost;
    }

    ghost->spawn(this, map_.getGhostX(), map_.getGhostY());
  }

  if (first != nullptr)
  {
    publishCommand(new SickGhostCommand(&gameInstance_,
        - first->getSickness()));
  }
}

void
GameEngine::nextLevel()
{
  nextLife();

  for (Food* food : gameInstance_.food)
  {
    food->setState(int(Food::NORMAL));
  }

  int sleepMultiplier{0};
  int sleepTime{settings_.ghostSleep};

  for (Ghost* ghost : gameInstance_.ghosts)
  {
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
