#ifndef _TileManager_H_
#define _TileManager_H_
#include "tinyxml2.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
using namespace tinyxml2;


class TileManager
{
public:
        TileManager();

        ~TileManager();
		void readXML();

        
private:
       XMLDocument doc;
	   XMLDeclaration* dec;
	   XMLElement* elem;
	   XMLText* text;
	   XMLAttribute* attribs;
	   vector <int>  tileNumbers;
	   vector <string> tilegid;
	   string orientation;
	   string tilemapwidth;
	   string tilemapheight;
	   vector <string> tilewidth;
	   vector <string> tileheight;
	   string tilesetwidth;
	   string tilesetheight;

};

#endif