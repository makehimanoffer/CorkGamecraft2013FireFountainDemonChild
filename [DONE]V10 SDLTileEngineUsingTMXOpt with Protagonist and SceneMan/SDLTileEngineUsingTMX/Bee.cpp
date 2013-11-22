#include "Bee.h"

Bee::Bee()
{



}


Bee::Bee(int x, int y, const char* imagesource, int direction,SDL_Renderer* renderer)
{
    
	this->x=x;
	this->y=y;
	width=10;
	height=10;
	this->imagesource=imagesource;
	this->direction=direction; //0 for left, 1 for right.
	this->renderer=renderer;
	this->boundingBox.x=x;
	this->boundingBox.y=y;
	this->boundingBox.w=width;
	this->boundingBox.h=height;
	Initialize(this->renderer);



}

Bee::~Bee()
{


}

void Bee::Initialize(SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load("bullet.png");
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	



}

void Bee::Update(SDL_Rect enemyrect)
{
	this->boundingBox.x=x;
	this->boundingBox.y=y;
	if(direction==0)
	{
		x--;
	}
	if(direction==1)
	{
		x++;
	}



}

void Bee::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer,texture,NULL,&boundingBox);

}