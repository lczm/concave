#pragma once
#include "window.h"
#include "image.h"
#include "button.h"
class MainMenu : public Window
{
private:

	Texture menuBg;
	Texture itemBg;

	Texture playbtnTexture;
	Texture insbtnTexture;
	Texture optbtnTexture;
	Texture crbtnTexture;
	Texture scrbarTexture;
	Texture scrollerTexture;


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
	Button scrbar;
	Button scroller;




public:
	MainMenu();
	~MainMenu();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();

	void initBg(Graphics* graphics);
};