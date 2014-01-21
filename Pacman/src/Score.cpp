/*
 * Score.cpp
 */

#include "Score.h"

#include <sstream>
#include <string>
#include <iostream>

#include "GraphicEngine.h"

Score::Score() :
score{0}, xpos_{1}, ypos_{1}, update{true}
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
  if (!update)
  {
    return;
  }
  print();

  // convert score_ to a string
  std::string result;
  std::ostringstream convert;
  convert << score;      // insert the textual representation of score_ in the characters in the stream
  result = convert.str(); // set 'Result' to the contents of the stream
  graphic->draw(result, xpos_, ypos_);

  update = false;
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

