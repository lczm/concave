#pragma once
#include "window.h"
#include "image.h"
#include "spriteText.h"

class HUD
{
private:
	Graphics* graphics;
	Input* input;
	Texture hudTexture;
	GridMask playerInfoGM;
	Image playerInfoImage;
	SpriteText* spriteText;
	CoordI test = { 0, 0 };

public:
	HUD();
	~HUD();
	void initialize(Graphics* graphics, Input* input);
	void releaseAll();
	void resetAll();
	void update();
	void render();
	void print();
	SpriteData getSpriteData();
};