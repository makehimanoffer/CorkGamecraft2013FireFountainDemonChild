#ifndef _GameObject_H_
#define _GameObject_H_

#include <SDL.h>
#include <iostream>
#include "Game.h"
using namespace std;
class GameObject{
public:
	GameObject();
	GameObject(int,int,const char*,SDL_Renderer*,int,int,int);
	virtual ~GameObject();
	virtual void Initialize();

	virtual void Draw(SDL_Renderer*)=0;
	virtual void Update();
	virtual SDL_Texture* LoadImage(const char*,SDL_Renderer*);

	int x,y;
	int width;
	int height;
	SDL_Rect* boundingBox;




};
#endif