/**
 * @file Food.cpp
 *
 *  Created on: 12 dec 2013
 * @author ivar
 */




Food::Food(double x, double y, Sprite* sprite, int score) :
  GameObject{x, y, sprite}, score_{score}, eaten_{false} {}

virtual void
Food::eat(GameEngine* gameEngine)
{
  gameEngine->publishCommand(new ScoreCommand{gameEngine->getGame(), score_});
  gameEngine->publishCommand(new FoodEatenCommand{this});
}

void
Food::setEaten(bool eaten)
{
  eaten_ = eaten;
}

bool
Food::getEaten()
{
  return eaten_;
}
