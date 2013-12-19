/*
 * Score.h
 */

#ifndef SCORE_H_
#define SCORE_H_

//#include "GraphicEngine.h"

class GraphicEngine;


class Score
{
public:
	Score() = default;

	void setScore(int added_score);
	void draw(GraphicEngine* graphic);

private:
	int score_ = 0;
	double xpos_ = 40;
	double ypos_ = 80;
};

#endif
