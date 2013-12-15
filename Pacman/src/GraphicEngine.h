/*
 * Graphics.h
 *
 *  Created on: 11 dec 2013
 *      Author: Akdas
 */

#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_
#include "SDL2/SDL.h"
#include "SDL_TTF.h"
#include "SDLSetup.h"

class GraphicEngine {
public:
	GraphicEngine();
	virtual ~GraphicEngine();

	void DrawSprite(Sprite sprite_, double xpos_, double ypos_, int current_ticks);
	void Draw(renderer, string output_, double xpos_, double ypos_);

	SDL_Rect* OutputRectangle();

private:

	SDL_Rect rect;
	int offset_map;
};

#endif /* GRAPHICS_H_ */