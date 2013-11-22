#ifndef _Layer_H_
#define _Layer_H_
#include "tinyxml2.h"
#include <vector>
#include <string>
#include <iostream>
#include "Tile.h"
#include <SDL.h>
#include "Tilemap.h"
using namespace std;
using namespace tinyxml2;


class Layer
{
public:
        Layer();
		Layer(const char*,int,const char*,int,int,int,int,int,int,const char*,SDL_Renderer*,int,int);
        ~Layer();
		
		void Initialize();
		void Draw(SDL_Renderer*);
		

        
private:
       
	   Tilemap* tm;
	   const char* xmlFile; 
	   XMLDocument doc;
	   XMLElement* elem;
	   int layerNumber;
	   const char* imagesource;
	   int layertilewidth;
	   int layertileheight; 
	   int tilesheetwidth;
	   int tilesheetheight; 
	   int tilewidth; 
	   int tileheight;
	   const char* mapOrientation;
	   SDL_Renderer* renderer;
	   int margin;
	   int spacing;
	  

};

#endif