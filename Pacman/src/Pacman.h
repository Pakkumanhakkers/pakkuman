/**
 * @file Pacman.h
 *
 *  Created on: 10 dec 2013
 * @author ivar
 */

#ifndef PACMAN_H_
#define PACMAN_H_

/**
 * Pacman som äter allt.
 */
class Pacman : public Moveable
{
public:
  enum Health
  {
    ALIVE, DEAD
  };

  virtual ~Pacman();
  Pacman();

  virtual int getState();
  virtual void setState(int);

  void die(GameEngine*);
  void spawn(GameEngine*, int, int);
private:
  int health_;
};



#endif /* PACMAN_H_ */
