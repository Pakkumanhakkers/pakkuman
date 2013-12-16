/*
 * Graphics.h
 *
 *  Created on: 11 dec 2013
 *      Author: Akdas
 */

#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_
#include "SDLSetup.h"
#include "Sprite.h"

class GraphicEngine {
public:
	GraphicEngine();
	virtual ~GraphicEngine();

	void DrawSprite(Sprite sprite_, double xpos_, double ypos_, int current_ticks, std::string direction);
	void Draw(SDL_Renderer* renderer, std::string output_, double xpos_, double ypos_);

	SDL_Rect* OutputRectangle(double Xpos, double Ypos, int SpriteWidth, int SpriteHeight);

private:

	SDL_Rect rect;
	int offset_map;
};

#endif /* GRAPHICS_H_ */
