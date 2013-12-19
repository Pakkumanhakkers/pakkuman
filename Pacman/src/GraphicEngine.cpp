/*
 * Graphics.cpp
 *
 *  Created on: 11 dec 2013
 *      Author: Akdas
 */

#include "GraphicEngine.h"

#include <SDL.h>
#include <SDL_error.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL2_ttf.h>
#include <iostream>

#include "Sprite.h"

GraphicEngine::GraphicEngine() :
rect{0,0,0,0},
offset_map{272},
globalFont{nullptr},
textColor{ 0, 0, 0 },
sdlSetup{1024, 640},
ticks{0},
scaleX_{1.0},
scaleY_{1.0}
{
  if (TTF_Init() == -1)
  {
    std::cerr << "Failed to do TTF_Init()" << std::endl;
  }
  else
  {
    globalFont = TTF_OpenFont("PAC-FONT.TTF", 28);
  }
  Sprite::SetRenderer(getRenderer());
}

GraphicEngine::~GraphicEngine()
{
}

void GraphicEngine::DrawSprite(Sprite* sprite_, double xpos_, double ypos_,
    Direction direction)
{
  SDL_RenderCopy(sdlSetup.GetRenderer(), sprite_->GetImage(),
      sprite_->GetCrop(ticks, direction),
      OutputRectangle(scaleX_*xpos_,
          scaleY_*ypos_,
          sprite_->GetSize(), sprite_->GetSize()));
}

void GraphicEngine::Draw(Sprite* Sprite_, double xpos_, double ypos_)
{
  SDL_RenderCopy(sdlSetup.GetRenderer(),
      Sprite_->GetImage(), NULL,
      OutputRectangle(xpos_, ypos_, Sprite_->GetSize(), Sprite_->GetSize()));
}

void GraphicEngine::draw(std::string output_, double xpos_, double ypos_)
{
  if (globalFont == nullptr)
  {
    std::cerr << "Has no font!" << std::endl;
    return;
  }
  //Render text surface
  SDL_Surface* textSurface = TTF_RenderText_Solid(
      globalFont, output_.c_str(), textColor );

  if( textSurface == NULL )
  {
    std::cerr << "Unable to render text surface! SDL_ttf Error: "
        << TTF_GetError() << std::endl;
  }
  else
  {
    SDL_Texture* mTexture = NULL;
    //Create texture from surface pixels
    mTexture = SDL_CreateTextureFromSurface( sdlSetup.GetRenderer(),
        textSurface );
    if( mTexture == NULL )
    {
      std::cerr << "Unable to create texture from rendered text! SDL Error: "
          << SDL_GetError() << std::endl;
    }
    else
    {
      //Get image dimensions
      int mWidth = textSurface->w;
      int mHeight = textSurface->h;

      //Set rendering space and render to screen
      //SDL_Rect renderQuad = { xpos_, ypos_, mWidth, mHeight };

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


SDL_Rect* GraphicEngine::OutputRectangle(double Xpos, double Ypos,
    int SpriteWidth, int SpriteHeight)
{
  rect.x = Xpos*32 + offset_map;
  rect.y = Ypos*32;
  rect.w = SpriteWidth;
  rect.h = SpriteHeight;

  return &rect;
}

SDL_Renderer* GraphicEngine::getRenderer()
{
  return sdlSetup.GetRenderer();
}

void GraphicEngine::setCurrentTime(int input){

  ticks = input;

}

void GraphicEngine::update()
{
  sdlSetup.Begin();
}

void GraphicEngine::show(){

	sdlSetup.End();

}
