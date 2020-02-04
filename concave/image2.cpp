#include "image2.h"

GridMask::GridMask()
{}

GridMask::~GridMask()
{}

void GridMask::initialize(int originX, int originY, int perWidth, int perHeight, int gapWidth, int gapHeight)
{
	GridMask::originX = originX;
	GridMask::originY = originY;
	GridMask::perWidth = perWidth;
	GridMask::perHeight = perHeight;
	GridMask::gapWidth = gapWidth;
	GridMask::gapHeight = gapHeight;
}

RECT GridMask::getRect(CoordI coord)
{
	RECT rect;
	rect.left	= coord.x * (perWidth + gapWidth);
	rect.top	= coord.y * (perHeight + gapHeight);
	rect.right	= rect.left + perWidth;
	rect.bottom = rect.top + perHeight;
	return rect;
}

Image::Image()
{}

Image::~Image()
{}

void Image::initialize(Texture* texture, GridMask gridMask)
{
	Image::texture = texture;
	Image::gridMask = gridMask;
}

SpriteData Image::getSpriteData(CoordI coord, float x, float y, float scale, float angle, bool flipHorizontal, bool flipVertical)
{
	return texture->getSpriteData(
		x, y, scale, gridMask.getRect(coord),
		angle, flipHorizontal, flipVertical
	);
}

ImageData Image::getImageData(CoordI coord)
{
	return texture->getImageData(
		gridMask.getRect(coord)
	);
}

AnimImage::AnimImage()
{}

AnimImage::~AnimImage()
{}

void AnimImage::initialize(Texture* texture, vector<GridMask> gridMasks, vector<int> endFrames)
{
	AnimImage::texture = texture;
	AnimImage::gridMasks = gridMasks;
	AnimImage::endFrames = endFrames;
}

ImageData AnimImage::getImageData(int state, int direction, int frameNo)
{
	return texture->getImageData(
		gridMasks[state].getRect(CoordI{ frameNo, direction })
	);
}