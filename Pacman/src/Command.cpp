/**
 * @file Command.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "Command.h"

#include <iterator>

using namespace std;

void MultiCommand::execute()
{
  for (Command* command : commands_)
  {
    command->execute();
  }
}

void MultiCommand::undo()
{
  for (auto i = commands_.end(); i != commands_.begin();)
  {
    (*(--i))->undo();
  }
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


