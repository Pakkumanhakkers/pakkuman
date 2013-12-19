/*
 * Sprite.cpp
 *
 *  Created on: 10 dec 2013
 *      Author: Akdas
 */



#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <string>

#include "Sprite.h"
#include "Moveable.h"


SDL_Renderer* Sprite::renderer = nullptr;

Sprite::Sprite(std::string FilePath) {
  image = NULL;
  image = IMG_LoadTexture(Sprite::GetRenderer(), FilePath.c_str());

  if(image == NULL)
  {
    std::cerr << "Couldn't load " << FilePath.c_str() << std::endl;
  }

  //Sets img_width and img_height to the dimensions of the image.
  // TODO bör fixas! kan inte bete sig lika för enkla bilder och bildkartor
  SDL_QueryTexture(image, NULL,NULL, &img_width, &img_height);

  crop.x = 0;
  crop.y = 0;

  //Initialize to crop just first frame on the first row.
  crop.w = 32;
  crop.h = 32;

  current_frame = 0;
  animation_delayspeed = 0;
}

Sprite::~Sprite() {
  SDL_DestroyTexture(image);
}

int Sprite::GetWidth()
{
  // TODO bör fixas! kan inte bete sig lika för enkla bilder och bildkartor
  return img_width/2;
}

int Sprite::GetHeight()
{
  // TODO bör fixas! kan inte bete sig lika för enkla bilder och bildkartor
  // vad ska dessa egentligen användas till?
  return img_height/4;
}

int Sprite::GetSize()
{
  // använder denna så länge (kvadratiska sprites, samma storlek)
  return 32;
}

SDL_Renderer* Sprite::GetRenderer()
{
  return renderer;
}

void Sprite::SetRenderer(SDL_Renderer* r)
{
  renderer = r;
}

/**
 * Copies the specified crop to the destination rectangle.
 * Destination rectangle is the one to be rendered.
 */
SDL_Rect* Sprite::GetCrop(float ticks, Direction direction){
  if(direction== Direction::RIGHT)
  {PlayAnimation(0,1,0,ticks);}
  else if(direction == Direction::LEFT)
  {PlayAnimation(0,1,2,ticks);}
  else if (direction == Direction::UP)
  {PlayAnimation(0,1,3,ticks);}
  else
  {PlayAnimation(0,1,1,ticks);}

  return &crop;
}

SDL_Texture* Sprite::GetImage()
{
  return image;
}



/**
 * Updates which part to be cropped from the sprite, can be used as follows;
 * pacman -> PlayAnimation(0,1,2,200);
 * This will check which frame of pacman.png we're cropping and crop the next one or reset to the first one.
 * pacman.png is uploaded to google drive for reference.
 */
void Sprite::PlayAnimation(int BeginFrame, int EndFrame, int Row, float ticks)
{
  if (animation_delayspeed + 10 < ticks)
  {
    if (EndFrame <= current_frame)
      current_frame = BeginFrame;
    else
      current_frame++;

    // TODO måste fixas! kan inte bete sig lika för enkla bilder och bildkartor
    // ska man ha en annan variabel för enkla bildens storlek?
    crop.x = current_frame * img_width/2;
    crop.y = Row * (img_height/4);
    crop.w = img_width/2;
    crop.h = img_height/4;
  }
}


