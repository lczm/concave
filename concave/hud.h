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
	SpriteData healthSpriteData;

public:
	HUD();
	~HUD();
	SpriteData imageToSpriteData(const char* file, UINT imageWidth, UINT imageHeight);
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
	void print();
	SpriteData getSpriteData();
};