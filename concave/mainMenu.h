#pragma once
#include "window.h"
#include "image.h"
#include "button.h"
class MainMenu : public Window
{
private:
	Texture playbtnTexture;
	Texture playHoverTexture;
	Texture insbtnTexture;
	Texture optbtnTexture;
	Texture crbtnTexture;
	//GridMask playbtnGM;
	Button playbtn;
	Button playHoverbtn;
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
};