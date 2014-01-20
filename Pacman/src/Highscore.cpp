/*
 * Highscore.cpp
 *
 *  Created on: Jan 20, 2014
 *      Author: erik
 */

#include "Highscore.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "GraphicEngine.h"
using namespace std;

Highscore::Highscore()  :
score{0}, xpos_{500}, ypos_{80}
{


}

Highscore::~Highscore() {

}

void Highscore::saveHighscore(int newScore)
{
	if (newScore > score)
	{
		std::cout << "New highscore!" << std::endl;
		score = newScore;
		ofstream output;
		output.open("R/Highscore.txt");
		if (output.is_open())
		{
		output << score;
		}
		output.close();
	}
}


void Highscore::loadHighscore()
	{
	int tempScore;
	ifstream input;
	input.open("R/Highscore.txt", ifstream::in);
	if (input.is_open())
	{
		input >> tempScore;
		score = tempScore;
	}

	input.close();
	//open file, read score, possibly convert to int and set as score
	}

void Highscore::print()
{
	std::cout << "Current highscore is: " << score << std::endl;
}

void Highscore::draw(GraphicEngine* graphic)
{
  // convert score_ to a string
  std::string Result;
  std::ostringstream convert;
  convert << score;      // insert the textual representation of score_ in the characters in the stream
  Result = convert.str(); // set 'Result' to the contents of the stream
  graphic->draw(Result, xpos_, ypos_);
}
