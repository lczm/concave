#pragma once
#include "graphics.h"
#include "input.h"
#include "image.h"


class Button
{
private:
	Graphics* graphics;
	Input* input;
	Texture *texture;
	//GridMask gridMask;
	float x;
	float y;


public:
	Button();
	~Button();
	void initialize(Graphics* graphics, Input* input, Texture* texture, float x, float y);
	SpriteData getSpriteData();
	void draw();
	bool isHovered();
	
};

