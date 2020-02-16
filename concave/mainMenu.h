#pragma once
#include "window.h"
#include "image.h"
#include "button.h"
class MainMenu : public Window
{
private:

	Texture menuBgTexture;
	SpriteData menuBg;


	Texture playbtnTexture;
	Texture insbtnTexture;
	Texture optbtnTexture;
	Texture crbtnTexture;
	


	Texture playHoverTexture;
	Texture insHoverTexture;
	Texture optHoverTexture;
	Texture crHoverTexture;
	Button playHover;
	Button insHover;
	Button optHover;
	Button crHover;


	//GridMask playbtnGM;
	Button playbtn;
	Button insbtn;
	Button optbtn;
	Button crbtn;
	




public:
	MainMenu();
	~MainMenu();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();

	void initButtons();
	/*void CheckState(Button a, Button a_hover);*/
};