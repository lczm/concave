#pragma once
#include "window.h"

class HUD : public Window
{
public:
	HUD();
	~HUD();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};