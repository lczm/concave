#pragma once
#include "window.h"

class Level : public Window
{
private:
	
public:
	Level();
	~Level();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};