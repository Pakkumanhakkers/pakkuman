/*
 * SDLSetup.cpp
 *
 *  Created on: 10 dec 2013
 *      Author: Akdas
 */

#include "SDLSetup.h"

cSDL_Setup::cSDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight) {


		window = NULL;
		window = SDL_CreateWindow("Pakkuman", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);

		//Failcheck
		if (window == NULL)
		{
			std::cout << "Window couldn't be created" << std::endl;
			*quit = true;
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
