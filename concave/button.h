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
	float x;
	float y;
	bool active;

public:
	Button();
	~Button();
	void initialize(Graphics* graphics, Input* input, Texture* texture);
	SpriteData getSpriteData();
	void setActive(bool a);
	void draw();
	bool isHovered();
	bool isClicked();
	int getWidth();
	int getHeight();
	void setPos(float posX, float posY);
	
};

