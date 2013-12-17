/**
 * @file GameInstance.cpp
 *
 *  Created on: 17 dec 2013
 * @author ivar
 */


GameInstance::~GameInstance()
{
  for (auto itr = ghosts.begin(); itr < ghosts.end();)
  {
    delete itr;
    itr = ghosts.erase(itr);
  }

  for (auto itr = ghosts.begin(); itr < ghosts.end();)
  {
    delete itr;
    itr = ghosts.erase(itr);
  }

  delete pacman;
}
