
#include "Tilemap.h"
#include "TMXReader.h"
#include "Layer.h"
#include "Tile.h"
#include "GameClass.h"

#include "Game.h"
#include <thread>
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
Game* game;
GameClass* Gameclass1;
void alansGame();
void davidsGame();
int main( int argc, char* args[] )
{
	thread t1(alansGame);
	thread t2(davidsGame);
	
	
	
	t1.join();
	t2.join();
	return 0;
}

void alansGame(){
	Gameclass1 = new GameClass(1000,600);//screen size specified here
	
	Gameclass1->MainGameLoop();//This calls the main game loop from gameClass.cpp
	
	
}
void davidsGame(){
	game= new Game();
	
	
	game->Initialize("THIS IS SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
	cout << "Enter 1 for Desert, 2 for Isometric or 3 for Multilayer Generic Tilemap"<<endl;
	
	//tmxr->Initialize();
	game->LoadContent();
	while(game->IsRunning())
	{
		
		
		SDL_RenderClear(game->m_p_Renderer);
		
		//tmxr->Draw(game->m_p_Renderer);
		game->Render();
		SDL_RenderPresent(game->m_p_Renderer);
		game->Update();
		SDL_Delay(1000);
	}
	game->CleanUp();
}