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
	Render* renders;

	Movement* movements;
	vector<State*> states;
public:
	Players(); ~Players();
	void initialize(int capacity);
	void push(CoordF position, Collision hCollision, Collision vCollision, 
		Render render, State* initialState);
	void pop(int index);
	void setPosition(int index, CoordF position);
	void setDestPosition(int index, CoordF position);
	void setCollision(int index, Collision hCollision, Collision vCollision);
	void setRender(int index, Render render);
	CoordF getPosition(int index);
	Collision getHCollision(int index);
	Collision getVCollision(int index);
	Render getRender(int index);
public:
	int getSize() { return size; }
	CoordF* getPositions() { return positions; }
	CoordF* getDestPositions() { return destinationPositions; }
	CoordF getDestPositions(int index) { return destinationPositions[index]; }
	Collision* getHCollisions() { return hCollisions; }
	Collision* getVCollisions() { return vCollisions; }
	Render* getRenders() { return renders; }

	void setState(int index, State* state);
	vector<State*> getStates() { return states; }

	Movement* getMovements() { return movements; }
	// vector<Movement*> getMovements() { return movements; }
};

#include "state.h"