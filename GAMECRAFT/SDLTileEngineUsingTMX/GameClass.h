//variables are defined here for use in the main.cpp
//Pointers from SpriteClass to the sprites to be drawn are also defined

#ifndef _GAMECLASS_
#define _GAMECLASS_

#pragma once
#include "Stdafx.h"
#include "Configure.h"
#include "SpriteClass.h"

class GameClass
{
public:
	GameClass(int ScreenWidth1, int ScreenHeight1);
	~GameClass(void);

public: 
	int ScreenWidth;
	int ScreenHeight;
	void MainGameLoop();

private:
	bool Quit;

	//bools used for movement
	bool RightMove;
	bool LeftMove;
	bool JumpMove;
	bool FallMove;
	bool EnemyBack;
	bool EnemyForward;

	//booleans used for collisions
	bool RightCollide;
	bool LeftCollide;
	bool TopCollide;
	bool BottomCollide;

	//Check bools
	bool JumpCheck;
	bool MenuCheck;
	bool ControlCheck;

	//Integers that hold the sides of player and obstacle
	int LeftPlayer, LeftObstacle, LeftEnemy;
	int RightPlayer, RightObstacle, RightEnemy;
	int TopPlayer, TopObstacle, TopEnemy;
	int BottomPlayer, BottomObstacle, BottomEnemy;
	int AniFrame;//Used to count frames
	int Timer;
	int EnemyInitialPos;//Used as an anchor for enemy patrol movement

	SpriteClass* Background;
	SpriteClass* Menu;
	SpriteClass* Control;
	SpriteClass* Player;
	SpriteClass* Obstacle[11];//number of Obstacles
	SpriteClass* Enemy[10];
	Mix_Chunk* effect1;

	Configure* Configure1;
	Configure* Configure2;
};

#endif