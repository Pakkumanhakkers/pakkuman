/**
 * @file Sprite.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef SPRITE_H_
#define SPRITE_H_

/**
 * Sprite representerar en sekvens av bilder. Används för bildloopar.
 */
class Sprite
{
public:
  // Stegar till nästa bild, implementera denna! :)
  void
  next();
  void
  prev();
  int
  getLength();
  // Behöver funktion för att rita ut

private:
  int length_;
  // Bilddata här lämpligtvis
};


#endif /* SPRITE_H_ */
