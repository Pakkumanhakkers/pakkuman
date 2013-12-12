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
  ~Pacman() {};
  Pacman(InputComponent* input, PhysicsComponent* physics,
        GraphicsComponent* graphics) :
      Moveable{input, physics, graphics} {}

  void die();
  void spawn();
};



#endif /* PACMAN_H_ */
