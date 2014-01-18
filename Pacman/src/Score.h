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

	void setScore(int newScore);
	void draw(GraphicEngine* graphic);
	int score;

private:

	double xpos_;
	double ypos_;
};

#endif
