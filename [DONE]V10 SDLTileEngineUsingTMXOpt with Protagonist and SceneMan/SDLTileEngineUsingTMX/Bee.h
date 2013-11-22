#ifndef _Bee_H_
#define _Bee_H_


#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
class Bee{
public:
	Bee();
	Bee(int,int,const char*,int,SDL_Renderer*);//x,y,imagesource, direction
	virtual ~Bee();
	void Initialize(SDL_Renderer*);

	void Draw(SDL_Renderer*);
	void Update(SDL_Rect);// rect represents enemy at the time
	

	int x,y;
	int width;
	int height;
	int direction;
	const char* imagesource;
	SDL_Rect boundingBox;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Renderer* renderer;




};
#endif