/**
 * @file GameEngine.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

#include "GameEngine.h"

#include <vector>

#include "Command.h"
#include "CommandManager.h"
#include "Food.h"
#include "Ghost.h"
#include "Map.h"
#include "Pacman.h"
#include "Settings.h"

class Timer;

void
GameEngine::initGame()
{
  int px = map_.getPacmanX();
  int py = map_.getPacmanY();
  int gx = map_.getPacmanX();
  int gy = map_.getGhostY();

  gameInstance_.pacman = new Pacman{px, py, &spriteDot};
  gameInstance_.ghosts.push_back(new Ghost{gx, gy, &spriteDot});
}

void
GameEngine::gameLoop()
{
  int newTime = SDL_GetTicks();
  while (currentTime_ < newTime)
  {
    updateGame();
    currentTime_ += settings_.frameTime;
  }

  drawGame();
}

void
GameEngine::updateGame()
{
  gameInstance_.pacman->update(this);

  for (Moveable* moveable : gameInstance_.ghosts)
  {
    moveable->update(this);
  }
}

void
GameEngine::drawGame()
{
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

void
GameEngine::lifeLost()
{
  if (gameInstance_.lives <= 0)
  {
    gameOver();
  }
  else
  {

  }
}

void
GameEngine::gameOver()
{

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
