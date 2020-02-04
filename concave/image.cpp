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

ImageData Texture::getImageData(RECT rect)
{
	return ImageData{
		width, height, rect, texture
	};
}

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

Sprite::Sprite()
{}

Sprite::~Sprite()
{}

void Sprite::initialize(Image* image, CoordI coord)
{
	Sprite::image = image;
	Sprite::coord = coord;
}

ImageData Sprite::getImageData()
{
	return image->getImageData(coord);
}

AnimSprite::AnimSprite()
{}

AnimSprite::~AnimSprite()
{}

void AnimSprite::initialize(int state, int direction, int frameNo)
{
	AnimSprite::state = state;
	AnimSprite::direction = direction;
	AnimSprite::frameNo = frameNo;
}

void AnimSprite::changeState(int state)
{
	AnimSprite::frameNo = 0;
	AnimSprite::state = state;
}

void AnimSprite::changeDirection(int direction)
{
	AnimSprite::direction = direction;
}