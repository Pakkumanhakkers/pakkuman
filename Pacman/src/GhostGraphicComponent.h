/**
 * @file GhostGraphicComponent.h
 *
 *  Created on: 17 dec 2013
 * @author ivar
 */

#ifndef GHOSTGRAPHICCOMPONENT_H_
#define GHOSTGRAPHICCOMPONENT_H_

#include "Component.h"
//#include "GameEngine.h"
//#include "Moveable.h"
//#include "Sprite.h"

class GameEngine;
class Moveable;
class Sprite;

class GhostGraphicComponent : public Component
{
public:
  GhostGraphicComponent(Sprite* normal, Sprite* sick, Sprite* blink,
      Sprite* dead);
  virtual
  ~GhostGraphicComponent();

  virtual void
  update(GameEngine*, Moveable*);

private:
  Sprite* normal_;
  Sprite* sick_;
  Sprite* blink_;
  Sprite* dead_;
};

#endif /* GHOSTGRAPHICCOMPONENT_H_ */
