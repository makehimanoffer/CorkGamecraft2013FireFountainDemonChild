#ifndef _MainMenu_H_
#define _MainMenu_H_

#include "SceneItem.h"
#include "SceneManager.h"


class Menu: public SceneItem
{
public:
	Menu();
	Menu(const Menu&);
	virtual ~Menu();
	void Initialize();
	void Update();
	void Draw(SDL_Renderer*);
	void Release();
	


private:

	
};

#endif