/**
 * @file MoveableGraphicsComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef MOVEABLEGRAPHICSCOMPONENT_H_
#define MOVEABLEGRAPHICSCOMPONENT_H_
class Moveable;

/**
 * Hanterar grafik för rörliga spelobjekt
 */
class MoveableGraphicsComponent
{
public:
  virtual ~MoveableGraphicsComponent();
  virtual void update(Moveable&);
};


#endif /* MOVEABLEGRAPHICSCOMPONENT_H_ */
