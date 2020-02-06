#include "image.h"

Texture::Texture()
{}

Texture::~Texture()
{}

bool Texture::initialize(Graphics* graphics, const char* file)
{
	Texture::file = file;
	try {
		HRESULT hr;
		UINT width, height;
		LP_TEXTURE texture;
		hr = graphics->loadTexture(file, TRANSCOLOR, width, height, texture);
		if (FAILED(hr)) { SAFE_RELEASE(texture); return false; }
		Texture::texture = texture;
		Texture::width = width;
		Texture::height = height;
	}
	catch (...) {
		return false;
	}
	return true;
}

void Texture::onLostDevice()
{
	SAFE_RELEASE(Texture::texture);
}

void Texture::onResetDevice(Graphics* graphics)
{
	UINT width, height;
	LP_TEXTURE texture;
	graphics->loadTexture(file, TRANSCOLOR, width, height, texture);
	Texture::texture = texture;
	Texture::width = width;
	Texture::height = height;
}

void Texture::getSpriteData(SpriteData& sd)
{
	sd.width = width;
	sd.height = height;
	sd.texture = texture;
}

GridMask::GridMask()
{}

GridMask::~GridMask()
{}

void GridMask::initialize(int originX, int originY, int perWidth, int perHeight, int gapWidth, int gapHeight, int pivotX, int pivotY)
{
	GridMask::originX = originX;
	GridMask::originY = originY;
	GridMask::perWidth = perWidth;
	GridMask::perHeight = perHeight;
	GridMask::gapWidth = gapWidth;
	GridMask::gapHeight = gapHeight;
	GridMask::pivotX = pivotX;
	GridMask::pivotY = pivotY;
}

void GridMask::getSpriteData(SpriteData& sd, CoordI coord)
{
	sd.rect.left	= originX + coord.x * (perWidth + gapWidth);
	sd.rect.top		= originY + coord.y * (perHeight + gapHeight);
	sd.rect.right	= sd.rect.left + perWidth;
	sd.rect.bottom	= sd.rect.top + perHeight;
	sd.pivotX		= pivotX;
	sd.pivotY		= pivotY;
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

void Image::getSpriteData(SpriteData& sd, CoordI coord)
{
	texture->getSpriteData(sd);
	gridMask.getSpriteData(sd, coord);
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

void AnimImage::getSpriteData(SpriteData& sd, int state, int direction, int frameNo)
{
	texture->getSpriteData(sd);
	gridMasks[state].getSpriteData(sd, CoordI{ frameNo, direction });
}

//Sprite::Sprite()
//{}
//
//Sprite::~Sprite()
//{}
//
//void Sprite::initialize(Image* image, CoordI coord)
//{
//	Sprite::image = image;
//	Sprite::coord = coord;
//}
//
//ImageData Sprite::getImageData()
//{
//	return image->getImageData(coord);
//}
//
//AnimSprite::AnimSprite()
//{}
//
//AnimSprite::~AnimSprite()
//{}
//
//void AnimSprite::initialize(int state, int direction, int frameNo)
//{
//	AnimSprite::state = state;
//	AnimSprite::direction = direction;
//	AnimSprite::frameNo = frameNo;
//}
//
//void AnimSprite::changeState(int state)
//{
//	AnimSprite::frameNo = 0;
//	AnimSprite::state = state;
//}
//
//void AnimSprite::changeDirection(int direction)
//{
//	AnimSprite::direction = direction;
//}