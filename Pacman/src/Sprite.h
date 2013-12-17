/**
 * @file Sprite.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL.h>
#include <string>

#include "Moveable.h"

/**
 * Sprite representerar en sekvens av bilder. Används för bildloopar.
 */
class Sprite {
public:
	Sprite(std::string FilePath);
	virtual ~Sprite();

	//Functions to find information about sprite.
	int GetWidth();
	int GetHeight();

	static SDL_Renderer* GetRenderer();
	static void SetRenderer(SDL_Renderer*);

	SDL_Texture* GetImage();
	SDL_Rect* GetCrop(float ticks, int direction);

private:
	//choose which part to crop
	void PlayAnimation(int BeginFrame, int EndFrame, int Row, float ticks);

	static SDL_Renderer renderer;
	SDL_Texture* image;

	//crop is source rectangle(temp rectangle) which will be copied to rect
	SDL_Rect crop;

	int img_width;
	int img_height;

	//Used by PlayAnimation
	int current_frame;
	int animation_delayspeed;
};

#endif /* SPRITE_H_ */
