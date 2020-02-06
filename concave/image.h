#pragma once
#include "constants.h"
#include "graphics.h"
#include <vector>
using namespace std;

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

	void getSpriteData(SpriteData& sd);
};

class GridMask
{
private:
	int originX, originY;
	int perWidth, perHeight;
	int gapWidth, gapHeight;
	int pivotX, pivotY;
public:
	GridMask();
	~GridMask();
	void initialize(int originX, int originY, int perWidth, int perHeight, int gapWidth, int gapHeight, int pivotX, int pivotY);
	void getSpriteData(SpriteData& sd, CoordI coord);
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
	void getSpriteData(SpriteData& sd, CoordI coord);
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
	void getSpriteData(SpriteData& sd, int state, int direction, int frameNo);
};

// These classes shouldn't be used.
// Please tell me if you want to use these classes.
//class Sprite
//{
//private:
//	Image* image;
//	CoordI coord;
//public:
//	Sprite();
//	~Sprite();
//	void initialize(Image* image, CoordI coord);
//	ImageData getImageData();
//};
//
//class AnimSprite
//{
//private:
//	AnimImage* animImage;
//	int state, direction, frameNo;
//public:
//	AnimSprite();
//	~AnimSprite();
//	void initialize(int state, int direction, int frameNo);
//	void changeState(int state);
//	void changeDirection(int direction);
//};