/**
 * @file Component.h
 *
 *  Created on: 16 dec 2013
 * @author ivar
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

//#include "GameEngine.h"
//#include "Moveable.h"

class GameEngine;
class Moveable;

class Component
{
public:
  virtual
  ~Component();
  Component();

  virtual void
  update(GameEngine*, Moveable*) = 0;
};

#endif /* COMPONENT_H_ */
