//Currently doing method to prevent jump jetpacking
//movement is handled in this class, screen and Renderer are alsop passed in,
//as well as game objects such as Player sprite being instantiated

#include "GameClass.h"

const int FPS = 400;
const int DELAY_TIME = 1000.0f / FPS;
Uint32 FrameStart, FrameTimer;

GameClass::GameClass(int ScreenWidth1, int ScreenHeight1)//the variables that specify the screen size are passed here, the values are specified in Main.cpp
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);//audio rate,audio format,audio_channels,audio_buffers
	ScreenWidth = ScreenWidth1;
	ScreenHeight = ScreenHeight1;

	Quit = false;
	Configure1 = new Configure(&Quit, ScreenWidth, ScreenHeight);//instantiation of the class , for the screen dimensions, values entered in game class

	//below the sprites are created as instances of the class SpriteClass.cpp
	Menu = new SpriteClass(Configure1->GetRenderer(),"assets/menu.png", 0, 0, ScreenWidth, ScreenHeight);
	Control = new SpriteClass(Configure1->GetRenderer(),"assets/control.png", 0, 0, ScreenWidth, ScreenHeight);
	Background = new SpriteClass(Configure1->GetRenderer(),"assets/background.png", 0, 0, ScreenWidth, ScreenHeight);
	Player = new SpriteClass(Configure1->GetRenderer(), "assets/threeplayer.png", 1, -100, 50, 50);//(x position, y postition, width, height) 
	Obstacle[0] = new SpriteClass(Configure1->GetRenderer(), "assets/Obstacle.png",-53, 200, 200, 100);
	Obstacle[1] = new SpriteClass(Configure1->GetRenderer(), "assets/Obstacle.png",200, 200, 200, 100);
	Obstacle[2] = new SpriteClass(Configure1->GetRenderer(), "assets/Obstacle.png",400, 200, 200, 100);
	Obstacle[3] = new SpriteClass(Configure1->GetRenderer(), "assets/Obstacle.png",400, -20, 200, 100);
	Obstacle[4] = new SpriteClass(Configure1->GetRenderer(), "assets/Obstacle.png",100, -20, 200, 100);
	Obstacle[5] = new SpriteClass(Configure1->GetRenderer(), "assets/Obstacle.png",600,500, 200, 100);
	Obstacle[6] = new SpriteClass(Configure1->GetRenderer(), "assets/Obstacle.png",400,300, 200, 100);
	Obstacle[7] = new SpriteClass(Configure1->GetRenderer(), "assets/Obstacle.png",300,500, 200, 100);
	Obstacle[8] = new SpriteClass(Configure1->GetRenderer(), "assets/SuperWin.png",0,500, 200, 100);
	Obstacle[9] = new SpriteClass(Configure1->GetRenderer(), "assets/Obstacle.png",100,250, 100, 50);
	Obstacle[10] = new SpriteClass(Configure1->GetRenderer(), "assets/SuperLose.png",800,250,200, 100);

	Enemy[0] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",430, 170, 50, 50);
	Enemy[1] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",430, 460, 50, 50);
	Enemy[2] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",150, 230, 50, 50);
	
	Enemy[3] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",2000, 2000, 50, 50);
	Enemy[4] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",2000, 2000, 50, 50);
	Enemy[5] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",2000, 2000, 50, 50);
	Enemy[6] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",2000, 2000, 50, 50);
	Enemy[7] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",2000, 2000, 50, 50);
	Enemy[8] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",2000, 2000, 50, 50);
	Enemy[9] = new SpriteClass(Configure1->GetRenderer(), "assets/Enemy.png",2000, 2000, 50, 50);

	effect1 = Mix_LoadWAV("assets/beginning2.wav");
	
	//below bools are used for movement checks
	RightMove = false;
	LeftMove = false;
	JumpMove = false;
	FallMove = false;
	EnemyForward = false;
	EnemyBack = false;
	MenuCheck = true;
	ControlCheck = false;

	//these bools are used for collision checks
	RightCollide = false;
	LeftCollide = false;
	TopCollide = false;
	BottomCollide = false;
	Timer = 0;
	AniFrame = 1;
	
	Mix_PlayChannel(-1, effect1, -1);
	
	//code here is used to create a static anchor for the enemies to patrol around when they cannot see the Player
	EnemyInitialPos = Enemy[0]->GetX();
}

