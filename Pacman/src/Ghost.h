/**
 * @file Ghost.h
 *
 *  Created on: 10 dec 2013
 * @author ivar
 */

#ifndef GHOST_H_
#define GHOST_H_

class AiInputComponent;

class Ghost : public Moveable, public Eatable
{
public:
  ~Ghost() {}
  Ghost(MoveableInputComponent* input, MoveablePhysicsComponent* physics,
        MoveableGraphicsComponent* graphics) :
      Moveable{input, physics, graphics}, health_state_{0} {}

  void eat();

  void enterChase();
  void enterScatter();
  void wound();
  void blink();
  void heal();

private:
  int health_state_;
};



#endif /* GHOST_H_ */
