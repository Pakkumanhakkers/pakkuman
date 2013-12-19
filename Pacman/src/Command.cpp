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

Command::Command() :
    timestamp_{0}
{
}

Command::~Command()
{
}

void
Command::setTimestamp(int timestamp)
{
  timestamp_ = timestamp;
}

int
Command::getTimestamp()
{
  return timestamp_;
}

MoveCommand::MoveCommand(GameObject* object, double x, double y) :
    object_{object}, preX_{0}, preY_{0}, x_{x}, y_{y}
{
}

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

SpriteCommand::SpriteCommand(GameObject* object, Sprite* sprite) :
    object_{object}, preSprite_{nullptr}, sprite_{sprite}
{
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

DirectCommand::DirectCommand(Moveable* moveable, enum Direction direction) :
    object_{moveable}, direction_{direction}, preDirection_{Direction::LEFT}
{
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

SpeedCommand::SpeedCommand(Moveable* moveable, double speed) :
    object_{moveable}, preSpeed_{0}, speed_{speed}
{
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

ScoreCommand::ScoreCommand(GameInstance* game, int score) :
    game_{game}, score_{score}
{
}

void ScoreCommand::execute()
{
  game_->score += score_;
}

void ScoreCommand::undo()
{
  game_->score -= score_;
}

LifeCommand::LifeCommand(GameInstance* game, int life) :
    game_{game}, life_{life}
{
}

void LifeCommand::execute()
{
  game_->lives += life_;
}

void LifeCommand::undo()
{
  game_->lives -= life_;
}

StateCommand::StateCommand(GameObject* object, int state) :
    object_{object}, preState_{0}, state_{state}
{
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

SickGhostCommand::SickGhostCommand(GameInstance* game, int sick) :
    game_{game}, sick_{sick}
{
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

GhostEatenCommand::GhostEatenCommand(GameInstance* game, int eaten) :
    game_{game}, eaten_{eaten}
{
}

void GhostEatenCommand::execute()
{
  game_->ghostsEaten += eaten_;
}

void GhostEatenCommand::undo()
{
  game_->ghostsEaten -= eaten_;
}
