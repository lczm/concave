#pragma once
#include "component.h"
using namespace Component;

class Tiles
{
private:
	int rows, cols;
	Collision* collisions;
	Render* renders;
public:
	Tiles(); ~Tiles();
	void initialize(int rows, int cols);
	void set(int row, int col, Collision collision, Render render);
	void setCollision(int row, int col, Collision collision);
	void setRender(int row, int col, Render render);
	Collision getCollision(int row, int col);
	Render getRender(int row, int col);
private:
	int mapIndex(int row, int col);
public:
	int getRows() { return rows; }
	int getCols() { return cols; }
};