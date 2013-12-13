/**
 * @file Ghost.cpp
 *
 *  Created on: 13 dec 2013
 * @author Erik N inte philip iallafall
 */

using namespace std;

void Ghost::enterChase()
{
	AiType = CHASE;
}

void Ghost::enterScatter()
{
	AiType = SCATTER;
}

void Ghost::enterRandom()
{
	AiType = RANDOM;
}

void Ghost::enterHome()
{
	AiType = HOME;
}

void Ghost::heal()
{
	health_state_ = NORMAL;
}

void Ghost::Wound()
{
	health_state_ = EATABLE;
}

void Ghost::blink() // Vad ska hända här?
{
		
}


