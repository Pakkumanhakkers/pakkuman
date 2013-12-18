/**
 * @file Moveable.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_

#include <list>
#include "GameObject.h"
#include "Component.h"
#include "Direction.h"
class GameEngine;
class GraphicEngine;

/**
 * Ett flyttbart spelobject.
 */
class Moveable : public GameObject
{
public:
  virtual
  ~Moveable();
  Moveable();

  void
  addComponent(Component*);

  virtual void
  draw(GraphicEngine*);
  virtual void
  update(GameEngine*);

  Direction
  getDirection();
  void
  setDirection(Direction direction);
  double
  getSpeed();
  void
  setSpeed(double speed);

  bool
  isCentered();

protected:
  std::list<Component*> components_;

private:
  double speed_;
  enum Direction direction_{UP};
};


#endif /* MOVEABLE_H_ */
