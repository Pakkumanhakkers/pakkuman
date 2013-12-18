/*
 * SDLSetup.cpp
 *
 *  Created on: 10 dec 2013
 *      Author: Akdas
 */

#include "SDLSetup.h"

#include <stddef.h>
#include <SDL.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <iostream>

cSDL_Setup::cSDL_Setup(int ScreenWidth, int ScreenHeight)
{
  window = SDL_CreateWindow("Pakkuman", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);

  //Failcheck
  if (window == NULL)
  {
    std::cerr << "Window couldn't be created" << std::endl;
  }

  renderer = NULL;
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  mainEvent = new SDL_Event();


}

cSDL_Setup::~cSDL_Setup() {

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  delete mainEvent;

}

SDL_Renderer* cSDL_Setup::GetRenderer()
{

  return renderer;
}


SDL_Event* cSDL_Setup::GetMainEvent()
{

  return mainEvent;
}


void cSDL_Setup::Begin() {

  SDL_PollEvent(mainEvent);
  SDL_RenderClear(renderer);


}


void cSDL_Setup::End() {

  SDL_RenderPresent(renderer);
}
