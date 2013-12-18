/**
 * @file SuperFood.cpp
 *
 *  Created on: 16 dec 2013
 * @author ivar
 */

#include "SuperFood.h"

#include "Command.h"
#include "GameEngine.h"
#include "Settings.h"
#include "Timer.h"

SuperFood::SuperFood(double x, double y, Sprite* sprite, int score) :
  Food{x, y, sprite, score}
{
}

void
SuperFood::eat(GameEngine* gameEngine)
{
  if (getState() != Food::EATEN)
  {
    Food::eat(gameEngine);

    Settings* s = gameEngine->getSettings();


    gameEngine->publishCommand(new GhostEatenCommand(gameEngine->getGame(), 0));

    gameEngine->publishCommand(new SickGhostCommand(gameEngine->getGame(), 2));

    gameEngine->publishTimer(new Timer(new SickGhostCommand(
        gameEngine->getGame(), -1),
        s->sickTime - s->blinkTime));
    gameEngine->publishTimer(new Timer(new SickGhostCommand(
        gameEngine->getGame(), -1),
        s->sickTime));
  }
}
