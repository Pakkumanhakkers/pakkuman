/**
 * @file Map.h
 *
 *  Created on: 11 dec 2013
 * @author ivar
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>

#include "Drawable.h"
#include "Sprite.h"
class Graphics;

/**
 * Beskriver en karta. Är statisk efter att data lästs in. Beskrivs med rutnät.
 */
class Map : public Drawable, public Sprite
{
public:
  enum TileType
  {
    FLOOR, WALL, DOT, CHERRY, PACMAN_SPAWN, GHOST_SPAWN
  };

  struct FoodInfo
  {
    int x;
    int y;
    TileType type;
  };

  Map(Sprite* wall, Sprite* floor);
  virtual ~Map();

  void
  loadFile(std::string filename);

  virtual void
  draw(Graphics*);

  int getWidth();
  int getHeight();
  bool isWall(int x, int y);
  TileType getTileType(int x, int y);

  int
  getPacmanX();
  int
  getPacmanY();
  int
  getGhostX();
  int
  getGhostY();
  std::vector<FoodInfo>*
  getFoodInfo();

private:
  void
  initMapExtras();

  TileType MapArray[15][20];

  Sprite* wallSprite_;
  Sprite* floorSprite_;

  int pacmanX_;
  int pacmanY_;
  int ghostX_;
  int ghostY_;
  std::vector<FoodInfo> foodInfo_;
};

#endif /* MAP_H_ */
