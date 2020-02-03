#pragma once
#include "window.h"

class MainMenu : public Window
{
public:
	MainMenu();
	~MainMenu();
	void initialize(vector<Window*>* windows);
	void releaseAll();
	void resetAll();
	void update();
	void render();
};