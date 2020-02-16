#pragma once
#include "window.h"
#include "spriteText.h"

class ModifierSelect : public Window
{
private:
	Graphics* graphics;
	Input* input;
	GridMask modifierGridMask;
	CoordI wandCoord;
	CoordI shieldCoord;
	CoordI swordCoord;
	SpriteData wandSpriteData;
	SpriteData shieldSpriteData;
	SpriteData swordSpriteData;
	SpriteText spriteText;

public:
	ModifierSelect();
	~ModifierSelect();
	SpriteData imageToSpriteData(const char* file, GridMask imageGridMask, CoordI imageCoord);
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
	int checkWhichButton(int mouseX, int mouseY);
};


