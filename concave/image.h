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
	void getSpriteData(SpriteData& SpriteData);
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
	void getSpriteData(SpriteData& SpriteData, CoordI coord);
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
	SpriteData getSpriteData(CoordI coord);
	//void getSpriteData(SpriteData& SpriteData, CoordI coord);
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
	//void getSpriteData(SpriteData& SpriteData, int state, int direction, int frameNo);
	int getEndFrame(int state);
};

//-------------------------------------------------------
// NOTE: These classes shouldn't be used.
// NOTE: Please tell me if you want to use these classes.
//-------------------------------------------------------
//class Sprite
//{
//private:
//	Image* image;
//	CoordI coord;
//public:
//	Sprite();
//	~Sprite();
//	void initialize(Image* image, CoordI coord);
//	SpriteData getSpriteData();
//};
//
//class AnimSprite
//{
//private:
//	AnimImage* animImage;
//	int state, direction, frameNo;
//	float delay, timer;
//	bool loop, loopComplete;
//public:
//	AnimSprite();
//	~AnimSprite();
//	void initialize(AnimImage* animImage, int state, int direction, int frameNo, float delay, bool loop);
//	SpriteData getSpriteData();
//	void setState(int state);
//	void setDirection(int direction);
//	void updateFrame(float deltaTime);
//
//	int getState() { return state; }
//	bool getLoop() { return loop; }
//	bool getLoopComplete() { return loopComplete; }
//	void setLoop(bool loop) { AnimSprite::loop = loop; }
//	void setLoopComplete(bool loopComplete) { AnimSprite::loopComplete = loopComplete; }
//	void setTimer(float timer) { AnimSprite::timer = timer; }
//};