/**
 * @file Map.h
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#ifndef MAP_H_
#define MAP_H_

/**
 * Beskriver en karta. Är statisk efter att data lästs in. Beskrivs med rutnät.
 */
class Map
{
public:
  enum TileType
  {
    FREE, WALL, DOT, STRAWBERRY, PACMAN_SPAWN, GHOST_SPAWN // mer?
  };

  Map();
  virtual
  ~Map();

  int
  getWidth();
  int
  getHeight();
  bool
  isWall(int x, int y);
  TileType
  getTileType(int x, int y);

  // ...
};

#endif /* MAP_H_ */
