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
 
class Map : public Drawable, public Sprite
{
public:
	Map(SDL_Renderer* sent_renderer);
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
  SDL_Renderer* MapRenderer;
  TileType MapArray[15][20];
  Sprite WallSprite = Sprite(SDL_Renderer* sent_renderer, Wall.png, int 32, int 32);
  Sprite FloorSpirte = Sprite(SDL_Renderer* sent_renderer, Floor.png, int 32, int 32);
  DotSprite = Sprite(SDL_Renderer* sent_renderer, Dot.png, int 32, int 32);
  CherrySprite = Sprite(SDL_Renderer* sent_renderer, Cherry.png, int 32, int 32);
  

};

#endif /* MAP_H_ */
