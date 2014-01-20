/*
 * Highscore.h
 *
 *  Created on: Jan 20, 2014
 *      Author: erik
 */

#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include "Drawable.h"

class GraphicEngine;

class Highscore : public Drawable
{
public:
	Highscore();
	virtual ~Highscore();


	void saveHighscore(int newScore);
	void loadHighscore();
	void print();
	void draw(GraphicEngine* graphic);

private:
	int score;
	double xpos_;
	double ypos_;
};

#endif /* HIGHSCORE_H_ */
