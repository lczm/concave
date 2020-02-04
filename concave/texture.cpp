#include "texture.h"

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