/*
 * Sprite.cpp
 *
 *  Created on: 10 dec 2013
 *      Author: Akdas
 */

#include "Sprite.h"

cSprite::Sprite(SDL_Renderer* sent_renderer, std::string FilePath, int x, int y, int w, int h) {

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



Sprite::~Sprite() {

	SDL_DestroyTexture(image);

}



/**
 * Copies the specified crop to the destination rectangle.
 *Destination rectangle is the one to be rendered.*/

void Sprite::Draw()
{
	SDL_RenderCopy(renderer, image, &crop, &rect);
}


void Sprite::SetX(int Xpos)
{
	rect.x = Xpos;
}

void Sprite::SetY(int Ypos)
{
	rect.y = Ypos;
}

void Sprite::SetPosition(int Xpos, int Ypos)
{
	rect.x = Xpos;
	rect.y = Ypos;
}

int Sprite::GetXpos()
{
	return rect.x;
}


int Sprite::GetYpos()
{
	return rect.y;
}



/**
 * Updates which part to be cropped from the sprite, can be used as follows;
 * pacman -> PlayAnimation(0,1,2,200);
 * This will check which frame of pacman.png we're cropping and crop the next one or reset to the first one.
 * pacman.png is uploaded to google drive for reference.
*/
void Sprite::PlayAnimation(int begin_frame, int end_frame, int row, float speed)
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


