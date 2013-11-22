#ifndef _Game_H_
#define _Game_H_
#include <SDL.h>
#include "Protagonist.h"
#include <SDL_image.h>
#include "SceneManager.h"


class Game{
public:
	Game();
	~Game();
	bool Initialize(const char*,int,int,int,int,int);
	void Render();
	void Update();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();
	void LoadContent();
	void UnloadContent();
	void setCamera();
	void apply_surface(int, int , SDL_Surface* , SDL_Surface*, SDL_Rect*);


	static SDL_Renderer* m_p_Renderer;

private:
	bool m_running;
	SDL_Window* m_p_Window;
	
	SDL_Texture* m_p_Texture;
	SDL_Rect m_Source;
	SDL_Rect m_Destination;
	SDL_Surface* m_p_Surface;
	Protagonist* p;
	SceneManager* manager;
	SDL_Rect camera; 

};
#endif
