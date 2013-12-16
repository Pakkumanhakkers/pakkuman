/*
 * Score.cpp
 */

#include "Score.h"
#include <sstream>

void Score::UpdateScore(int added_score)
{
	score_ = score_ + added_score;
}

void Score::Draw()
{
	// convert score_ to a string
	string Result;
	ostringstream convert;
	convert << score_;      // insert the textual representation of score_ in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the stream

	GraphicEngine->Draw(Result, xpos_, ypos_);
}
