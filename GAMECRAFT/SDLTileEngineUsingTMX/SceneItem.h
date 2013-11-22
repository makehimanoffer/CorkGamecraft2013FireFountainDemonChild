#ifndef _SceneItem_H_
#define _SceneItem_H_

#include <thread>
#include <chrono>
#include <string>
#include <iostream>
#include <SDL.h>

using namespace std;
class SceneItem
{
public:
	SceneItem();
	SceneItem(const char*, SDL_Renderer*);
	virtual ~SceneItem();
	virtual void Initialize()=0;
	virtual void Update()=0;
	virtual void Release()=0;
	virtual void Draw(SDL_Renderer*)=0;
	
	
};


#endif