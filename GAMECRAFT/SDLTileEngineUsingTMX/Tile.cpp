#include "Tile.h"

Tile::Tile()
{



}


Tile::~Tile()
{


}

Tile::Tile(int gid,int levelx,int levely,const char* imagesource,int tilesheetwidth,int tilesheetheight,int tilewidth,int tileheight,const char* mapOrientation,int row,int col,SDL_Renderer* renderer,int margin,int spacing)
{
	this->gid=gid - 1;
	if(gid==-1)
	{
		collidable=true;
	}
	else
	{
		collidable=false;
	}
	this->renderer=renderer;
	
	this->levelx=levelx;
	this->levely=levely;
	this->imagesource=imagesource;
	this->tilesheetwidth=tilesheetwidth;
	this->tilesheetheight=tilesheetwidth;
	this->tilewidth=tilewidth;
	this->tileheight=tileheight;
	this->margin=margin;
	this->spacing=spacing;
	int numRows= tilesheetwidth/tilewidth;
	int numColumns= tilesheetheight/tileheight;
	int gidRow=this->gid%numRows;
	int gidCol=this->gid/numColumns;
	imagex=((this->gid%numRows) * (tilewidth + spacing))  +margin ; //x
	imagey=((this->gid/numRows) * (tileheight + spacing)) + margin; //y
	
	//cout<<"imagex: "<<imagex<< " imagey:"<<imagey<<endl;
	imageLocation.x=imagex;
	imageLocation.y=imagey;
	imageLocation.w=tilewidth;
	imageLocation.h=tileheight;
	if(strcmp(mapOrientation,"orthogonal")==0)
	{
		whereToDraw.x=levelx;
		whereToDraw.y=levely;
	}
	if(strcmp(mapOrientation,"isometric")==0)
	{
		whereToDraw.x=((levelx-levely)/2);
		whereToDraw.y=((levelx + levely)/2)/2;
	}
	whereToDraw.w=tilewidth;
	whereToDraw.h=tileheight;
	this->mapOrientation=mapOrientation;
	
	


}


void Tile::Draw(SDL_Renderer* renderer)
{
	
	SDL_RenderCopy(renderer,ImageManager::texture,&imageLocation,&whereToDraw);

	
	
}

void Tile::Initialize()
{
	/*
	cout<< imagex<<endl;
	cout<< imagey<<endl;
	cout<< levelx<<endl;
	cout<< levely<<endl;
	*/
	

}