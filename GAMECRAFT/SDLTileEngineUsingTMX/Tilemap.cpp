#include "Tilemap.h"

vector<Tile*> Tilemap::tiles;
Tilemap::Tilemap()
{
	

	
}

Tilemap::Tilemap(vector<int>gid, const char* imagesource, int layertilewidth, int layertileheight, int tilesheetwidth,int tilesheetheight, int tilewidth, int tileheight,const char* mapOrientation,SDL_Renderer* renderer,int margin,int spacing)
{
	this->gid=gid;
	this->imagesource=imagesource;
	this->layertilewidth=layertilewidth;
	this->layertileheight=layertileheight;
	this->tilesheetwidth=tilesheetwidth;
	this->tilesheetheight=tilesheetheight;
	this->tilewidth=tilewidth;
	this->tileheight=tileheight;
	this->mapOrientation=mapOrientation;
	this->renderer=renderer;
	this->margin=margin;
	this->spacing=spacing;
	im= new ImageManager(imagesource,renderer);

}

Tilemap::~Tilemap()
{


}




void Tilemap::Initialize()
{
	
	tiles.resize(layertilewidth*layertileheight);
	for (int row = 0; row < layertilewidth; row++) {
		for (int col = 0; col < layertileheight; col++) {
			//cout<< row * layertileheight + col <<endl;

			tiles[row * layertileheight + col]= new Tile(gid[row * layertilewidth + col],col*tilewidth,row*tileheight,imagesource,tilesheetwidth,tilesheetheight,tilewidth,tileheight,mapOrientation,row,col,renderer,margin,spacing);
			//tiles[row * layertileheight + col]= new Tile(gid->at(row * layertileheight + col),row*tilewidth,col*tileheight,imagesource,tilesheetwidth,tilesheetheight,tilewidth,tileheight);
		}
	}
	for(int i=0;i<tiles.size();i++)
	{
		tiles[i]->Initialize();
	}
	

}

void Tilemap::Draw(SDL_Renderer* renderer)
{
	for(int i=0;i<tiles.size();i++)
	{
		tiles[i]->Draw(renderer);
	}

}
