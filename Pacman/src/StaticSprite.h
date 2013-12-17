/**
 * @file StaticSprite.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef STATICSPRITE_H_
#define STATICSPRITE_H_

#include "SDLSetup.h"

/**
 * StaticSprite representerar en bild. Used for stationary images, t.ex. wall.
 */
class StaticSprite {
public:

	StaticSprite(SDL_Renderer* sent_renderer, std::string FilePath, int w, int h);
	virtual ~StaticSprite();



	//Functions to find information about sprite.
	int GetWidth();
	int GetHeight();

	SDL_Renderer* GetRenderer();

	SDL_Texture* GetImage();

	/*
	SDL_Rect* GetCrop(float ticks, std::string direction);
	 */

private:

/*
	//choose which part to crop
	void PlayAnimation(int BeginFrame, int EndFrame, int Row, float ticks);
*/

	SDL_Texture* image;

	/*
	//crop is source rectangle(temp rectangle) which will be copied to rect in GraphicEngine
	SDL_Rect crop;
	 */

	SDL_Renderer* renderer;

	int img_width;
	int img_height;

	/*
	//Used by PlayAnimation
	int current_frame;
	int animation_delayspeed;
	*/
};

#endif /* STATICSPRITE_H_ */