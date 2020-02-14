#pragma once
#include "input.h"
#include "component.h"
using namespace STATE;

struct State;
class Players
{
private:
	int capacity, size;
	vector<CoordF> positionArray;
	vector<CoordF> destPositionArray;
	vector<Lines> hLinesArray;
	vector<Lines> vLinesArray;

	vector<State*> fsmArray;
	vector<AnimImage*> imageArray;
	vector<int> stateArray;
	vector<int> frameNoArray;
	vector<int> directionArray;
	vector<float> timerArray;
	vector<float> delayArray;

	vector<int> healthArray;
	vector<int> manaArray;
public:
	Players(); ~Players();
	void initialize(int capacity);
	void push(CoordF position, Lines hLines, Lines vLines,
		State* fsm, AnimImage* image, int state, int health, int mana);
 	void pop(int index);
public:
	int getSize() { return size; }
 	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<CoordF>& getDestPositionArray() { return destPositionArray; }
 	vector<Lines>& getHLinesArray() { return hLinesArray; }
 	vector<Lines>& getVLinesArray() { return vLinesArray; }

	vector<State*>& getFsmArray() { return fsmArray; }
 	vector<AnimImage*>& getImageArray() { return imageArray; }
	vector<int>& getStateArray() { return stateArray; }
	vector<int>& getFrameNoArray() { return frameNoArray; }
	vector<int>& getDirectionArray() { return directionArray; }
	vector<float>& getTimerArray() { return timerArray; }
	vector<float>& getDelayArray() { return delayArray; }

	vector<int>& getHealthArray() { return healthArray; }
	vector<int>& getManaArray() { return manaArray; }
};

#include "state.h"
