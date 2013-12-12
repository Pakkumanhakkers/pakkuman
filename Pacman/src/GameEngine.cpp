/**
 * @file GameEngine.cpp
 *
 *  Created on: 9 dec 2013
 * @author tor
 */

void
GameEngine::initGame()
{
  int width = map_.getWidth();
  int height = map_.getHeight();

  for (int i = 0; i < width; ++i)
  {
    for (int j = 0; j < height; ++j)
    {
      switch (map_.getTileType(i, j))
      {
        case Map::TileType::DOT:
          gameInstance_.food.push_back(new Food{i, j, &spriteDot,
            settings_.scoreDot});
          break;
        case Map::TileType::STRAWBERRY:
          gameInstance_.food.push_back(new Food{i, j, &spriteDot,
            settings_.scoreFruit});
          break;
        case Map::TileType::PACMAN_SPAWN:
          gameInstance_.pacman = new Pacman{i, j, &spriteDot};
          break;
        case Map::TileType::GHOST_SPAWN:
          gameInstance_.ghosts.push_back(new Ghost{i, j, &spriteDot});
          break;
      }
    }
  }
}

void
GameEngine::gameLoop()
{
  int newTime = SDL_GetTicks();
  while (currentTime_ < newTime)
  {
    updateGame();
    currentTime_ += settings_.frameTime;
  }

  drawGame();
}

void
GameEngine::updateGame()
{
  gameInstance_.pacman->update(this);

  for (Moveable* moveable : gameInstance_.ghosts)
  {
    moveable->update(this);
  }

  if (gameInstance_.lives <= 0)
  {
    gameOver();
  }
}

void
GameEngine::drawGame()
{
  map_.draw(&graphics_);

  gameInstance_.pacman->draw(&graphics_);

  for (Moveable* object : gameInstance_.ghosts)
  {
    object->draw(&graphics_);
  }

  for (Food* object : gameInstance_.food)
  {
    object->draw(&graphics_);
  }
}

void
GameEngine::publishCommand(Command* command)
{
  commandManager_.add(command);
  command->execute();
}

void
GameEngine::publishTimer(Timer* timer)
{
  commandManager_.add(timer);
}

Map*
GameEngine::getMap()
{
  return &map_;
}

GameInstance*
GameEngine::getGame()
{
  return &gameInstance_;
}
