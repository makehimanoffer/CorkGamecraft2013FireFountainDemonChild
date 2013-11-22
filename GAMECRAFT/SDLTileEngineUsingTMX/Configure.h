//The following class is the header for the implementation that sets up the Window and Renderer
#ifndef _CONFIGURE_
#define _CONFIGURE_

#pragma once //run once
#include "Stdafx.h"

class Configure
{
public:
	Configure(bool* Quit, int ScreenWidth, int ScreenHeight);
	~Configure(void);

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();
private:
	//Creating pointers to the necessary functions to be used in the Configure.cpp file
	SDL_Window* Window;
	SDL_Renderer* Renderer;
	SDL_Event* MainEvent;

};

#endif