#include "Protagonist.h"
#include <SDL.h>
#include "Bee.h"
Protagonist::Protagonist()
{


}

Protagonist::Protagonist(int x,int y,const char* imagesource,SDL_Renderer* renderer, int numberOfCells,int imagewidth,int imageheight)
{
	this->x=x;
	this->y=y;
	this->imagewidth=imagewidth;
	this->imageheight=imageheight;
	this->tilewidth=imagewidth/numberOfCells;
	this->tileheight=imageheight;
	drawingRect.x=0;
	drawingRect.y=0;
	drawingRect.w=imagewidth/numberOfCells;
	drawingRect.h=imageheight;
	this->boundingBox.x=x;
	this->boundingBox.y=y;
	this->boundingBox.w=imagewidth/numberOfCells;
	this->boundingBox.h=tileheight;
	this->renderer=renderer;
	this->texture=LoadImage(imagesource,renderer);

}


Protagonist::~Protagonist()
{




}



void Protagonist::Draw(SDL_Renderer* renderer)
{
	
	for(int i=0;i<NOT_THE_BEES.size;i++){
		NOT_THE_BEES[i]->Draw(renderer);
	}
	SDL_RenderCopy(renderer,this->texture,&drawingRect,&boundingBox);
	

}

void Protagonist::Initialize()
{



}

void Protagonist::Update()
{
	
	const Uint8* keystate = SDL_GetKeyboardState(NULL);//returns all keys down. Passing in NULL does it for all keys.
	
	if(keystate[SDL_SCANCODE_W])
	{
		boundingBox.y--;
	}
	if(keystate[SDL_SCANCODE_S])
	{
		boundingBox.y++;
	}
	if(keystate[SDL_SCANCODE_A])
	{
		boundingBox.x--;
	}
	if(keystate[SDL_SCANCODE_D])
	{
		boundingBox.x++;
	}
	if(keystate[SDL_SCANCODE_SPACE])
	{
		NOT_THE_BEES.push_back(new Bee(x,y,"sheet.png",0,renderer));
	}
	Animate();

}

SDL_Texture* Protagonist::LoadImage(const char* image,SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load("sheet.png");
	SDL_Texture* t1 = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	return t1;

}

void Protagonist::Animate()
{
	if((time*SDL_GetTicks())%57==0){
	drawingRect.x+=tilewidth;
	if(drawingRect.x>=imagewidth-tilewidth)
	{
		drawingRect.x=0;
		
	}
	}
	time++;


}

