#pragma once
#include "window.h"
#include "image.h"
#include "spriteText.h"

class HUD : public Window
{
private:
	Graphics* graphics;
	Input* input;
	SpriteText spriteText;
	SpriteData manaSpriteData;
	SpriteData manaOrbSpriteData;
	SpriteData healthSpriteData;
	SpriteData healthOrbSpriteData;
	SpriteData inventorySpriteData;

public:
	HUD();
	~HUD();
	SpriteData imageToSpriteData(const char* file, UINT imageWidth, UINT imageHeight);
	SpriteData imageToSpriteData(const char* file, UINT imageWidth, UINT imageHeight, 
								GridMask imageGridMask, CoordI imageCoord);
	SpriteData getInventorySpriteData();
	void drawInventory(UINT x, UINT y);
	void drawHUD();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
	void print();
	SpriteData getSpriteData();
};