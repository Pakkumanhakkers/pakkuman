/**
 * @file GraphicsComponent.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef GRAPHICSCOMPONENT_H_
#define GRAPHICSCOMPONENT_H_
class GameObject;

/**
 * Väljer ut rätt grafik. Ritar ej.
 */
class GraphicsComponent
{
public:
  virtual ~GraphicsComponent();
  virtual void update(GameObject&);
};


#endif /* GRAPHICSCOMPONENT_H_ */
