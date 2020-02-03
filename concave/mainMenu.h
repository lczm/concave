#pragma once
#include "window.h"

class MainMenu : public Window
{
public:
	MainMenu();
	~MainMenu();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};