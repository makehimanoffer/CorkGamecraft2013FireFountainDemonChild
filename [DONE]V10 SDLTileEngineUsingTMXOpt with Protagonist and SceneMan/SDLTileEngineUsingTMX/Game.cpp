#include "Game.h"

SDL_Renderer* Game::m_p_Renderer;
Game::Game(){
	
}
Game::~Game(){
}
bool Game::Initialize(const char* WindowName,int WindowX,int WindowY,int WindowWidth,int WindowHeight,int flags ){
	SDL_Init(SDL_INIT_EVERYTHING);

	m_p_Window= SDL_CreateWindow(WindowName,WindowX,WindowY,WindowWidth,WindowHeight,flags);
	Game::m_p_Renderer= SDL_CreateRenderer(m_p_Window,-1,0);
	manager=SceneManager::getInstance();
	p=new Protagonist(10,10,"sheet.png",m_p_Renderer,4,128,32);
	return m_running=true;
	
}

void Game::LoadContent(){
	//DEBUG_MSG("Loading Content");
	//m_p_Surface = SDL_LoadBMP("MightyNo9.bmp");
	//m_p_Texture =SDL_CreateTextureFromSurface(Game::m_p_Renderer,m_p_Surface);
	//SDL_FreeSurface(m_p_Surface);
}
void Game::UnloadContent(){

}

void Game::Update(){
	HandleEvents();
	
	p->Update();
}

void Game::HandleEvents(){
	SDL_Event event;
		//DEBUG_MSG("Running");

		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					m_running=false;
					break;
				case SDLK_1:
					manager->current=SceneManager::State::DESERT;
					manager->nextSceneItem(m_p_Renderer);
					break;
				case SDLK_2:
					manager->current=SceneManager::State::ISO;
					manager->nextSceneItem(m_p_Renderer);
					break;
				case SDLK_3:
					manager->current=SceneManager::State::GENERIC;
					manager->nextSceneItem(m_p_Renderer);
					break;
				
				
				}
			}
		}
	}


void Game::Render(){
	
	//SDL_FillRect(m_p_Surface,&m_p_Surface->clip_rect, SDL_MapRGB(m_p_Surface->format, r, g, b));
	//manager->nextSceneItem()->Draw(m_p_Renderer);
	manager->Update(m_p_Renderer);
	p->Draw(m_p_Renderer);
	
	
}
bool Game::IsRunning(){
	return m_running;
}


void Game::CleanUp(){
	if(m_p_Window){
		m_p_Window=0;
	}
	if(Game::m_p_Renderer){
		Game::m_p_Renderer=0;
	}
	if(p){
		p=0;
	}
	SDL_Quit();
	
}






