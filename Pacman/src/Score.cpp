/*
 * Score.cpp
 */

#include "Score.h"

#include <sstream>
#include <string>

#include "GraphicEngine.h"

void Score::setScore(int added_score)
{
	score_ =  added_score;
}

void Score::draw(GraphicEngine* graphic)
{
	// convert score_ to a string
	std::string Result;
	std::ostringstream convert;
	convert << score_;      // insert the textual representation of score_ in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the stream

	graphic->draw(Result, xpos_, ypos_);
}
