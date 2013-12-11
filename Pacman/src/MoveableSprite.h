/**
 * @file MoveableSprite.h
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#ifndef MOVEABLESPRITE_H_
#define MOVEABLESPRITE_H_


/**
 * MoveableSprite representerar en sekvens av bilder med riktningar.
 */
class MoveableSprite : public Sprite
{
public:
  Moveable::Direction getDirection() {return direction_;}
  void setDirection(Moveable::Direction direction);

private:
  Moveable::Direction direction_;
  int length_;
};


#endif /* MOVEABLESPRITE_H_ */
