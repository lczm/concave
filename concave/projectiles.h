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
	// Position
	vector<CoordF> positionArray;
	// Animation
	vector<AnimImage*> animImageArray;
	vector<int> frameNoArray;
	vector<float> timerArray;
	vector<float> delayArray;
	// Movement
	vector<float> rotationArray;
	vector<float> velocityArray;
	// Collision
	LineISet hLineISet;
	LineISet vLineISet;
	vector<LineISetIters> hLineISetItersArray;
	vector<LineISetIters> vLineISetItersArray;
public:
	Projectiles(); ~Projectiles();
	void initialize(int capacity);
	void push(CoordF position, AnimImage* animImage, Lines hLines, Lines vLines, float rotation);
	void pop(int index);
public:
	int getSize() { return size; }
	// Postition
	vector<CoordF>& getPositionArray() { return positionArray; }
	// Animation
	vector<AnimImage*>& getAnimImageArray() { return animImageArray; }
	vector<int>& getFrameNoArray() { return frameNoArray; }
	vector<float>& getTimerArray() { return timerArray; }
	vector<float>& getDelayArray() { return delayArray; }
	// Movement
	vector<float>& getRotationArray() { return rotationArray; }
	vector<float>& getVelocityArray() { return velocityArray; }
	// Collision
	LineISet& getHLineISet() { return hLineISet; }
	LineISet& getVLineISet() { return vLineISet; }
	vector<LineISetIters>& getHLineISetItersArray() { return hLineISetItersArray; }
	vector<LineISetIters>& getVLineISetItersArray() { return vLineISetItersArray; }
};