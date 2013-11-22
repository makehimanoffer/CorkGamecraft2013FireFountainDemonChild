#include "Projectile.h"

Projectile::Projectile()
{



}


Projectile::Projectile(int x, int y, const char* imagesource, int direction,SDL_Renderer* renderer)
{
	this->x=x;
	this->y=y;
	this->imagesource=imagesource;
	this->direction=direction; //0 for left, 1 for right.
	this->renderer=renderer;
	Initialize(this->renderer);



}

Projectile::~Projectile()
{


}

void Projectile::Initialize(SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load("sheet.png");
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	



}

void Projectile::Update(SDL_Rect enemyrect)
{




}

void Projectile::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer,texture,NULL,boundingBox);

}