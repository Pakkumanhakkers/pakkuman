/**
 * @file Ghost.cpp
 *
 *  Created on: 13 dec 2013
 * @author Erik N inte philip iallafall
 */

using namespace std;

void Ghost::enterChase()
{
	CurrentAi = CHASE;
}

void Ghost::enterScatter()
{
	CurrentAi = SCATTER;
}

void Ghost::enterRandom()
{
	CurrentAi = RANDOM;
}

void Ghost::enterHome()
{
	CurrentAi = HOME;
}

void Ghost::heal()
{
	CurrentHealthState = NORMAL;
}

void Ghost::wound()
{
	CurrentHealthState = EATABLE;
}

void Ghost::blink() // Vad ska hända här?
{
		
}

AiType Ghost::getAiType()
{
return CurrentAi;
}


