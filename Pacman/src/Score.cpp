/*
 * Score.cpp
 */

#include "Score.h"

#include <sstream>
#include <string>

#include "GraphicEngine.h"

void Score::UpdateScore(int added_score)
{
	score_ = score_ + added_score;
}

void Score::Draw(GraphicEngine* graphic)
{
	// convert score_ to a string
	std::string Result;
	std::ostringstream convert;
	convert << score_;      // insert the textual representation of score_ in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the stream

	graphic->Draw(Result, xpos_, ypos_);
}
