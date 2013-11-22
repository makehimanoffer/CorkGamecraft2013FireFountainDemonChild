#include "ImageManager.h"

SDL_Texture* ImageManager::texture;
ImageManager::ImageManager()
{


}

ImageManager::ImageManager(const char* imagesource,SDL_Renderer* renderer)
{
	this->renderer=renderer;
	surface = IMG_Load(imagesource);
	ImageManager::texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);

}


ImageManager::~ImageManager()
{




}




