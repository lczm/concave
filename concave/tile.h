#pragma once
#include "image.h"

class Tile
{
private:
	Image* imageA;
	Image* imageB;
	bool explored;
public:
	void initialize(Image* imageA, Image* imageB);
	void setImageA(Image* imageA);
	void setImageB(Image* imageB);
};