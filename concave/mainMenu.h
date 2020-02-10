#pragma once
#include "window.h"
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
	void initialize(Graphics* graphics, Input* input);
	void releaseAll();
	void resetAll();
	void update();
	void render();
};