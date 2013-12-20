/**
 * @file KeyboardInputComponent.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "KeyboardInputComponent.h"

#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>

#include "Command.h"
#include "DefaultPhysicsComponent.h"
#include "GameEngine.h"
#include "Component.h"
#include "Moveable.h"

KeyboardInputComponent::KeyboardInputComponent()  :
next_direction_{Direction::LEFT}
{
}

void KeyboardInputComponent::update(GameEngine* gameEngine, Moveable* moveable)
{
  const Uint8* state = SDL_GetKeyboardState(nullptr);
  if (state[SDL_SCANCODE_LEFT])
  {
    next_direction_ = Direction::LEFT;
  }
  else if (state[SDL_SCANCODE_RIGHT])
  {
    next_direction_ = Direction::RIGHT;
  }
  else if (state[SDL_SCANCODE_UP])
  {
    next_direction_ = Direction::UP;
  }
  else if (state[SDL_SCANCODE_DOWN])
  {
    next_direction_ = Direction::DOWN;
  }

  if (moveable->isCentered() &&
      DefaultPhysicsComponent::canMove(gameEngine->getMap(), moveable,
          next_direction_) &&
          (moveable->getDirection() != getOppositeDirection(next_direction_)))
  {
    gameEngine->publishCommand(new DirectCommand(moveable, next_direction_));
  }
}
