//this is the header for SpriteClass
#ifndef _SPRITECLASS_
#define _SPRITECLASS_

#pragma once
#include "Stdafx.h"

class SpriteClass
{
public:
	SpriteClass(SDL_Renderer* Passed_Renderer, std::string FilePath, int x, int y, int w, int h);//sprite x and y position, width, height
	~SpriteClass(void);

	void Draw();//The draw function for standart art assets
	void DrawAnimation(int currentFrame);//The draw function for animated sprites

	//Below code holds positions and is called to get and set the position of objects
	void PosX(int x);
	void PosY(int y);
	void PosSet(int x, int y);

	int GetX();
	int GetY();

//Creating pointers to be used in SpriteClass.cpp
private:
	SDL_Texture* Image;//The SDL_Texture function holds pixel data
	SDL_Rect DestinationRect;//SDL_Rect function is rectangle whose origin is at it's top left corner (0,0)
	SDL_Rect SourceRect; //For Animation so it changes frames
	SDL_Renderer* Renderer;//The pointer for Renderer
};

#endif
