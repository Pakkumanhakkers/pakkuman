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
class Drawable;
class Sprite;


class Map
{
public:
	Map(GraphicEngine* gre, Sprite* Wall, Sprite* Floor) : WallSprite{Wall}, FloorSprite{Floor}, graphicengine{gre} {}
	void drawMapArray();

  enum TileType
  {
    FLOOR, WALL, DOT, CHERRY, PACMAN_SPAWN, GHOST_SPAWN
  };

  Map();
  virtual ~Map();

  virtual void draw(Graphics*);

  int getWidth();
  int getHeight();
  bool isWall(int x, int y);
  TileType getTileType(int x, int y);
  
  private:
  GraphicEngine* graphicengine;
  Sprite* WallSprite;
  Sprite* FloorSprite;
  TileType MapArray[15][20];

  

};

#endif /* MAP_H_ */
