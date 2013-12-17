/**
 * @file Food.cpp
 *
 *  Created on: 12 dec 2013
 * @author ivar
 */

#include "Food.h"

#include "Command.h"
#include "GameEngine.h"


Food::Food(double x, double y, Sprite* sprite, int score) :
  GameObject{x, y, sprite}, score_{score}, health_{NORMAL} {}

void
Food::eat(GameEngine* gameEngine)
{
  if (getState() != Food::EATEN)
  {
    gameEngine->publishCommand(new ScoreCommand{gameEngine->getGame(), score_});
    gameEngine->publishCommand(new StateCommand{this, Food::EATEN});
  }
}

int
Food::getState()
{
  return health_;
}

void
Food::setState(int state)
{
  health_ = Food::Health(state);
}
