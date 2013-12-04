/**
 * @file InputComponent.h
 *
 *  Created on: 4 dec 2013
 * @author tor
 */

#ifndef INPUTCOMPONENT_H_
#define INPUTCOMPONENT_H_
class GameObject;

/**
 * Hanterar indata från t ex tangentbord eller AI
 */
class InputComponent
{
public:
  virtual ~InputComponent();
  virtual void update(GameObject&);
};

#endif /* INPUTCOMPONENT_H_ */
