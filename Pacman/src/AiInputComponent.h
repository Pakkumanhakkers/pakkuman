/**
 * @file AiInputComponent.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef AIINPUTCOMPONENT_H_
#define AIINPUTCOMPONENT_H_


/**
 * Styr rörliga objekt med AI
 */
class AiInputComponent : Moveable, GameEngine
{
public:
  void update(Moveable&, GameEngine&);
  Direction updateDirection(AiType Ai, int ghost_x, int ghost_y, int target_x, int target_y);

private:
    bool Valid(int ghost_x, int ghost_y,int direction);
	Direction getRandom(int ghost_x, int ghost_y);
};


#endif /* AIINPUTCOMPONENT_H_ */
