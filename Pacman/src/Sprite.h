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
class cSprite {
public:
	//Input arguments are a renderer, a filepath, x and y is the point to initialize, w and h is width and height of the sprite.

	cSprite(SDL_Renderer* sent_renderer, std::string FilePath, int x, int y, int w, int h);
	virtual ~cSprite();

	//Function to draw sprite
	void Draw();

	//Functions to set positions
	void SetX(int Xpos);
	void SetY(int Ypos);
	void SetPosition(int Xpos, int Ypos);


	//Functions to find positions
	int GetXpos();
	int GetYpos();

private:

	SDL_Texture* image;
	SDL_Rect rect;

	SDL_Renderer* renderer;
};
