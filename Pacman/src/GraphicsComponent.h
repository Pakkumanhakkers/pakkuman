/**
 * @file GraphicsComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef GRAPHICSCOMPONENT_H_
#define GRAPHICSCOMPONENT_H_
class Sprite;

class Moveable;

/**
 * Hanterar grafik för rörliga spelobjekt
 */
class GraphicsComponent
{
public:
  GraphicsComponent(MoveableSprite*);
  virtual ~GraphicsComponent() = 0;
  virtual void update(Moveable*);

private:
  MoveableSprite* sprite_;
};


#endif /* GRAPHICSCOMPONENT_H_ */

