#pragma once
#include "window.h"
#include "image.h"
#include "button.h"
class MainMenu : public Window
{
private:
	Texture playbtnTexture;
	GridMask playbtnGM;
	Button playbtn;




public:
	MainMenu();
	~MainMenu();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};