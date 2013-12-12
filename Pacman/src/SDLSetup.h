/*
 * SDLSetup.h
 *
 *  Created on: 10 dec 2013
 *      Author: Akdas
 */

/** Should include the mainfile I think */


#ifndef SDLSetup_H_
#define SDLSetup_H_


/* Bad name, my bad. */

class cSDL_Setup {
public:
	//Initializer
	cSDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight);
	virtual ~cSDL_Setup();

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	//Clear current renderers
	void Begin();

	//Draw functions in drawable-classes will update the renderer.

	//Displays rendered objects on screen.
	void End();

private:

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event* mainEvent;
};

#endif /* SDLSetup_H_ */
