/*
 * Graphics.h
 *
 *  Created on: 11 dec 2013
 *      Author: Akdas
 */

#ifndef GRAPHICENGINE_H_
#define GRAPHICENGINE_H_

class GraphicEngine {
public:
	GraphicEngine();
	virtual ~GraphicEngine();


	SDL_Rect* OutputRectangle();

	void DrawSprite(Sprite sprite_, double xpos_, double ypos_, int current_ticks);


private:

	SDL_Rect rect;

};

#endif /* GRAPHICS_H_ */
