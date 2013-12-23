/**
 * @file PathFinder.h
 *
 *  Created on: 6 dec 2013
 * @author Erik N inte philip iallafall
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_
//#include "Map.h"

#include "Direction.h"

class Moveable;
class Map;
class GameEngine;
class PathFinder
{
public:
Direction getDirection(Moveable*, int, int);
Direction getDirection2(Moveable*, GameEngine*);
PathFinder(Map*);

private:
Map* internalMap;

};


#endif /* PATHFINDER_H_ */
