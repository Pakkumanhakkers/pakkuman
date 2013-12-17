/**
 * @file PathFinder.h
 *
 *  Created on: 6 dec 2013
 * @author Erik N inte philip iallafall
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_


//#include "GameEngine.h"
//#include "Map.h"
#include "Moveable.h"
class Map;

class PathFinder
{
public:
Direction getDirection(Moveable*, int, int);
PathFinder(Map*);

private:
Map* internalMap;

};





#endif /* PATHFINDER_H_ */
