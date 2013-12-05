/**
 * @file MoveableGraphicsComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef MOVEABLEGRAPHICSCOMPONENT_H_
#define MOVEABLEGRAPHICSCOMPONENT_H_
class Sprite;

class Moveable;

/**
 * Hanterar grafik för rörliga spelobjekt
 */
class MoveableGraphicsComponent
{
public:
  MoveableGraphicsComponent(Sprite* left, Sprite* right,
      Sprite* up, Sprite* down) :
    left_(left), right_(right), up_(up), down_(down) {}
  void update(Moveable&);

private:
  Sprite* left_;
  Sprite* right_;
  Sprite* up_;
  Sprite* down_;
};


#endif /* MOVEABLEGRAPHICSCOMPONENT_H_ */

