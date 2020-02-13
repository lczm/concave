#pragma once
#include "input.h"
#include "component.h"

class State;

class Players
{
private:
	int capacity, size;
	vector<CoordF> positionArray;
	vector<CoordF> destPositionArray;
	vector<Lines> hLinesArray;
	vector<Lines> vLinesArray;

	vector<State*> stateArray;
	vector<AnimImage*> imageArray;
	vector<RenderInfo> imageInfoArray;

	vector<Movement> movementArray;
	vector<int> healthArray;
	vector<int> manaArray;
public:
	Players(); ~Players();
	void initialize(int capacity);
	void push(CoordF position, AnimImage* image, RenderInfo imageInfo, 
		State* state, Lines hLines, Lines vLines);
 	void pop(int index);
public:
	void setPosition(int index, CoordF position);
	void setDestPosition(int index, CoordF destPosition);
	void setMovement(int index, Movement movement);
	void setState(int index, State* state);
public:
	int getSize() { return size; }
 	vector<CoordF>& getPositionArray() { return positionArray; }
	vector<CoordF>& getDestPositionArray() { return destPositionArray; }
 	vector<Lines>& getHLinesArray() { return hLinesArray; }
 	vector<Lines>& getVLinesArray() { return vLinesArray; }
	vector<State*>& getStateArray() { return stateArray; }
 	vector<AnimImage*>& getImageArray() { return imageArray; }
	vector<RenderInfo>& getImageInfoArray() { return imageInfoArray; }
	vector<Movement>& getMovementArray() { return movementArray; }
public:
	void updateStateInfo(int index, PLAYER_STATE state);
};
