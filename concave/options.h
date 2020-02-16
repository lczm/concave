#pragma once
#include "window.h"

class Options : public Window
{
public:
	Options();
	~Options();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};