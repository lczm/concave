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
	GridMask skillsGridMask;
	GridMask itemGridMask;
	CoordI fireballCoord;
	CoordI teleportCoord;
	CoordI healthPotCoord;
	CoordI manaPotCoord;
	CoordI emptyHealthPotCoord;
	CoordI emptyManaPotCoord;
	SpriteText spriteText;
	SpriteData manaSpriteData;
	SpriteData manaOrbSpriteData;
	SpriteData manaOrbRegenSpriteData;
	SpriteData healthSpriteData;
	SpriteData healthOrbSpriteData;
	SpriteData healthOrbRegenSpriteData;
	SpriteData inventorySpriteData;
	SpriteData fireballSpriteData;
	SpriteData teleportSpriteData;
	SpriteData healthPotSpriteData;
	SpriteData manaPotSpriteData;
	SpriteData emptyHealthPotSpriteData;
	SpriteData emptyManaPotSpriteData;
	COLOR_ARGB itemTranscolor = D3DCOLOR_ARGB(255, 73, 101, 101);

public:
	HUD();
	~HUD();
	SpriteData imageToSpriteData(const char* file);
	SpriteData imageToSpriteData(const char* file, GridMask imageGridMask, CoordI imageCoord);
	SpriteData imageToSpriteData(const char* file, COLOR_ARGB color, GridMask imageGridMask, CoordI imageCoord);
	void drawHUD();
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};