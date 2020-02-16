// #pragma once
// #include "image.h"
// #include <vector>
// #include <set>
// using namespace std;
// 
// class Projectiles
// {
// private:
// 	int capacity, size;
// 	vector<CoordF> positionArray;
// 	vector<Sprite*> spriteArray;
// 	LineISet hLineISet;
// 	LineISet vLineISet;
// 	vector<LineISetIters> hLineISetItersArray;
// 	vector<LineISetIters> vLineISetItersArray;
// public:
// 	Projectiles(); ~Projectiles();
// 	void initialize(int capacity);
// 	void push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines);
// 	void pop(int index);
// public:
// 	int getSize() { return size; }
// 	vector<CoordF>& getPositionArray() { return positionArray; }
// 	vector<Sprite*>& getSpriteArray() { return spriteArray; }
// 	LineISet& getHLineISet() { return hLineISet; }
// 	LineISet& getVLineISet() { return vLineISet; }
// 	vector<LineISetIters>& getHLineISetItersArray() { return hLineISetItersArray; }
// 	vector<LineISetIters>& getVLineISetItersArray() { return vLineISetItersArray; }
// };

#pragma once
#include "constants.h"
#include "image.h"
#include <vector>
#include <set>
using namespace std;

class Projectiles
{
private:
	int capacity, size;
	vector<CoordF> positionArray;
	LineISet hLineISet;
	LineISet vLineISet;
	vector<LineISetIters> hLineISetItersArray;
	vector<LineISetIters> vLineISetItersArray;

	vector<AnimImage*> animImageArray;
	vector<int> frameNoArray;
	vector<float> timerArray;
	vector<float> delayArray;
	vector<float> rotationArray;
	vector<float> velocityArray;
	vector<CoordF> dydxArray;

public:
	Projectiles(); ~Projectiles();
	void initialize(int capacity);
	void push(CoordF position, AnimImage* animImage, Lines hLines, Lines vLines, float rotation);
	void pop(int index);
public:
	int getSize() { return size; }
	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<AnimImage*>& getAnimImageArray() { return animImageArray; }
	LineISet& getHLineISet() { return hLineISet; }
	LineISet& getVLineISet() { return vLineISet; }
	vector<LineISetIters>& getHLineISetItersArray() { return hLineISetItersArray; }
	vector<LineISetIters>& getVLineISetItersArray() { return vLineISetItersArray; }
	vector<int>& getFrameNoArray() { return frameNoArray; }
	vector<float>& getTimerArray() { return timerArray; }
	vector<float>& getDelayArray() { return delayArray; }
	vector<float>& getRotationArray() { return rotationArray; }
	vector<float>& getVelocityArray() { return velocityArray; }
	vector<CoordF>& getDydxArray() { return dydxArray; }
};