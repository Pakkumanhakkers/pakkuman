/*
 * Graphics.cpp
 *
 *  Created on: 11 dec 2013
 *      Author: Akdas
 */

#include "GraphicEngine.h"

GraphicEngine::GraphicEngine() {

	rect.x = 0;
	rect.y = 0;
	rect.w = 0;
	rect.h = 0;
	offset_map = 128;

}

GraphicEngine::~GraphicEngine() {
	// TODO Auto-generated destructor stub
}


void GraphicEngine::DrawSprite(sprite_, xpos_, ypos_, current_ticks){

	SDL_RenderCopy(Sprite->GetRenderer(), Sprite->GetImage(), &(Sprite->GetCrop(current_ticks)), &(OutputRectangle(Xpos,Ypos,Sprite->w, Sprite->h)));

}

SDL_Rect* GraphicEngine::OutputRectangle(Xpos, Ypos, SpriteWidth, SpriteHeight){

	rect.x = Xpos + offset_map;
	rect.y = Ypos;
	rect.w = SpriteWidth;
	rect.h = SpriteHeight;

	return rect;

}
