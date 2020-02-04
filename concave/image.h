#pragma once
#include "constants.h"
#include "graphics.h"
#include <vector>
using namespace std;

struct ImageData
{
	int         width;              // Width of sprite in pixels
	int         height;             // Height of sprite in pixels
	RECT        rect;               // used to select an image from a larger texture
	LP_TEXTURE  texture;            // pointer to texture
};

class Texture
{
private:
	const char* file;
	int width, height;
	LP_TEXTURE texture;
public:
	Texture();
	~Texture();
	bool initialize(Graphics* graphics, const char* file);
	void onLostDevice();
	void onResetDevice(Graphics* graphics);

	ImageData getImageData(RECT rect);
};

class GridMask
{
private:
	int originX, originY;
	int perWidth, perHeight;
	int gapWidth, gapHeight;
public:
	GridMask();
	~GridMask();
	void initialize(int originX, int originY, int perWidth, int perHeight, int gapWidth, int gapHeight);
	RECT getRect(CoordI coord);
};

class Image
{
private:
	Texture* texture;
	GridMask gridMask;
public:
	Image();
	~Image();
	void initialize(Texture* texture, GridMask gridMask);
	ImageData getImageData(CoordI coord);
};

class AnimImage
{
private:
	Texture* texture;
	vector<GridMask> gridMasks;
	vector<int> endFrames;
public:
	AnimImage();
	~AnimImage();
	void initialize(Texture* texture, vector<GridMask> gridMask, vector<int> endFrames);
	ImageData getImageData(int state, int direction, int frameNo);
};

class Sprite
{
private:
	Image* image;
	CoordI coord;
public:
	Sprite();
	~Sprite();
	void initialize(Image* image, CoordI coord);
	ImageData getImageData();
};

class AnimSprite
{
private:
	AnimImage* animImage;
	int state, direction, frameNo;
public:
	AnimSprite();
	~AnimSprite();
	void initialize(int state, int direction, int frameNo);
	void changeState(int state);
	void changeDirection(int direction);
};