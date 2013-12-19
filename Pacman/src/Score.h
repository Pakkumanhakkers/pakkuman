/*
 * Score.h
 */

#ifndef SCORE_H_
#define SCORE_H_

#include "Drawable.h"

class GraphicEngine;


class Score : public Drawable
{
public:
	Score();

	void setScore(int score);
	void draw(GraphicEngine* graphic);

private:
	int score_;
	double xpos_;
	double ypos_;
};

#endif
