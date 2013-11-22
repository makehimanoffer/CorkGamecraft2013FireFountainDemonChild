#ifndef _TMXReader_H_
#define _TMXReader_H_
#include "tinyxml2.h"
#include <vector>
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "SceneItem.h"
#include "Layer.h"
using namespace std;
using namespace tinyxml2;


class TMXReader : public SceneItem
{
public:
        TMXReader();
		TMXReader(const char*,SDL_Renderer*);
        ~TMXReader();
		void readXML(const char*);
		void Initialize();
		void Draw(SDL_Renderer*);
		void Update();
		void Release();
		

        
private:
       XMLDocument doc;
	   XMLElement* elem;
	   vector <int> gid;
	   vector <Layer*> layers;
	   const char* tilemap;
	   SDL_Renderer* renderer;
	   const char* imagesource;
	   int spacing;
	   int margin;
	   string image;

	   const char* xmlOrientation; //orientation
	   int tilemapwidth; //number of tiles in width (e.g 10)
	   int tilemapheight; // number of tiles in height (e.g 10)
	   int tilesetwidth; // width of tile in map (e.g 32)
	   int tilesetheight;// height of tile in map (32)
	   const char* tilemapname; //name of tilemap in tileset
	   int tilewidth; //width of tile in tileset
	   int tileheight; //height of  tile in tileset 
	   int tilesheetwidth; //width of tilesheet
	   int tilesheetheight; //height of tilesheet
	   const char* layername; // name of layer
	   int layertilewidth; //number of tiles width
	   int layertileheight; //number of tiles height
	   XMLElement* temp;
	   
	  

};

#endif