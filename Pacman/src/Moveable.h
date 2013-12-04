/**
 * @file Moveable.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_
class GraphicsComponent;
class InputComponent;
class PhysicsComponent;

#include "GameObject.h"

/**
 * Ett flyttbart spelobject.
 */
class Moveable : public GameObject
{
public:
  virtual ~Moveable() {};
  Moveable(InputComponent* input, PhysicsComponent* physics,
      GraphicsComponent* graphics) :
    GameObject(graphics), input_(input), physics_(physics) {}

protected:
  InputComponent* input_;
  PhysicsComponent* physics_;
};


#endif /* MOVEABLE_H_ */
