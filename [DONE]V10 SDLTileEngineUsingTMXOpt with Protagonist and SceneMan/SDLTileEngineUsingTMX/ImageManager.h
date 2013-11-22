#ifndef _ImageManager_H_
#define _ImageManager_H_

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

using namespace std;
class ImageManager{
public:
	ImageManager();
	ImageManager(const char*,SDL_Renderer*);
	virtual ~ImageManager();
	void Initialize();
	
	
	SDL_Surface* surface;
	static SDL_Texture* texture;
	SDL_Renderer* renderer;
private:
	



};
#endif