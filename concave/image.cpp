#include "image.h"

Image::Image()
{}

Image::~Image()
{}

void Image::initialize(Texture texture, int originX, int originY, int perWidth, int perHeight, int gapWidth, int gapHeight)
{
	Image::texture = texture;
	Image::originX = originX;
	Image::originY = originY;
	Image::perWidth = perWidth;
	Image::perHeight = perHeight;
	Image::gapWidth = gapWidth;
	Image::gapHeight = gapHeight;
}

RECT Image::getRect(CoordI coord)
{
	RECT rect;
	rect.left	= coord.x * (perWidth + gapWidth);
	rect.top	= coord.y * (perHeight + gapHeight);
	rect.right	= rect.left + perWidth;
	rect.bottom = rect.top + perHeight;
	return rect;
}

SpriteData Image::getSpriteData(CoordI coord, float x, float y, float scale, float angle = 0, bool flipHorizontal = false, bool flipVertical = false)
{
	return texture.getSpriteData(
		x, y, scale, getRect(coord), angle,
		flipHorizontal, flipVertical
	);
}