#pragma once
#include "constants.h"
#include "graphics.h"

class Image
{
private:
	const char* file;
	int rows, cols;
	int width, height;
	LP_TEXTURE texture;
	RECT getRect(int frameNo);
public:
	Image();
	~Image();
	bool initialize(Graphics* graphics, const char* file, int rows, int cols);
	void onLostDevice(Graphics* graphics);
	void onResetDevice(Graphics* graphics);
	SpriteData getSpriteData(int frameNo, float x, float y, float scale, float angle = 0, bool flipHorizontal = false, bool flipVertical = false);
};
