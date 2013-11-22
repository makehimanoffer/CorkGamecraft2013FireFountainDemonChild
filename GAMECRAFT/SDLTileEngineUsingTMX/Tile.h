#ifndef _Tile_H_
#define _Tile_H_

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "ImageManager.h"
using namespace std;
class Tile{
public:
	Tile();
	Tile(int,int,int,const char*,int,int,int,int,const char*,int,int,SDL_Renderer*,int,int);
	~Tile();
	void Initialize();

	void Draw(SDL_Renderer*);

	int gid;
	int levelx;
	int levely;
	const char* imagesource;
	int tilesheetwidth;
	int tilesheetheight;
	int tilewidth;
	int tileheight;
	int imagex;
	int imagey;
	SDL_Rect whereToDraw;//position in level;
	SDL_Rect imageLocation; //position on image
	SDL_Texture* texture;
	SDL_Surface* surface;
	int layerNumber;
	const char* mapOrientation;
	
	SDL_Renderer* renderer;
	int margin;
	int spacing;
	bool collidable;


};
#endif