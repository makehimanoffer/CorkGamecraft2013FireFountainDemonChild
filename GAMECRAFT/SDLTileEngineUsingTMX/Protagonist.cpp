#include "Protagonist.h"
#include <SDL.h>
#include "SceneManager.h"

SceneManager* sm=SceneManager::getInstance();
Protagonist::Protagonist()
{


}

Protagonist::Protagonist(int x,int y,const char* imagesource,SDL_Renderer* renderer, int numberOfCells,int imagewidth,int imageheight)
{
	pressed=false;
	this->x=x;
	this->y=y;
	this->imagewidth=imagewidth;
	this->imageheight=imageheight;
	this->tilewidth=imagewidth/numberOfCells;
	this->tileheight=imageheight;
	drawingRect.x=0;
	drawingRect.y=0;
	drawingRect.w=imagewidth/numberOfCells;
	drawingRect.h=imageheight;
	this->boundingBox.x=x;
	this->boundingBox.y=y;
	this->boundingBox.w=imagewidth/numberOfCells;
	this->boundingBox.h=tileheight;
	this->texture=LoadImage(imagesource,renderer);
	gravity=2;
	colliding=false;
	

}


Protagonist::~Protagonist()
{




}



void Protagonist::Draw(SDL_Renderer* renderer)
{
	
	for(int i=0;i<b.size() && !b.empty();i++){
		b[i]->Draw(renderer);
	}
	SDL_RenderCopy(renderer,this->texture,&drawingRect,&boundingBox);
	

}

void Protagonist::Initialize()
{



}

void Protagonist::Update(SDL_Renderer* renderer,SDL_Rect enemyRect)
{
	for(int i=0;i<b.size() && !b.empty();i++){
		b[i]->Update();
	}
	const Uint8* keystate = SDL_GetKeyboardState(NULL);//returns all keys down. Passing in NULL does it for all keys.
	if(sm->current==SceneManager::DESERT ){

	boundingBox.y+=gravity;
	}
	for(int i=0;i<Tilemap::tiles.size();i++)
	{
		/*
		if(!Tilemap::tiles[i]->gid>0){
		topPlayer=boundingBox.y;
		bottomPlayer=boundingBox.y+32;
		leftPlayer=boundingBox.x;
		rightPlayer=boundingBox.x+32;
		leftTile=Tilemap::tiles[i]->levelx;
		rightTile= Tilemap::tiles[i]->levelx + 32;
		topTile= Tilemap::tiles[i]->levely;
		bottomTile= Tilemap::tiles[i]->levely + 32;
		if(rightPlayer==leftTile&& bottomPlayer>=topTile&& topPlayer<=bottomTile)
		{
			boundingBox.x-=1;
		}
		if(leftPlayer==rightTile&& bottomPlayer>=topTile&& topPlayer<=bottomTile)
		{
			boundingBox.x+=1;
		}
		if(bottomPlayer>=topTile && rightPlayer>=leftTile && leftPlayer<=rightTile)
		{
			cout<<"colliding"<<endl;
			boundingBox.y-=10;
		}
		if(topPlayer==bottomTile && rightPlayer>=leftTile && leftPlayer<=rightTile)
		{
			boundingBox.y+=gravity;
		}
		}
		*/
		
		if(SDL_HasIntersection(&boundingBox,&Tilemap::tiles[i]->whereToDraw)&& Tilemap::tiles[i]->gid>=0)
		{
			cout<<"colliding"<<endl;
			boundingBox.y-=gravity;
			
		}
		/*
		if(checkCollision(boundingBox,Tilemap::tiles[i]->whereToDraw))
		{
			boundingBox.y-=gravity;
			


		}
		if(checkCollisionRight(boundingBox,Tilemap::tiles[i]->whereToDraw))
		{
			


		}
		*/


	}
	if(boundingBox.x>800){
		boundingBox.x=0;
	}
	if(boundingBox.x<0){
		boundingBox.x=800;
	}
	if(keystate[SDL_SCANCODE_W])
	{
		if(boundingBox.y>0){
		boundingBox.y-=10;
		}
	}
	if(keystate[SDL_SCANCODE_S])
	{
		boundingBox.y++;
	}
	if(keystate[SDL_SCANCODE_SPACE] && pressed==false)
	{
		b.push_back(new Bee(boundingBox.x,boundingBox.y,"bee.png",renderer,0));
		pressed=true;
			
		
	}
	if(keystate[SDL_SCANCODE_SPACE] && pressed==true)
	{
		
		pressed==false;
	}
	for(int i=0;i<b.size();i++){
		if(SDL_HasIntersection(&b[i]->boundingBox, &enemyRect)){
			sm->current= SceneManager::MENU;
			sm->nextSceneItem(renderer);
			pressed=false;
		}
	}

	
	if(keystate[SDL_SCANCODE_A])
	{
		boundingBox.x--;
	}
	if(keystate[SDL_SCANCODE_D])
	{
		boundingBox.x++;
	}
	Animate();

}

SDL_Texture* Protagonist::LoadImage(const char* image,SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(image);
	SDL_Texture* t1 = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	return t1;

}

bool Protagonist::checkCollisionLeft(SDL_Rect A, SDL_Rect B)
{
	int rightOfTile= B.x+B.w;
	int leftOfPlayer= A.x;
	return false;

}

bool Protagonist::checkCollisionRight(SDL_Rect A, SDL_Rect B)
{
	int rightOfTile= B.x;
	int leftOfPlayer= A.x + A.w;
	if(rightOfTile==leftOfPlayer)
	{
		return true;
	}

}

bool Protagonist::checkCollision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;
        
    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

	 //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }
    
    if( topA >= bottomB )
    {
        return false;
    }
    
    if( rightA <= leftB )
    {
        return false;
    }
    
    if( leftA >= rightB )
    {
        return false;
    }
    
    //If none of the sides from A are outside B
    return true;
}

void Protagonist::Animate()
{
	if((time*SDL_GetTicks())%57==0){
	drawingRect.x+=tilewidth;
	if(drawingRect.x>=imagewidth-tilewidth)
	{
		drawingRect.x=0;
		
	}
	}
	time++;


}

