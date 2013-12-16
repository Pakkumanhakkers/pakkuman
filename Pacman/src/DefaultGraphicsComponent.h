/**
 * @file DefaultGraphicsComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef DEFAULTGRAPHICSCOMPONENT_H_
#define DEFAULTGRAPHICSCOMPONENT_H_
class Sprite;

class Moveable;

/**
 * Hanterar grafik för rörliga spelobjekt
 */
class DefaultGraphicsComponent : public Component
{
public:
  DefaultGraphicsComponent(MoveableSprite*);
  virtual ~DefaultGraphicsComponent();
  virtual void update(GameEngine*, Moveable*);

private:
  MoveableSprite* sprite_;
};


#endif /* DEFAULTGRAPHICSCOMPONENT_H_ */

