#include "Layer.h"


Layer::Layer()
{
	

	
}

Layer::Layer(const char* xmlFile,int layerNumber, const char* imagesource, int layertilewidth, int layertileheight, int tilesheetwidth,int tilesheetheight, int tilewidth, int tileheight,const char* mapOrientation,SDL_Renderer* renderer,int margin,int spacing)
{
	this->xmlFile=xmlFile;
	this->layerNumber=layerNumber;
	this->imagesource=imagesource;
	this->layertilewidth=layertilewidth;
	this->layertileheight=layertileheight;
	this->tilesheetwidth=tilesheetwidth;
	this->tilesheetheight=tilesheetheight;
	this->tilewidth=tilewidth;
	this->tileheight=tileheight;
	this->mapOrientation=mapOrientation;
	this->renderer=renderer;
	//cout<<"constructor of Layer"<<endl;
	this->margin=margin;
	this->spacing=spacing;

}

Layer::~Layer()
{


}


void Layer::Initialize()
{
	doc.LoadFile(xmlFile);
	elem=doc.FirstChildElement("map")->FirstChildElement("layer");
	int counter=0;
	vector <int> gid;
	while(elem!=NULL)
	{
		if(counter==layerNumber)
		{
			XMLElement* temp=elem->FirstChildElement("data")->FirstChildElement("tile");
			while(temp!=NULL)
			{
				gid.push_back(atoi(temp->Attribute("gid")));
				temp=temp->NextSiblingElement();
			}
		}
		counter++;
		if(elem!=NULL)
		{
			elem=elem->NextSiblingElement();
		}
	}
	
	
	tm= new Tilemap(gid,imagesource,layertilewidth,layertileheight,tilesheetwidth,tilesheetheight,tilewidth,tileheight,mapOrientation,renderer,margin,spacing);
	tm->Initialize();


}

void Layer::Draw(SDL_Renderer* renderer)
{
	tm->Draw(renderer);

}
