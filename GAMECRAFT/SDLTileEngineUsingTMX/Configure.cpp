//this is the implementation of Configure for Window and Renderer, specific values for Window size in game
#include "Configure.h"

Configure::Configure(bool* quit, int ScreenWidth, int ScreenHeight)
{
	Window = SDL_CreateWindow("My Window", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);//SDL_WINDOW_SHOWN, SDL_WINDOW_FULLSCREEN, SDL_WINDOW_RESIZABLE
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);//Uses the SDL 2D accellerated renderer
	MainEvent = new SDL_Event();//The pointer MainEvent from Configure.h is made a new SDL_EVENT here
}

Configure::~Configure(void)//the deconstructor
{
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	delete MainEvent;
}
//getters are below, for renderer and main event
SDL_Renderer* Configure::GetRenderer()//Gets the renderer
{
	return Renderer;
}

SDL_Event* Configure::GetMainEvent()//Gets the main event
{
	return MainEvent;
}

void Configure::Begin()
{
	SDL_PollEvent(MainEvent);//This polls for current events (in this case MainEvent)
	SDL_RenderClear(Renderer);//Render clear function to clear the current rendering target of Renderer
}

void Configure::End()
{
	SDL_RenderPresent(Renderer);//Updates the screenb with renderin performed
}