/*
 * Graphics.h
 *
 *  Created on: 11 dec 2013
 *      Author: Akdas
 */

#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_

#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <SDL_ttf.h>
#include <string>

#include "Moveable.h"
#include "SDLSetup.h"
//#include "Sprite.h"

class GraphicEngine {
public:
	GraphicEngine();
	virtual ~GraphicEngine();


	//DrawSprite takes care of movable, needs a direction as input argument to know which row of the image to crop.
	void DrawSprite(Sprite* sprite_, double xpos_, double ypos_, Moveable::Direction direction = Moveable::Direction::RIGHT)  ;

	void Draw(Sprite* sprite_, double xpos_, double ypos_);

	//Draw is used by objects with no direction.
	void Draw(std::string output_, double xpos_, double ypos_);
	
	void setCurrentTime(int input);


	SDL_Rect* OutputRectangle(double Xpos, double Ypos, int SpriteWidth, int SpriteHeight);

private:

	SDL_Rect rect;
	int offset_map;
	TTF_Font* globalFont;
	SDL_Color textColor;
	cSDL_Setup sdlSetup;
	int ticks;
};

#endif /* GRAPHICS_H_ */
