#ifndef _Tilemap_H_
#define _Tilemap_H_
#include "tinyxml2.h"
#include <vector>
#include <string>
#include <iostream>
#include "Tile.h"
#include "ImageManager.h"
#include <SDL.h>

using namespace std;
using namespace tinyxml2;


class Tilemap
{
public:
        Tilemap();
		Tilemap(vector<int>,const char*,int,int,int,int,int,int,const char*,SDL_Renderer*,int,int);
        ~Tilemap();
		
		void Initialize();
		void Draw(SDL_Renderer*);
		static vector <Tile*> tiles;
		

        
private:
      
	   
	   vector<XMLElement*> layers;
	   vector <int> gid; 
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
	   ImageManager* im;
	  

};

#endif