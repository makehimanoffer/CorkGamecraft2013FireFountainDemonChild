//this is the implementation for sprite class, the sprites are instantiated in the main class

#include "SpriteClass.h"


SpriteClass::SpriteClass(SDL_Renderer* pass_in_render, std::string FilePath, int x, int y, int w, int h)
{
	Renderer = pass_in_render;
	Image = NULL;
	Image = IMG_LoadTexture(Renderer,FilePath.c_str());//this line looks for a file as it's second parameter

	//Assigning SourceRect to passed parameters, for animating sprites
	SourceRect.x=0;
	SourceRect.y=0;
	SourceRect.w=w;
	SourceRect.h=h;

	//Assigning DestinationRect to the passed parameters
	DestinationRect.x = x;
	DestinationRect.y = y;
	DestinationRect.w = w;
	DestinationRect.h = h;

}


SpriteClass::~SpriteClass(void)//deconstructor
{
	SDL_DestroyTexture(Image);//Deconstructs Image
}

void SpriteClass::Draw()
{
	SDL_RenderCopy(Renderer, Image, NULL, &DestinationRect);//3rd parameter used for cropping
}

void SpriteClass::DrawAnimation(int currentFrame)
{
	//Update a Source Rectangle here with current Frame. Pass in currentFrame
	SourceRect.x = currentFrame * SourceRect.w;

	SDL_RenderCopy(Renderer, Image, &SourceRect, &DestinationRect);//3rd parameter used for cropping
}


//Getters and setters for positions are below
void SpriteClass::PosX(int x)
{
	DestinationRect.x = x;
}

void SpriteClass::PosY(int y)
{
	DestinationRect.y = y;
}

void SpriteClass::PosSet(int x, int y)
{
	DestinationRect.x = x;
	DestinationRect.y = y;
}

int SpriteClass::GetX()
{
	return DestinationRect.x;
}

int SpriteClass::GetY()
{
	return DestinationRect.y;
}