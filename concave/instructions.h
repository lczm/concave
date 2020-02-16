#pragma once
#include "window.h"

class Instructions : public Window
{
public:
	Instructions();
	~Instructions();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};