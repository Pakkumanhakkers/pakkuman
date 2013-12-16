/*
 * Graphics.cpp
 *
 *  Created on: 11 dec 2013
 *      Author: Akdas
 */

#include "GraphicEngine.h"
#include <string>

GraphicEngine::GraphicEngine() {

	rect.x = 0;
	rect.y = 0;
	rect.w = 0;
	rect.h = 0;
	offset_map = 128;

}

GraphicEngine::~GraphicEngine() {
	delete GraphicEngine;
}


void GraphicEngine::DrawSprite(Sprite sprite_, double xpos_, double ypos_, int current_ticks, std::string direction)
{
	SDL_RenderCopy(sprite_->GetRenderer(), sprite_->GetImage(),
			sprite_->GetCrop(current_ticks, direction),
			OutputRectangle(xpos_,ypos_,sprite_->GetWidth(), sprite_->GetHeight()));

}

void GraphicEngine::Draw(SDL_Renderer* renderer, std::string output_, double Xpos_, double Ypos_)
{

}

SDL_Rect* GraphicEngine::OutputRectangle(double Xpos, double Ypos, int SpriteWidth, int SpriteHeight)
{
	rect.x = Xpos + offset_map;
	rect.y = Ypos;
	rect.w = SpriteWidth;
	rect.h = SpriteHeight;

	return rect;
}
