#pragma once
#include "image.h"
#include "input.h"
#include "component.h"
#include <iostream>
#include <vector>
using namespace std;

class RenderLevel
{
private:
	Graphics* graphics;
	Input* input;

	Texture tileTexture;
	GridMask tileGridMask;
	Image tileImage;


public:
	RenderLevel();
	~RenderLevel();

	void initialize(Graphics* graphics, Input* input);
	void renderMap(int map[mapWidth][mapHeight],int x, int y, SpriteData& sd);

};