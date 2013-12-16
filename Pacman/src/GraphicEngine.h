/*
 * Graphics.h
 *
 *  Created on: 11 dec 2013
 *      Author: Akdas
 */

#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_
#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "SDL_TTF.h"
#include "SDLSetup.h"

class GraphicEngine {
public:
	GraphicEngine();
	virtual ~GraphicEngine();

	void DrawSprite(Sprite sprite_, double xpos_, double ypos_, int current_ticks);
	void Draw(string output_, double xpos_, double ypos_);

	SDL_Rect* OutputRectangle(double Xpos, double Ypos, int SpriteWidth, int SpriteHeight);

private:

	SDL_Rect rect;
	int offset_map;
	TTF_Font globalFont;
	SDL_Color textColor;
	cSDL_Setup sdlSetup;
};

#endif /* GRAPHICS_H_ */
