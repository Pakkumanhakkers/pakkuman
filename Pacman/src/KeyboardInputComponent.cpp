/**
 * @file KeyboardInputComponent.cpp
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#include "KeyboardInputComponent.h"

#include <SDL_keyboard.h>
#include <SDL_scancode.h>
#include <SDL_stdinc.h>
#include <cmath>

#include "Command.h"
#include "GameEngine.h"
#include "Map.h"
#include "PhysicsComponent.h"

class GameEngine;
class Moveable;

KeyboardInputComponent::KeyboardInputComponent()  :
    next_direction_{Moveable::Direction::LEFT}
{
}

void KeyboardInputComponent::update(Moveable* moveable, GameEngine* gameEngine)
{
  const Uint8* state = SDL_GetKeyboardState(nullptr);
  if (state[SDL_SCANCODE_LEFT])
  {
    next_direction_ = Moveable::Direction::LEFT;
  }
  else if (state[SDL_SCANCODE_RIGHT])
  {
    next_direction_ = Moveable::Direction::RIGHT;
  }
  else if (state[SDL_SCANCODE_UP])
  {
    next_direction_ = Moveable::Direction::UP;
  }
  else if (state[SDL_SCANCODE_DOWN])
  {
    next_direction_ = Moveable::Direction::DOWN;
  }

  if (PhysicsComponent::canTurn(gameEngine->getMap(), moveable,
      next_direction_))
  {
    gameEngine->publishCommand(new DirectCommand(moveable, next_direction_));
  }
}
