#ifndef _Bee_H_
#define _Bee_H_

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
using namespace std;
class Bee{
public:
	Bee();
	Bee(int,int,const char*,SDL_Renderer*,int);
	virtual ~Bee();
    void Initialize();

	 void Draw(SDL_Renderer*);
	 void Update();
	 void Fired();
	 SDL_Texture* LoadImage(const char*,SDL_Renderer*);

	int x,y;
	int width;
	int height;
	int direction;
	SDL_Rect boundingBox;
	SDL_Rect drawingRect;
	SDL_Texture* texture;




};
#endif