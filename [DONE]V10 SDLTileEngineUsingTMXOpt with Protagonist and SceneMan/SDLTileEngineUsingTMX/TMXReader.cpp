#include "TMXReader.h"


TMXReader::TMXReader()
{
	

	
}

TMXReader::TMXReader(const char* tilemap,SDL_Renderer* renderer)
{
	this->tilemap=tilemap;
	this->renderer=renderer;
	spacing=0;
	margin=0;
	image="tilemap.png";
	
	

}

TMXReader::~TMXReader()
{


}


void TMXReader::readXML( const char* xmlFile)
{
	doc.LoadFile(xmlFile);
	

	elem=doc.FirstChildElement("map");
	
	xmlOrientation= elem->Attribute("orientation",NULL);
	tilemapwidth= atoi(elem->Attribute("width",NULL));
	tilemapheight= atoi(elem->Attribute("height",NULL));
	tilesetwidth= atoi(elem->Attribute("tilewidth",NULL));
	tilesetheight= atoi(elem->Attribute("tileheight",NULL));
	
	
	elem=doc.FirstChildElement("map")->FirstChildElement("tileset");
	
	if(elem->Attribute("name")!=NULL)
	tilemapname=elem->Attribute("name",NULL);
	
	if(elem->Attribute("tilewidth")!=NULL)
	tilewidth=atoi(elem->Attribute("tilewidth",NULL));

	if(elem->Attribute("tileheight")!=NULL)
	tileheight=atoi(elem->Attribute("tileheight",NULL));
	
	
	if(doc.FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image")!=NULL)
	{
	elem=doc.FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image");
	image=elem->Attribute("source",NULL);
	tilesheetwidth= atoi(elem->Attribute("width",NULL));
	tilesheetheight=atoi(elem->Attribute("height",NULL));
	
	}
	if(doc.FirstChildElement("map")->FirstChildElement("tileset")->FirstChildElement("image")==NULL)
	{
	  elem=doc.FirstChildElement("map")->FirstChildElement("tileset");
	  XMLDocument tsx;
	  XMLElement* tsxelem;
	  tsx.LoadFile(elem->Attribute("source"));
	  tsxelem= tsx.FirstChildElement("tileset");
	  tilewidth=atoi(tsxelem->Attribute("tilewidth"));
	  spacing=atoi(tsxelem->Attribute("spacing"));
	  margin=atoi(tsxelem->Attribute("margin"));
	  tileheight=atoi(tsxelem->Attribute("tileheight"));
	  tsxelem=tsx.FirstChildElement("tileset")->FirstChildElement("image");
	  image= tsxelem->Attribute("source");
	  tilesheetwidth= atoi(tsxelem->Attribute("width",NULL));
	  tilesheetheight=atoi(tsxelem->Attribute("height",NULL));
	 // cout<<tilesheetheight<<endl;
	  temp=tsxelem;

	}
	imagesource= image.c_str();
	//cout<<imagesource<<endl;
	elem=doc.FirstChildElement("map")->FirstChildElement("layer");
	layername=elem->Attribute("name");
	layertilewidth=atoi(elem->Attribute("width"));
	layertileheight=atoi(elem->Attribute("height"));
	
	
	XMLElement* e = doc.FirstChildElement("map")->FirstChildElement("layer");
	int layerNumber=0;
	bool continueOn=true;
	while(continueOn){
		//cout<<"idk"<<endl;
		
		

		layers.insert(layers.begin(),new Layer(xmlFile,layerNumber, imagesource, layertilewidth, layertileheight, tilesheetwidth, tilesheetheight, tilewidth, tileheight,xmlOrientation,renderer,margin,spacing));
		//layers.push_back(new Layer());
		layerNumber++;
		//cout<<"endloop"<<endl;
		
		e=e->NextSiblingElement();
		if(e==NULL)
		{
			continueOn=false;

		}
		

	}
	
	
}

void TMXReader::Initialize()
{
	readXML(tilemap);

	for(int i=0;i<layers.size();i++)
	{
		//cout<<"getting here"<<endl;
		layers[i]->Initialize();
	}

}

void TMXReader::Draw(SDL_Renderer* renderer)
{
	for(int i=0;i<layers.size();i++)
	{
		layers[i]->Draw(renderer);
	}

	

}

void TMXReader::Release()
{
	

	
}

void TMXReader::Update()
{


}
