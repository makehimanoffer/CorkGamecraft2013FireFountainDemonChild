
#include "Tilemap.h"
#include "TMXReader.h"
#include "Layer.h"
#include "Tile.h"

#include "Game.h"
using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
Game* game;
int main( int argc, char* args[] )
{
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
	}
	game->CleanUp();
	
	return 0;
}