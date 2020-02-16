#pragma once
#include "constants.h"
#include "image.h"
#include <vector>
using namespace std;

class AnimObjects
{
private:
	int capacity, size;
	// Position
	vector<CoordF> positionArray;
	// Animation
	vector<AnimImage*> animImageArray;
	vector<int> stateArray;
	vector<int> directionArray;
	vector<int> frameNoArray;
	vector<float> timerArray;
	vector<float> delayArray; // Temporary
	// Collision
	LineISet hLineISet;
	LineISet vLineISet;
	vector<LineISetIters> hLineISetItersArray;
	vector<LineISetIters> vLineISetItersArray;
public:
	AnimObjects(); ~AnimObjects();
	void initialize(int capacity);
	void push(CoordF position, AnimImage* animImage, int state, int direction, int delay, Lines hLines, Lines vLines);
	void pop(int index);
public:
	int getSize() { return size; }
	// Position
	vector<CoordF>& getPositionArray() { return positionArray; }
	// Animation
	vector<AnimImage*>& getAnimImageArray() { return animImageArray; }
	vector<int>& getStateArray() { return stateArray; }
	vector<int>& getDirectionArray() { return directionArray; }
	vector<int>& getFrameNoArray() { return frameNoArray; }
	vector<float>& getTimerArray() { return timerArray; }
	vector<float>& getDelayArray() { return delayArray; }
	// Collision
	LineISet& getHLineISet() { return hLineISet; }
	LineISet& getVLineISet() { return vLineISet; }
	vector<LineISetIters>& getHLineISetItersArray() { return hLineISetItersArray; }
	vector<LineISetIters>& getVLineISetItersArray() { return vLineISetItersArray; }
};