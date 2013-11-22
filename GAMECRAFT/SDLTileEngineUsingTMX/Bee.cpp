#include "Bee.h"
#include <SDL.h>
#include "SceneManager.h"

Bee::Bee()
{
	//write your initilissation in here ya mad lad

}

Bee::Bee(int x,int y,const char* imagesource,SDL_Renderer* renderer, int direction)
{
	this->x=x;
	this->y=y;
	
	this->boundingBox.x=x;
	this->boundingBox.y=y;
	this->boundingBox.w=32;
	this->boundingBox.h=32;
	this->drawingRect.x=0;
	this->drawingRect.y=0;
	this->drawingRect.w=32;
	this->drawingRect.h=32;
	this->texture=LoadImage(imagesource,renderer);
	this->direction=direction;
	

}


Bee::~Bee()
{




}



void Bee::Draw(SDL_Renderer* renderer)// we draw when fired??
{
	//if(bounding box of bee == bounding box of player,
	//() player. its not gona hit who fired it)
	//return false; //this will call the destructor for bee from
	//outside class. 


	SDL_RenderCopy(renderer,this->texture,&drawingRect,&boundingBox);
	

}

void Bee::Fired()
{
		
}

SDL_Texture* Bee::LoadImage(const char* image,SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(image);
	SDL_Texture* t1 = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	return t1;

}

void Bee::Initialize()
{



}

void Bee::Update()
{
	if(direction==0)
	{
	boundingBox.x++;
	}
	if(direction==1)
	{
		boundingBox.x--;
	}


	
	
	

}





