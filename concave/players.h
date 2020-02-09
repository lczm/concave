#pragma once
#include "component.h"
#include <cstring>

class Players
{
private:
	int capacity, size;
	CoordF* positions;
	Collision* collisions;
	Render* renders;
public:
	Players(); ~Players();
	void initialize(int capacity);
	void insert(CoordF position, Collision collision, Render render);
	void insert(int size, CoordF* position, Collision* collision, Render* render);
	void pop(int index);
	void setPosition(int index, CoordF position);
	void setCollision(int index, Collision collision);
	void setRender(int index, Render render);
	CoordF getPosition(int index);
	Collision getCollision(int index);
	Render getRender(int index);
public:
	int getSize() { return size; }
};