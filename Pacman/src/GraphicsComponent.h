/**
 * @file GraphicsComponent.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef GRAPHICSCOMPONENT_H_
#define GRAPHICSCOMPONENT_H_
class GameObject;
class Graphics;

/**
 * Hanterar det grafiska
 */
class GraphicsComponent
{
public:
  virtual ~GraphicsComponent();
  virtual void update(GameObject&, Graphics&);
};


#endif /* GRAPHICSCOMPONENT_H_ */
