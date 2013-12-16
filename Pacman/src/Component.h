/**
 * @file Component.h
 *
 *  Created on: 16 dec 2013
 * @author ivar
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

class Component
{
public:
  virtual
  ~Component();
  Component() = 0;

  virtual void
  update(GameEngine*, Moveable*) = 0;
};

#endif /* COMPONENT_H_ */
