#include "TileManager.h"


TileManager::TileManager()
{
	doc.LoadFile("tilemap.tmx");


}

TileManager::~TileManager()
{


}


void TileManager::readXML()
{
	const char* xmlVersion;
	const char* xmlOrientation;
	const char* tilemapwidth;
	const char* tilemapheight;
	const char* tilesetwidth;
	const char* tilesetheight;
	const char* firstgid;
	const char* tilemapname;
	const char* tilewidth;
	const char* tileheight;
	const char* imagesource;
	const char* tilesheetwidth;
	const char* tilesheetheight;

	elem=doc.FirstChildElement("map");
	xmlVersion= elem->Attribute("version",NULL);
	xmlOrientation= elem->Attribute("orientation",NULL);
	tilemapwidth= elem->Attribute("width",NULL);
	tilemapheight= elem->Attribute("height",NULL);
	tilesetwidth= elem->Attribute("tilewidth",NULL);
	tilesetheight= elem->Attribute("tileheight",NULL);
	cout<< xmlVersion<<endl;
	cout<< xmlOrientation<<endl;
	cout<< tilemapwidth<<endl;
	cout<< tilemapheight<<endl;
	cout<< tilesetwidth<<endl;
	cout<< tilesetheight<<endl;
	elem=doc.FirstChildElement("map")->FirstChildElement("tileset");
	firstgid=elem->Attribute("firstgid",NULL);
	cout<< firstgid<<endl;
	tilemapname=elem->Attribute("name",NULL);
	cout<<tilemapname<<endl;
	tilewidth=elem->Attribute("tilewidth",NULL);
	tileheight=elem->Attribute("tileheight",NULL);
	cout<<tilewidth<<endl;
	cout<<tileheight<<endl;
	elem=doc.FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image");
	imagesource=elem->Attribute("source",NULL);
	tilesheetwidth=elem->Attribute("width",NULL);
	tilesheetheight=elem->Attribute("height",NULL);
	cout<<imagesource<<endl;
	cout<<tilesheetwidth<<endl;
	cout<<tilesheetwidth<<endl;



}
