/**
 * @file Ghost.cpp
 *
 *  Created on: 13 dec 2013
 * @author Erik N inte philip iallafall
 */

using namespace std;

void Ghost::enterChase()
{
	AiComponent->setAi(AiInputComponent::CHASE);
}

void Ghost::enterScatter()
{
	AiComponent->setAi(AiInputComponent::SCATTER);
}

void Ghost::enterRandom()
{
	AiComponent->setAi(AiInputComponent::RANDOM);
}

void Ghost::enterHome()
{
	AiComponent->setAi(AiInputComponent::HOME);
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




