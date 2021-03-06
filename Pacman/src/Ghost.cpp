/**
 * @file Ghost.cpp
 *
 *  Created on: 13 dec 2013
 * @author Erik N inte philip iallafall
 */

#include "Ghost.h"

#include "Command.h"
#include "GameInstance.h"
#include "Pacman.h"
#include "GameEngine.h"

using namespace std;

Ghost::~Ghost()
{
}

Ghost::Ghost() :
  health_{NORMAL}, sickness_{0}, score_{100}
{
}

Ghost::Ghost(double x, double y, Sprite* sprite) :
  health_{NORMAL}, sickness_{0}, score_{100}
{
  setX(x);
  setY(y);
  setSprite(sprite);
}

int
Ghost::getState()
{
  return health_;
}

void
Ghost::setState(int state)
{
  health_ = Ghost::Health(state);
}

void
Ghost::changeSickness(int sick)
{
  sickness_ += sick;
  if (getState() != Ghost::Health::EATEN)
  {
    if (sickness_ > 1)
    {
      setState(Ghost::Health::EATABLE);
    }
    else if (sickness_ == 1 && getState() != Ghost::Health::NORMAL)
    {
      setState(Ghost::Health::EATABLE_BLINK);
    }
    else
    {
      setState(Ghost::Health::NORMAL);
    }
  }
}

int
Ghost::getSickness()
{
  return sickness_;
}

void Ghost::eat(GameEngine* gameEngine)
{
  switch (health_)
  {
    case Ghost::EATABLE:
    case Ghost::EATABLE_BLINK:
      die(gameEngine);
      break;
    case Ghost::NORMAL:
    case Ghost::SLEEP:
      gameEngine->getGame()->pacman->die(gameEngine);
      break;
    default:
      break;
  }
}

void
Ghost::die(GameEngine* gameEngine)
{
  gameEngine->publishCommand(new GhostEatenCommand(gameEngine->getGame(), 1));
  gameEngine->publishCommand(new ScoreCommand(gameEngine->getGame(),
      score_ * gameEngine->getGame()->ghostsEaten));

  gameEngine->publishCommand(new StateCommand(this, Ghost::Health::EATEN));
}

void
Ghost::spawn(GameEngine* gameEngine, int x, int y)
{
  gameEngine->publishCommand(new MoveCommand(this, x, y));
  gameEngine->publishCommand(new StateCommand(this, Ghost::NORMAL));
}
