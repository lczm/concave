#pragma once
#include <string>
#include "constants.h"
#include "image.h"

class SpriteText : public Image
{
private:
	Image font;
	Texture textureData;
	char* file;
	Graphics* graphics;
	UINT width, height;
	UINT fontHeight;
	UINT tabSize;
};
