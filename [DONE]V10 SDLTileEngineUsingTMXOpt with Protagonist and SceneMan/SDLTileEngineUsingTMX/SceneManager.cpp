#include "SceneManager.h"
SceneManager* SceneManager::manager; 



SceneManager::SceneManager()
{
	
	last= LOADING;
	current= MENU;//was MENU
	active=new Menu();
	
}


SceneManager::SceneManager(const SceneManager& other)
{
	
}


SceneManager::~SceneManager()
{
}

void SceneManager::Initialize(){

	
}

void SceneManager::Update(SDL_Renderer* renderer){

	active->Draw(renderer);

}

SceneItem* SceneManager::nextSceneItem(SDL_Renderer* renderer){
	
	switch(current){
		
		case MENU:
                    if (last != MENU)
                    {
                        active = new Menu();
                        active->Initialize();
                        
                        
                        last = MENU;

                        if (previous)
                            previous=0;
						
                        previous = active;
                    }
                    break;
					
		case DESERT:
			if (last != DESERT)
                    {
						active= new TMXReader("Test.tmx",renderer);
						active->Initialize();
						
                        
                        
						last = DESERT;

                        if (previous)
                            previous=0;
						
                        previous = active;
                    }
                    break;

		case ISO:
			if (last != ISO)
                    {
						active = new TMXReader("isometric_grass_and_water.tmx",renderer);
						active->Initialize();
						
                        
                        
						last = ISO;

                        if (previous)
                            previous=0;
						
                        previous = active;
                    }
                    break;

		case GENERIC:
			if (last != GENERIC)
                    {
						active = new TMXReader("tilemap2.tmx",renderer);
						active->Initialize();
						
                        
                        
						last = GENERIC;

                        if (previous)
                            previous=0;
						
                        previous = active;
                    }
                    break;


		

		default:
			last=LOADING;
			break;



	}

	return active;

}

SceneManager * SceneManager::getInstance(){
	if(!manager)
		manager = new SceneManager();
	return manager;

}
