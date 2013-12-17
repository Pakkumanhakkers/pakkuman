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
#include "Food.h"
#include "Ghost.h"
#include "GraphicEngine.h"
#include "Map.h"
#include "Pacman.h"
#include "Settings.h"
#include "Sprite.h"

class Timer;

void
GameEngine::initGame()
{

	spriteCherry = Sprite("Cherry.png");
	spriteFood = Sprite("Dot.png");
	spriteWall =  Sprite("Wall.png");
	spriteFloor =  Sprite("Floor.png");
	spritePacman =  Sprite("Pacman.png");
	spriteGhost = Sprite("Ghost.png");
	spriteSickGhost =  Sprite("sickGhost.png");
	spriteBlinkGhost = Sprite("blinkGhost.png");
	spriteEyes = Sprite("eyes.png");


  map_ = Map{&spriteWall, &spriteFloor};
  map_->loadFile("Map.txt");
  pathFinder_ = PathFinder(getMap());

  

  int px = map_.getPacmanX();
  int py = map_.getPacmanY();
  int gx = map_.getGhostX();
  int gy = map_.getGhostY();

  gameInstance_.pacman = new Pacman{px, py, &spritePacman};

  for (int i = 0; i < settings_.ghostCount; ++i)
  {
  Ghost* g = new Ghost{gx, gy, &spriteDot};
  AiInputComponent* a = new AiInputComponent(getMap(),getPathFinder());
  ghostAi.push_back(a);
  g->addComponent(a);
  gameInstance_.ghosts.push_back(g);
  }

  for (Map::FoodInfo& food : *(map_.getFoodInfo()))
  {
    Food* f{nullptr};

    switch (food.type)
    {
      case Map::DOT:
        f = new Food(food.x, food.y, &spriteDot, settings_.scoreDot);
        break;
      case Map::CHERRY:
        f = new SuperFood(food.x, food.y, &spriteCherry, settings_.scoreFruit);
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

  gameInstance_.pacman->draw(&graphics_);

  for (Moveable* object : gameInstance_.ghosts)
  {
    object->draw(&graphics_);
  }

  for (Food* object : gameInstance_.food)
  {
    object->draw(&graphics_);
  }
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
