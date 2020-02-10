#pragma once
#include "window.h"
#include "image.h"
class Button
{
private:
	Graphics* graphics;
	Input* input;
	Texture *texture;
	GridMask gridMask;
	SpriteData spriteData;
	float x;
	float y;


public:
	Button();
	~Button();
	void initialize(Graphics* graphics, Input* input, Texture* texture);
	SpriteData getSpriteData();
	void draw();
	
};

