/*
 * Command.h
 *
 *  Created on: 4 dec 2013
 *      Author: tor
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <vector>

#include "Moveable.h"

/**
 * Ett kommando som ska utföras
 */
class Command
{
public:
  virtual ~Command() {}
  virtual void execute() = 0;
  virtual void undo() = 0;
};

/**
 * Kedjar flera kommandon
 */
class MultiCommand : public Command
{
public:
  MultiCommand(std::vector<Command*>& commands) : commands_(commands) {}

  void execute();
  void undo();
private:
  std::vector<Command*> commands_;
};

/**
 * Flyttar ett objekt
 */
class MoveCommand : public Command
{
public:
  MoveCommand(GameObject& object, double x, double y) :
    object_(&object), x_(x), y_(y) {}

  void execute();
  void undo();

private:
  GameObject* object_;
  double preX_;
  double preY_;
  double x_;
  double y_;
};

/**
 * Byter riktning på ett rörligt objekt
 */
class DirectCommand : public Command
{
public:
  DirectCommand(Moveable& moveable, Moveable::Direction direction) :
    object_(&moveable), direction_(direction) {}

  void execute();
  void undo();

private:
  Moveable* object_;
  Moveable::Direction preDirection_;
  Moveable::Direction direction_;
};

/**
 * Byter fart på ett rörligt objekt
 */
class SpeedCommand : public Command
{
public:
  SpeedCommand(Moveable& moveable, double speed) :
    object_(&moveable), speed_(speed) {}

  void execute();
  void undo();

private:
  Moveable* object_;
  double preSpeed_;
  double speed_;
};

/**
 * Äter upp något ätbart
 */
class EatCommand : public Command
{
public:
  EatCommand();
};

#endif /* COMMAND_H_ */
