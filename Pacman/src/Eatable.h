/**
 * @file Eatable.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef EATABLE_H_
#define EATABLE_H_

/**
 * Kan ätas.
 */
class Eatable
{
public:
  virtual
  ~Eatable();
  Eatable();

  virtual void
  eat() = 0;
};

#endif /* EATABLE_H_ */
