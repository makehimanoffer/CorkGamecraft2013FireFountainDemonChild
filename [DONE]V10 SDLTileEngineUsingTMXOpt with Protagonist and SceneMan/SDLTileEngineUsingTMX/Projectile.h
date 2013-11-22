#ifndef _Projectile_H_
#define _Projectile_H_

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
using namespace std;
class Projectile{
public:
	Projectile();
	Projectile(int,int,const char*,int,SDL_Renderer*);//x,y,imagesource, direction
	virtual ~Projectile();
	virtual void Initialize(SDL_Renderer*);

	virtual void Draw(SDL_Renderer*)=0;
	virtual void Update(SDL_Rect);// rect represents enemy at the time
	

	int x,y;
	int width;
	int height;
	int direction;
	const char* imagesource;
	SDL_Rect* boundingBox;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Renderer* renderer;




};
#endif