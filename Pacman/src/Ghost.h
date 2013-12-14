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
  Ghost(InputComponent* input, PhysicsComponent* physics,
        GraphicsComponent* graphics) :
      Moveable{input, physics, graphics}, health_state_{1} {}

  void eat(GameEngine*); //Vad ska denna göra, och hur ska den implementeras?
  void enterChase();  //dessa två ändrar AiType
  void enterScatter();
  void enterRandom();
  void enterHome();
  void wound();  //Denna sätter health_state_ till EATABLE, korrektomundo?
  void blink(); // Hur ska denna implementeras?
  void heal();  // Just nu sätter denna health_state_ till NORMAL, funkar det för er andra?
  AiType getAiType();
private:
  enum health_state_
  {
	NORMAL, EATABLE, EATEN
  }
  health_state_ CurrentHealthState = NORMAL;
  
  enum AiType 
  {
	CHASE, RANDOM, SCATTER, HOME
  };
  AiType CurrentAi = CHASE;

};



#endif /* GHOST_H_ */
