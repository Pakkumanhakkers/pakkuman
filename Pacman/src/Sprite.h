/**
 * @file Sprite.h
 *
 *  Created on: 5 dec 2013
 * @author tor
 */

#ifndef SPRITE_H_
#define SPRITE_H_

/**
 * Sprite representerar en sekvens av bilder. Används för bildloopar.
 */
class Sprite {
public:
	Sprite(SDL_Renderer* sent_renderer, std::string FilePath, int x, int y, int w, int h);
	virtual ~cSprite();

	//Function to update which part will be rendered
	void Draw();

	//Functions to set positions
	void SetX(int Xpos);
	void SetY(int Ypos);
	void SetPosition(int Xpos, int Ypos);


	//Functions to find positions
	int GetXpos();
	int GetYpos();

	//Choose which part of the sprite to crop out
	void PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed);

	/**
	 *  I think next/prev is covered by PlayAnimation? Not sure what is supposed getLength to do? length
	 * of a frame?
	 * void next();
	 * void prev();
	 * int getLength() */


private:

	SDL_Texture* image;

	//rect is destination rectangle
	SDL_Rect rect;

	//crop is source rectangle(temp rectangle) which will be copied to rect
	SDL_Rect crop;

	SDL_Renderer* renderer;

	int img_width;
	int img_height;

	//Used by PlayAnimation
	int current_frame;
	int animation_delayspeed;
};

#endif /* SPRITE_H_ */
