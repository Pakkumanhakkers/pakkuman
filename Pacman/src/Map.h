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
<<<<<<< HEAD

class Map : public Drawable, public Sprite
=======
class Drawable;
class Sprite;


class Map
>>>>>>> branch 'master' of https://github.com/Pakkumanhakkers/pakkuman.git
{
public:
<<<<<<< HEAD
=======
	Map(GraphicEngine* gre, Sprite* Wall, Sprite* Floor) : WallSprite{Wall}, FloorSprite{Floor}, graphicengine{gre} {}
	void drawMapArray();

>>>>>>> branch 'master' of https://github.com/Pakkumanhakkers/pakkuman.git
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
  
<<<<<<< HEAD
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
=======
  private:
  GraphicEngine* graphicengine;
  Sprite* WallSprite;
  Sprite* FloorSprite;
  TileType MapArray[15][20];

  
>>>>>>> branch 'master' of https://github.com/Pakkumanhakkers/pakkuman.git

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
