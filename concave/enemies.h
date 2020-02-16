#pragma once
#include "constants.h"
#include "image.h"
#include <vector>
using namespace std;

class Enemies
{
private:
	int capacity, size;
	// Position
	vector<CoordF> positionArray;
	vector<CoordF> destPositionArray;
	// Animation
	vector<AnimImage*> animImageArray;
	vector<int> stateArray;
	vector<int> directionArray;
	vector<int> frameNoArray;
	vector<float> timerArray;
	vector<float> delayArray; // Temporary
	vector<FSM> fsmArray;
	// Movement
	vector<float> rotationArray;
	vector<float> velocityArray;
	// Collision
	LineISet hLineISet;
	LineISet vLineISet;
	vector<LineISetIters> hLineISetItersArray;
	vector<LineISetIters> vLineISetItersArray;
	// Attributes
	vector<int> rangeArray;
public:
	Enemies(); ~Enemies();
	void initialize(int capacity);
	void push(CoordF position, AnimImage* animImage, int state, FSM fsm, float rotation, float velocity, Lines hLines, Lines vLines);
	void pop(int index);
public:
	int getSize() { return size; }
	// Position
	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<CoordF>& getDestPositionArray() { return destPositionArray; }
	// Animation
	vector<AnimImage*>& getAnimImageArray() { return animImageArray; }
	vector<int>& getStateArray() { return stateArray; }
	vector<int>& getDirectionArray() { return directionArray; }
	vector<int>& getFrameNoArray() { return frameNoArray; }
	vector<float>& getTimerArray() { return timerArray; }
	vector<float>& getDelayArray() { return delayArray; }
	vector<FSM>& getFSMArray() { return fsmArray; }
	// Movement
	vector<float>& getRotationArray() { return rotationArray; }
	vector<float>& getVelocityArray() { return velocityArray; }
	// Collision
	LineISet& getHLineISet() { return hLineISet; }
	LineISet& getVLineISet() { return vLineISet; }
	vector<LineISetIters>& getHLineISetItersArray() { return hLineISetItersArray; }
	vector<LineISetIters>& getVLineISetItersArray() { return vLineISetItersArray; }
	// Attributes
	vector<int>& getRangeArray() { return rangeArray; }
};