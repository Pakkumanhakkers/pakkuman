/**
 * @file PathFinder.h
 *
 *  Created on: 12 dec 2013
 * @author Erik N inte philip iallafall
 */
 
#include <ifstream>
#inluce <iostream>
using namespace std;
 
 
 
 
Map::Map(SDL_Renderer* sent_renderer)
{
	//skapar sprites!
	Wall = Sprite(SDL_Renderer* sent_renderer, Wall.png, int 32, int 32);
	Floor = Sprite(SDL_Renderer* sent_renderer, Floor.png, int 32, int 32);

	char MapArray[15][20];		//Fyller på en array utifrån Map.txt
	int cor_x;
	int cor_y;
	ifstream Map;
	Map.open("Map.txt");
	 for(cor_y=0;cor_y<20;++cor_y)
	{
		for(cor_x=0;cor_x<15;cor_x++) 
		{
			Map >> MapArray[cor_x][cor_y];
			if(MapArray[cor_x][cor_y]=="#")
				Draw(Wall,cor_x,cor_y);
			else
				Draw(Floor,cor_x,cor_y);
				
		}
	}


	
	//ritar ut!
	
	
}
