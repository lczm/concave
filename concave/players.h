#pragma once
#include "component.h"
#include <cstring>
using namespace Component;

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
	CoordF getPosition(int index);
	Collision getCollision(int index);
	Render getRender(int index);
public:
	int getSize() { return size; }
};