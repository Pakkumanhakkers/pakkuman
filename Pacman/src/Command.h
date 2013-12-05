/*
 * Command.h
 *
 *  Created on: 4 dec 2013
 *      Author: tor
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <vector>

#include "GameObject.h"

/**
 * En händelse som ska utföras
 */
class Command
{
public:
  virtual ~Command() {}
  virtual void execute() = 0;
  virtual void undo() = 0;
};

class MultiCommand : public Command
{
public:
  virtual MultiCommand(std::vector<Command>& events) : events_(events) {}

  void execute();
  void undo();
private:
  std::vector<Command> events_;
};

class MoveObjectCommand : public Command
{
public:
  MoveObjectCommand(GameObject object, double x, double y) :
    object_(object), x_(x), y_(y) {}

  void execute();
  void undo();
private:
  GameObject object_;
  double x_;
  double y_;
};

class EatObjectCommand : public Command
{
public:
  EatObjectCommand();
};

#endif /* COMMAND_H_ */
