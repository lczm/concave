#pragma once
#include "window.h"

class Credits : public Window
{
public:
	Credits();
	~Credits();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};