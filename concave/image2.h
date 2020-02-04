#pragma once
#include "constants.h"
#include "graphics.h"
#include "texture.h"
#include <vector>
using namespace std;

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
	SpriteData getSpriteData(CoordI coord, float x, float y, float scale, float angle = 0, bool flipHorizontal = false, bool flipVertical = false);
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
	SpriteData getSpriteData(int state, int direction, int frameNo);
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
	SpriteData getSpriteData(float x, float y, float scale, float angle = 0, bool flipHorizontal = false, bool flipVertical = false);
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
	void changeState();
	void changeDirection();
};

enum DIRECTION8 { SOUTH, SOUTH_WEST, WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST };
enum DIRECTION16 {};