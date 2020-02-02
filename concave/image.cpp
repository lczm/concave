#include "image2.h"

Image::Image()
{}

Image::~Image()
{}

bool Image::initialize(Graphics* graphics, const char* file, int rows, int cols)
{
	Image::file = file;
	try {
		HRESULT hr;
		UINT width, height;
		LP_TEXTURE texture;
		hr = graphics->loadTexture(file, TRANSCOLOR, width, height, texture);
		if (FAILED(hr)) { SAFE_RELEASE(texture); return false; }
		Image::texture = texture;
		Image::width = width;
		Image::height = height;
	}
	catch (...) {
		return false;
	}
}

void Image::onLostDevice(Graphics* graphics)
{
	SAFE_RELEASE(Image::texture);
}

void Image::onResetDevice(Graphics* graphics)
{
	UINT width, height;
	LP_TEXTURE texture;
	graphics->loadTexture(file, TRANSCOLOR, width, height, texture);
	Image::texture = texture;
	Image::width = width;
	Image::height = height;
}

SpriteData Image::getSpriteData(int frameNo, float x, float y, float scale, float angle, bool flipHorizontal = false, bool flipVertical = false)
{
	return SpriteData{ 
		width, height, 
		x, y, scale, angle, 
		getRect(frameNo), texture, 
		flipHorizontal, flipVertical
	};
}

RECT Image::getRect(int frameNo)
{
	RECT rect;
	rect.left	= (frameNo % cols) * width;
	rect.top	= (frameNo / cols) * height;
	rect.right	= rect.left + width;
	rect.bottom = rect.top + height;
	return rect;
}
