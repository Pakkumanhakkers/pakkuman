/**
 * @file Command.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "Command.h"

#include <iterator>
#include <list>

#include "Ghost.h"
#include "GameInstance.h"

using namespace std;

void MoveCommand::execute()
{
  preX_ = object_->getX();
  preY_ = object_->getY();
  object_->setX(x_);
  object_->setY(y_);
}

void MoveCommand::undo()
{
  object_->setX(preX_);
  object_->setY(preY_);
}

void SpriteCommand::execute()
{
  preSprite_ = object_->getSprite();
  object_->setSprite(sprite_);
}

void SpriteCommand::undo()
{
  object_->setSprite(preSprite_);
}

void DirectCommand::execute()
{
  preDirection_ = object_->getDirection();
  object_->setDirection(direction_);
}

void DirectCommand::undo()
{
  object_->setDirection(preDirection_);
}

void SpeedCommand::execute()
{
  preSpeed_ = object_->getSpeed();
  object_->setSpeed(speed_);
}

void SpeedCommand::undo()
{
  object_->setSpeed(preSpeed_);
}

void ScoreCommand::execute()
{
  game_->score += score_;
}

void ScoreCommand::undo()
{
  game_->score -= score_;
}

void LifeCommand::execute()
{
  game_->lives += life_;
}

void LifeCommand::undo()
{
  game_->lives -= life_;
}

void StateCommand::execute()
{
  preState_ = object_->getState();
  object_->setState(state_);
}

void StateCommand::undo()
{
  object_->setState(preState_);
}

void SickGhostCommand::execute()
{
  for (Ghost* g : game_->ghosts)
  {
    g->changeSickness(sick_);
  }
}

void SickGhostCommand::undo()
{
  for (Ghost* g : game_->ghosts)
  {
    g->changeSickness(-sick_);
  }
}
