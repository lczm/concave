#pragma once
#include "graphics.h"

struct ImageData
{
	int         width;              // Width of sprite in pixels
	int         height;             // Height of sprite in pixels
	RECT        rect;               // used to select an image from a larger texture
	LP_TEXTURE  texture;            // pointer to texture
};

class Texture
{
private:
	const char* file;
	int width, height;
	LP_TEXTURE texture;
public:
	Texture();
	~Texture();
	bool initialize(Graphics* graphics, const char* file);
	void onLostDevice();
	void onResetDevice(Graphics* graphics);

	SpriteData getSpriteData(float x, float y, float scale, RECT rect, float angle = 0, bool flipHorizontal = false, bool flipVertical = false);
	ImageData getImageData(RECT rect);
};