#pragma once
#include "window.h"

class MainMenu : public Window
{
private:
	



public:
	MainMenu();
	~MainMenu();
	void initialize(Graphics* graphics, Input* input);
	void releaseAll();
	void resetAll();
	void update();
	void render();
};