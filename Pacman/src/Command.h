/**
 * @file Command.h
 *
 *  Created on: 4 dec 2013
 * @author tor
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
  Command() {}
  virtual ~Command() {}

  virtual void execute() = 0;
  virtual void undo() = 0;

  void setTimestamp(int timestamp) {timestamp_ = timestamp;};
  int getTimestamp() {return timestamp_;};

private:
  int timestamp_{0};
};

/*
 * GameObject Command
 */

/**
 * Flyttar ett objekt
 */
class MoveCommand : public Command
{
public:
  MoveCommand(GameObject* object, double x, double y) :
    object_{object}, x_{x}, y_{y} {}

  void execute();
  void undo();

private:
  GameObject* object_;
  double preX_{0};
  double preY_{0};
  double x_;
  double y_;
};

/**
 * Byter sprite för ett object
 */
class SpriteCommand : public Command
{
public:
  SpriteCommand(GameObject* object, Sprite* sprite) :
    object_{object}, sprite_{sprite}, preSprite_{nullptr} {}

  void execute();
  void undo();

private:
  GameObject* object_;
  Sprite* preSprite_;
  Sprite* sprite_;
};

/*
 * MoveableObject Command
 */

/**
 * Byter riktning på ett rörligt objekt
 */
class DirectCommand : public Command
{
public:
  DirectCommand(Moveable* moveable, Moveable::Direction direction) :
    object_{moveable}, direction_{direction} {}

  void execute();
  void undo();

private:
  Moveable* object_;
  Moveable::Direction preDirection_{0};
  Moveable::Direction direction_;
};

/**
 * Byter fart på ett rörligt objekt
 */
class SpeedCommand : public Command
{
public:
  SpeedCommand(Moveable* moveable, double speed) :
    object_{moveable}, speed_{speed} {}

  void execute();
  void undo();

private:
  Moveable* object_;
  double preSpeed_{0};
  double speed_;
};

/*
 * GameInstance Command
 */

/**
 * Ger poäng
 */
class ScoreCommand : public Command
{
public:
  ScoreCommand(GameInstance* game, int score) :
    game_{game}, score_{score} {}

  void execute();
  void undo();

private:
  GameInstance* game_;
  int score_;
};

/**
 * Byter status på uppäten mat
 */
class FoodEatenCommand : public Command
{
public:
  FoodEatenCommand(Food* food) :
    food_{food} {}

  void execute();
  void undo();

private:
  Food* food_;
};

/**
 * Tappar livspoäng.
 */
class LifeCommand : public Command
{
public:
  LifeCommand(GameInstance* game, int life) :
    game_{game}, life_{life} {}

  void execute();
  void undo();

private:
  GameInstance* game_;
  int life_;
};

#endif /* COMMAND_H_ */
