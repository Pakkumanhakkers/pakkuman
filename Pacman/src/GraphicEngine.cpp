/*
 * Graphics.cpp
 *
 *  Created on: 11 dec 2013
 *      Author: Akdas
 */

#include "GraphicEngine.h"

GraphicEngine::GraphicEngine() {

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

}

GraphicEngine::~GraphicEngine() {
	// TODO Auto-generated destructor stub
}


void GraphicEngine::DrawSprite(sprite_, xpos_, ypos_, current_ticks){

	SDL_RenderCopy(Sprite->GetRenderer, Sprite->getImage(), &(Sprite->GetCrop(current_ticks)), &(OutputRectangle(Xpos,Ypos,Sprite->w, Sprite->h)));

}


SDL_Rect* GraphicEngine::OutputRectangle(Xpos, Ypos, SpriteWidth, SpriteHeight){

	rect.x = Xpos + 128 + Xpos*128;
	rect.y = Ypos;
	rect.w = SpriteWidth;
	rect.h = SpriteHeight;

	return rect;

}
