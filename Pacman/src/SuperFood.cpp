/**
 * @file SuperFood.cpp
 *
 *  Created on: 16 dec 2013
 * @author ivar
 */

#include "SuperFood.h"

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
    gameEngine->publishCommand(new SickGhostCommand(gameEngine, 2));

    gameEngine->publishTimer(new Timer(new SickGhostCommand(gameEngine, -1),
        s->sickTime - s->blinkTime));
    gameEngine->publishTimer(new Timer(new SickGhostCommand(gameEngine, -1),
        s->sickTime));
  }
}