GameClass::~GameClass(void)//this is the deconstructor
{
	delete Configure1;
	delete Background;
	delete Player;
}



void GameClass::MainGameLoop(void)//my main game loop, this is called in Main.cpp
{

	while(!Quit && Configure1->GetMainEvent()->type != SDL_QUIT)
	{
		FrameStart = SDL_GetTicks();

		Configure1->Begin();

		//Update Current Frame
		AniFrame = int(((SDL_GetTicks()/100)%3));

		if(MenuCheck && !ControlCheck)
		{
			Menu->Draw();
		}

		if(ControlCheck && !MenuCheck)
		{
			Control->Draw();
		}

		if (!MenuCheck && !ControlCheck)
		{
		//objects are drawn to screen below by calling the draw method from SpriteClass.cpp
		Background->Draw();
		//Menu->Draw();
		Player->DrawAnimation(AniFrame);
		
		Enemy[0]->Draw();
		Enemy[1]->Draw();
		Enemy[2]->Draw();
		}

		//getting the Player and Enemy sides
		LeftPlayer = Player->GetX();
		RightPlayer = Player->GetX()+50;
		TopPlayer = Player->GetY();
		BottomPlayer = Player->GetY()+50;
		//controls
		switch(Configure1->GetMainEvent()->type)//switch to check if a key is pressed
		{

			case SDL_KEYDOWN://if the key is pressed
			switch(Configure1->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_a:
				LeftMove = true;
				std::cout << "A key was pressed" << std::endl;
				break;

			case SDLK_s:
				RightMove = true;
				std::cout << "S key was pressed" << std::endl;
				break;

			case SDLK_m:
				MenuCheck = false;
				ControlCheck = false;
				std::cout << "S key was pressed" << std::endl;
				break;

			case SDLK_c:
				ControlCheck = true;
				MenuCheck = false;
				std::cout << "S key was pressed" << std::endl;
				break;

			case SDLK_SPACE:
				if(JumpCheck && BottomCollide)
				{
				std::cout << "Space key was pressed" << std::endl;
				JumpMove = true;
				}
				break;

			default:
				break;
			}
			break;
			
			case SDL_KEYUP://if the key is up
				switch(Configure1->GetMainEvent()->key.keysym.sym)
				{
	
				case SDLK_a:
					LeftMove = false;
					break;

				case SDLK_s:
					RightMove = false;
					break;
					
				case SDLK_SPACE:
					JumpMove = false;
					JumpCheck = true;
					break;
				}

		default:
			break;
		}
		
		if(Player->GetY()<700 && !MenuCheck && !ControlCheck)
		{
			Player->PosY(Player->GetY()+1);
		}

		//movement speed handled in below block of code
		if(LeftMove && !LeftCollide)//a
		{
			Player->PosX(Player->GetX()-1);
		}
		if(RightMove && !RightCollide)//s
		{
			Player->PosX(Player->GetX()+1);
		}
		
		if(JumpMove && JumpCheck && !TopCollide && Timer < 100)//space
		{
			Player->PosY(Player->GetY()-2);
			Timer++;						
		}

		if(Timer>=100)
		{
			JumpCheck = false;
			JumpMove = false;
			Timer = 0;
		}
		
		if(Enemy[0]->GetX() <= EnemyInitialPos)
		{
			EnemyForward = true;
			EnemyBack = false;
		}

		if(Enemy[0]->GetX() >= EnemyInitialPos + 100)
		{
			EnemyForward = false;
			EnemyBack = true;
		}

		if(EnemyForward && !EnemyBack)
		{
			Enemy[0]->PosX(Enemy[0]->GetX()+1);
			Enemy[1]->PosY(Enemy[1]->GetY()+1);
		}

		if(EnemyBack && !EnemyForward)
		{
			Enemy[0]->PosX(Enemy[0]->GetX()-1);
			Enemy[1]->PosY(Enemy[1]->GetY()-1);
		}

		//collision checks, boundry checks
		for(int i = 0; i<11; i++)//This loops through the different Obstacles for collision checks
		{
			if(!MenuCheck && !ControlCheck)
			{
			Obstacle[i]->Draw();//If statement and a seperate counter for each level
			

			LeftObstacle = Obstacle[i]->GetX();
			RightObstacle = Obstacle[i]->GetX()+200;
			TopObstacle = Obstacle[i]->GetY();
			BottomObstacle = Obstacle[i]->GetY()+100;

			LeftEnemy = Enemy[i]->GetX();
			RightEnemy = Enemy[i]->GetX()+50;
			TopEnemy = Enemy[i]->GetY();
			BottomEnemy = Enemy[i]->GetY()+50;

		if(RightPlayer == LeftObstacle && BottomPlayer >= TopObstacle && TopPlayer <= BottomObstacle || RightPlayer == 1000)
		{
			std::cout << "Right Collide!" << std::endl;
			RightMove = false;
			Player->PosX(Player->GetX()-1);
		}

		if(LeftPlayer == RightObstacle && BottomPlayer >= TopObstacle && TopPlayer <= BottomObstacle || LeftPlayer <=1)
		{
			std::cout << "Left Collide!" << std::endl;
			LeftMove = false;
			Player->PosX(Player->GetX()+1);
		}

		if(BottomPlayer == TopObstacle	&& RightPlayer >= LeftObstacle && LeftPlayer <= RightObstacle)
		{
			std::cout << "Bottom Collide!" << std::endl;
			Player->PosY(Player->GetY()-1);
			JumpCheck = true;
			BottomCollide = true;
			
			//Below code increased the player's speed while touching the floor, for balancing it against jump speed
			if(LeftMove && !LeftCollide)//a
			{
			Player->PosX(Player->GetX()-1);
			}

			if(RightMove && !RightCollide)//s
			{
			Player->PosX(Player->GetX()+1);
			}
		}

		if(BottomPlayer == Obstacle[8]->GetY() && RightPlayer >= Obstacle[8]->GetX() && LeftPlayer <= Obstacle[8]->GetX()+200)
		{
			std::cout << "Win!" << std::endl;
			Player->PosX(Player->GetX()==1);
			Player->PosY(Player->GetY()==-100);
			MenuCheck = true;
		}

		if(BottomPlayer == Obstacle[10]->GetY() && RightPlayer >= Obstacle[10]->GetX() && LeftPlayer <= Obstacle[10]->GetX()+200)
		{
			std::cout << "Win!" << std::endl;
			Player->PosX(Player->GetX()==1);
			Player->PosY(Player->GetY()==-100);
			MenuCheck = true;
		}

		if(TopPlayer == BottomObstacle-2 && RightPlayer >= LeftObstacle && LeftPlayer <= RightObstacle)
		{
			std::cout << "Top Collide!" << std::endl;
			Player->PosY(Player->GetY()+2);
		}

		if(TopPlayer == BottomObstacle && RightPlayer >= LeftObstacle && LeftPlayer <= RightObstacle)//Hang line
		{
			std::cout << "Hang in there, baby!" << std::endl;
			Player->PosY(Player->GetY()-1);
		}

		//Enemy collisions are below, they work the same as obstaclle collisions but the player respawns if he triggers one
		if(RightPlayer == LeftEnemy && BottomPlayer >= TopEnemy && TopPlayer <= BottomEnemy)
		{
			std::cout << "Right Collide!" << std::endl;
			Player->PosX(Player->GetX()==1);
			Player->PosY(Player->GetY()==-100);
			MenuCheck = true;
		}

		if(LeftPlayer == RightEnemy && BottomPlayer >= TopEnemy && TopPlayer <= BottomEnemy)
		{
			std::cout << "Left Collide!" << std::endl;
			std::cout << "Bottom Collide!" << std::endl;
			Player->PosX(Player->GetX()==1);
			Player->PosY(Player->GetY()==-100);
			MenuCheck = true;
		}

		if(BottomPlayer == TopEnemy	&& RightPlayer >= LeftEnemy && LeftPlayer <= RightEnemy)
		{
			std::cout << "Bottom Collide!" << std::endl;
			Player->PosX(Player->GetX()==1);
			Player->PosY(Player->GetY()==-100);
			MenuCheck = true;
		}

		if(TopPlayer <= 0)//top boundry
		{
			Player->PosY(Player->GetY()+1);
		}

		if(TopPlayer == 700)
		{
			Player->PosX(Player->GetX()==1);
			Player->PosY(Player->GetY()==-100);
			MenuCheck = true;
		}
			
	}
}
	Configure1->End();

		FrameTimer = SDL_GetTicks()- FrameStart;
		if(FrameTimer < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - FrameTimer));
		}
	}
}