#pragma once
#include "window.h"
#include "image.h"
#include "spriteText.h"
#include "item.h"

class HUD : public Window
{
private:
	Graphics* graphics;
	Input* input;
	boolean inventoryDisplayed;
	SpriteText spriteText;
	SpriteData manaSpriteData;
	SpriteData manaOrbSpriteData;
	SpriteData manaOrbRegenSpriteData;
	SpriteData healthSpriteData;
	SpriteData healthOrbSpriteData;
	SpriteData healthOrbRegenSpriteData;
	SpriteData inventorySpriteData;

public:
	HUD();
	~HUD();
	SpriteData imageToSpriteData(const char* file);
	SpriteData imageToSpriteData(const char* file, UINT imageWidth, UINT imageHeight, 
								GridMask imageGridMask, CoordI imageCoord);
	SpriteData getInventorySpriteData();
	void drawHUD();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};