/**
 * @file PathFinder.h
 *
 *  Created on: 6 dec 2013
 * @author Erik N inte philip iallafall
 */

#ifndef GHOST_H_
#define GHOST_H_


#include "Moveable.h"



class Ghost
{
public:
Ghost(int aiType, int speed);
void FindPath();
void Die();
void ToggleEatable(bool);
int eatable;
int speed;
int aiType;
string ghost_name;

};




#endif /* PATHFINDER_H_ */