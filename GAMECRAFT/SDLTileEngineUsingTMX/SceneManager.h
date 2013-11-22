#ifndef _SceneManager_H_
#define _SceneManager_H_

#include "SceneItem.h"
#include "TMXReader.h"
#include "Menu.h"

class SceneManager
{
public:
	enum State{DESERT,ISO,GENERIC,MENU,LOADING};
	void Initialize();
	void Update(SDL_Renderer*);
	static SceneManager * getInstance();
	SceneItem* nextSceneItem(SDL_Renderer*);

private:
	SceneManager();
	
	SceneManager(const SceneManager&);
	virtual ~SceneManager();

public:
	enum State last;
	enum State current;
	SceneItem * previous;
	SceneItem * active;

private:
	static SceneManager * manager;
	SDL_Renderer* renderer;

};



#endif