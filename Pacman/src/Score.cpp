/*
 * Score.cpp
 */

#include "Score.h"

#include <sstream>
#include <string>

#include "GraphicEngine.h"

Score::Score() :
score_{0}, xpos_{40}, ypos_{80}
{
}

void Score::setScore(int score)
{
  score_ =  score;
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
