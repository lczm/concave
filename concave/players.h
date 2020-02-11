#pragma once
#include "input.h"
#include "component.h"

class State;

class Players
{
private:
	int capacity, size;
	CoordF* positions;
	CoordF* destinationPositions;
	Collision* hCollisions;
	Collision* vCollisions;
	RenderAnim* renders;
	RenderInfo* rendersInfos;

	vector<State*> states;
    // vector<Movement> movements;
    Movement* movements;
public:
	Players(); ~Players();
	void initialize(int capacity);
	void push(CoordF position, Collision hCollision, Collision vCollision, 
		RenderAnim render, RenderInfo renderInfo, State* initialState);
	void pop(int index);
	void setPosition(int index, CoordF position);
	void setDestPosition(int index, CoordF position);
	void setCollision(int index, Collision hCollision, Collision vCollision);
	void setRender(int index, RenderAnim);
	void setState(int index, State* state);
    void setMovement(int index, Movement movement);
	CoordF getPosition(int index);
	CoordF getDestPositions(int index);
	Collision getHCollision(int index);
	Collision getVCollision(int index);
	RenderAnim getRender(int index);
	RenderInfo getRenderInfo(int index);
    Movement getMovements(int index);
public:
	int getSize() { return size; }
	CoordF* getPositions() { return positions; }
	CoordF* getDestPositions() { return destinationPositions; }
	Collision* getHCollisions() { return hCollisions; }
	Collision* getVCollisions() { return vCollisions; }
	vector<State*> getStates() { return states; }
	RenderAnim* getRenders() { return renders; }
	RenderInfo* getRenderInfos() { return rendersInfos; }
};

#include "state.h"