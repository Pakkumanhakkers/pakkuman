/*
 * Score.cpp
 */

#include "Score.h"

#include <sstream>
#include <string>
#include <iostream>

#include "GraphicEngine.h"

Score::Score() :
score{0}, xpos_{40}, ypos_{80}, update{false}
{
}

void Score::setScore(int newScore)
{
	if(newScore > score)
	{
		score =  newScore;
		update = true;
	}
}

void Score::draw(GraphicEngine* graphic)
{
  // convert score_ to a string
  std::string Result;
  std::ostringstream convert;
  convert << score;      // insert the textual representation of score_ in the characters in the stream
  Result = convert.str(); // set 'Result' to the contents of the stream
  graphic->draw(Result, xpos_, ypos_);
}

void Score::print()
{
	if (update)
	{
		std::cout << score << std::endl;
		update = false;
	}
}

void Score::resetScore()
{
	score = 0;
}

