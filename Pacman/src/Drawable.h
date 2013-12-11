/**
 * @file Drawable.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef DRAWABLE_H_
#define DRAWABLE_H_
class Graphics;

/**
 * Kan ritas ut.
 */
class Drawable
{
public:
  virtual
  ~Drawable();
  Drawable();

  virtual void
  draw(Graphics&) = 0;
};


#endif /* DRAWABLE_H_ */
