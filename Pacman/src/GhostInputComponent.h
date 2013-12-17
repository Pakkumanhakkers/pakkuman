/**
 * @file GhostInputComponent.h
 *
 *  Created on: 17 dec 2013
 * @author ivar
 */

#ifndef GHOSTINPUTCOMPONENT_H_
#define GHOSTINPUTCOMPONENT_H_

class GhostInputComponent : public Component
{
public:
  GhostInputComponent(AiInputComponent);
  virtual
  ~GhostInputComponent();

  virtual void
  update(GameEngine*, Moveable*);

private:
  AiInputComponent ai_;
};

#endif /* GHOSTINPUTCOMPONENT_H_ */
