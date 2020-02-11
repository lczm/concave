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

void Texture::getSpriteData(SpriteData& spriteData)
{
	spriteData.width = width;
	spriteData.height = height;
	spriteData.texture = texture;
	spriteData.rect.left = 0;
	spriteData.rect.top = 0;
	spriteData.rect.right = width;
	spriteData.rect.bottom = height;
	spriteData.pivotX = 0;
	spriteData.pivotY = 0;
	
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

void GridMask::getSpriteData(SpriteData& spriteData, CoordI coord)
{
	spriteData.rect.left	= originX + coord.x * (perWidth + gapWidth);
	spriteData.rect.top		= originY + coord.y * (perHeight + gapHeight);
	spriteData.rect.right	= spriteData.rect.left + perWidth;
	spriteData.rect.bottom	= spriteData.rect.top + perHeight;
	spriteData.pivotX		= pivotX;
	spriteData.pivotY		= pivotY;
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

void Image::getSpriteData(SpriteData& spriteData, CoordI coord)
{
	texture->getSpriteData(spriteData);
	gridMask.getSpriteData(spriteData, coord);
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

void AnimImage::getSpriteData(SpriteData& spriteData, int state, int direction, int frameNo)
{
	texture->getSpriteData(spriteData);
	gridMasks[state].getSpriteData(spriteData, CoordI{ frameNo, direction });
}

int AnimImage::getEndFrame(int state)
{
	return endFrames[state];
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
//SpriteData Sprite::getSpriteData()
//{
//	SpriteData sd;
//	image->getSpriteData(sd, coord);
//	return sd;
//}
//
//AnimSprite::AnimSprite()
//{}
//
//AnimSprite::~AnimSprite()
//{}
//
//void AnimSprite::initialize(AnimImage* animImage, int state, int direction, int frameNo, float delay, bool loop)
//{
//	AnimSprite::animImage = animImage;
//	AnimSprite::state = state;
//	AnimSprite::direction = direction;
//	AnimSprite::frameNo = frameNo;
//	AnimSprite::delay = delay;
//	AnimSprite::timer = 0;
//	AnimSprite::loop = loop;
//}
//
//SpriteData AnimSprite::getSpriteData()
//{
//	SpriteData sd;
//	animImage->getSpriteData(sd, state, direction, frameNo);
//	return sd;
//}
//
//void AnimSprite::setState(int state)
//{
//	if (AnimSprite::state == state) return;
//	AnimSprite::frameNo = 0;
//	AnimSprite::state = state;
//}
//
//void AnimSprite::setDirection(int direction)
//{
//	AnimSprite::direction = direction;
//}
//
//void AnimSprite::updateFrame(float deltaTime)
//{
//	timer += deltaTime;
//	if (timer >= delay) {
//		timer -= delay;
//		frameNo++;
//		if (frameNo >= animImage->getEndFrame(state)) {
//			frameNo = 0;
//			if (!loop) loopComplete = true;
//		}
//	}
//}