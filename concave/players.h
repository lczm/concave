#pragma once
#include "component.h"

class Players
{
private:
	int capacity, size;
	CoordF* positions;
	Collision* hCollisions;
	Collision* vCollisions;
	Render* renders;
public:
	Players(); ~Players();
	void initialize(int capacity);
	void push(CoordF position, Collision hCollision, Collision vCollision, Render render);
	void pop(int index);
	void setPosition(int index, CoordF position);
	void setCollision(int index, Collision hCollision, Collision vCollision);
	void setRender(int index, Render render);
	CoordF getPosition(int index);
	Collision getHCollision(int index);
	Collision getVCollision(int index);
	Render getRender(int index);
public:
	int getSize() { return size; }
};