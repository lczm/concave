#pragma once
#include "window.h"
#include "image.h"

class HUD
{
private:
	Graphics* graphics;
	Input* input;
	Texture hudTexture;
	GridMask playerInfoGM;
	Image playerInfoImage;
	CoordI test = { 0, 0 };

public:
	HUD();
	~HUD();
	void initialize(Graphics* graphics, Input* input);
	void releaseAll();
	void resetAll();
	void update();
	void render();
	SpriteData getSpriteData();
};