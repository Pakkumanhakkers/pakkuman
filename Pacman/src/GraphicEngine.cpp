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
	globalFont =  TTF_OpenFont( "PAC-FONT.TTF", 28 );
	textColor = { 0, 0, 0 };
	sdlSetup = cSDL_Setup(false, 1024 /*bredd*/, 640 /*height*/);

}

GraphicEngine::~GraphicEngine() {
	delete GraphicEngine;
}


void GraphicEngine::DrawSprite(Sprite* sprite_, double xpos_, double ypos_, int current_ticks, Moveable::Direction direction)
{
	SDL_RenderCopy(sprite_->GetRenderer(), sprite_->GetImage(),
			sprite_->GetCrop(current_ticks, direction),
			OutputRectangle(xpos_,ypos_,sprite_->GetWidth(), sprite_->GetHeight()));
}


void GraphicEngine::Draw(Sprite* statSprite_, double xpos_, double ypos_)
{
	SDL_RenderCopy(Sprite_->GetRenderer(),
			Sprite_->GetImage(), NULL,
			OutputRectangle(xpos_, ypos_, Sprite_->GetWidth(), Sprite_->GetHeight()));
}


void GraphicEngine::Draw(std::string output_, double xpos_, double ypos_)
{
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( globalFont, output_.c_str(), textColor );

	if( textSurface == NULL )
	{
		std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
	}
	else
	{
		SDL_Texture* mTexture = NULL;
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( sdlSetup.GetRenderer(), textSurface );
		if( mTexture == NULL )
		{
			std::cout << "Unable to create texture from rendered text! SDL Error: "
					<< SDL_GetError() << std::endl;
		}
		else
		{
			//Get image dimensions
			int mWidth = textSurface->w;
			int mHeight = textSurface->h;

			//Set rendering space and render to screen
			SDL_Rect renderQuad = { xpos_, ypos_, mWidth, mHeight };

			//Set how the texture is to be flipped.
			SDL_RendererFlip flip = SDL_FLIP_NONE;

			//Render to screen
			SDL_RenderCopyEx( sdlSetup.GetRenderer(), mTexture,
					NULL/* eller ska detta vara sdlSetup->GetWindow()? */,
					OutputRectangle(xpos_ - offset_map, ypos_, mWidth, mHeight),
					0.0 /* The angel on which the text is drawn in degrees */,
					NULL /* Punkten rendering-rutan snurras runt (w/2, h/2 nu) */,
					flip);
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
}


SDL_Rect* GraphicEngine::OutputRectangle(double Xpos, double Ypos, int SpriteWidth, int SpriteHeight)
{
	rect.x = Xpos + offset_map;
	rect.y = Ypos;
	rect.w = SpriteWidth;
	rect.h = SpriteHeight;

	return rect;
}
