#pragma once
#include "texture.h"
using namespace std;

class Image
{
private:
	Texture texture;
	int originX, originY;
	int perWidth, perHeight;
	int gapWidth, gapHeight;
public:
	Image();
	~Image();
	void initialize(Texture texture, int originX, int originY, int perWidth, int perHeight, int gapWidth, int gapHeight);
	RECT getRect(CoordI coord);
	SpriteData getSpriteData(CoordI coord, float x, float y, float scale, float angle = 0, bool flipHorizontal = false, bool flipVertical = false);
};