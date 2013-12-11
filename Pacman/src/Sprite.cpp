/*
 * Sprite.cpp
 *
 *  Created on: 10 dec 2013
 *      Author: Akdas
 */

#include "Headerfiles/Sprite.h"

cSprite::cSprite(SDL_Renderer* sent_renderer, std::string FilePath, int x, int y, int w, int h) {

	renderer = sent_renderer;

	image = NULL;
	image = IMG_LoadTexture(renderer, FilePath.c_str());



		if(image ==NULL)
			{
				std::cout << "Couldn't load " << FilePath.c_str() << std::endl;
			}
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;

		//Sets img_width and img_height to the dimensions of the image.
		SDL_QueryTexture(image, NULL,NULL, &img_width, &img_height);

		crop.x = 0;
		crop.y = 0;

		//Initialize to crop just first frame on the first row.
		crop.w = img_width/2;
		crop.h = img_height/4;

		current_frame = 0;
		animation_delayspeed = 0;


}



cSprite::~cSprite() {

	SDL_DestroyTexture(image);

}


void cSprite::Draw()
{
	SDL_RenderCopy(renderer, image, &crop, &rect);
}


void cSprite::SetX(int Xpos)
{
	rect.x = Xpos;
}

void cSprite::SetY(int Ypos)
{
	rect.y = Ypos;
}

void cSprite::SetPosition(int Xpos, int Ypos)
{
	rect.x = Xpos;
	rect.y = Ypos;
}

int cSprite::GetXpos()
{
	return rect.x;
}


int cSprite::GetYpos()
{
	return rect.y;
}


void cSprite::PlayAnimation(int begin_frame, int end_frame, int row, float speed)
{

	if (animation_delayspeed + speed < SDL_GetTicks())
	{


	if (end_frame <= current_frame)
		current_frame = begin_frame;
	else
		current_frame++;

	crop.x = current_frame * img_width/2;
	crop.y = row * (img_height/4);
	crop.w = img_width/2;
	crop.h = img_height/4;

	animation_delayspeed = SDL_GetTicks();
	}

}


