#ifndef _Protagonist_H_
#define _Protagonist_H_

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Bee.h"
#include <vector>

using namespace std;
class Protagonist{
public:
	Protagonist();
	Protagonist(int,int,const char*,SDL_Renderer*,int,int,int);
	~Protagonist();
	vector<Bee*> b;
	void Initialize();
	void Update(SDL_Renderer*, SDL_Rect);
	SDL_Texture* LoadImage(const char*,SDL_Renderer*);
	void Draw(SDL_Renderer*);
	void Animate();
	int x,y;
	int width;
	int height;
	SDL_Rect boundingBox;
	SDL_Rect drawingRect;
	SDL_Texture* texture;
	int numberOfCells;
	int imagewidth;
	int imageheight;
	int tilewidth;
	int tileheight;
	int time;
	int gravity;
	bool checkCollision(SDL_Rect, SDL_Rect);
	bool checkCollisionLeft(SDL_Rect, SDL_Rect);
	bool checkCollisionRight(SDL_Rect, SDL_Rect);
	bool colliding;
	int leftPlayer, leftTile, rightPlayer, rightTile, bottomPlayer, bottomTile,topPlayer,topTile;
	bool pressed;


};
#endif