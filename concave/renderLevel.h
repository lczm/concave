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

	Texture itemTexture;
	GridMask itemGridMask;
	Image itemImage;

	Texture manyItemsTexture;
	GridMask manyItemsGridMask;
	Image manyItemsImage;

public:
	RenderLevel();
	~RenderLevel();

	void initialize(Graphics* graphics, Input* input, int type);
	void renderMap(int map[mapWidth][mapHeight],int x, int y, SpriteData& sd, int type);

	Image getTileImage() {
		return tileImage;
	}

	void renderMiniMap(int map[mapWidth][mapHeight]);

};