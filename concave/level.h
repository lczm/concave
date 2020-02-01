#pragma once
#include "window.h"
#include "image.h"

class Level : public Window
{
private:
	Image tileImage;
public:
	Level();
	~Level();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();

	/*
	VECTOR2 ToScreen(int x, int y);
	VECTOR2 worldSize = { 5,5 };
	VECTOR2 tileSize = { 160, 80 };
	VECTOR2 origin = { 2,1 };
	*/
};