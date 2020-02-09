#pragma once
#include "component.h"

class Tiles
{
private:
	int rows, cols;
	Collision* hCollisions;
	Collision* vCollisions;
	Render* renders;
public:
	Tiles(); ~Tiles();
	void initialize(int rows, int cols);
	void set(int row, int col, Collision hCollision, Collision vCollision, Render render);
	void setCollision(int row, int col, Collision hCollision, Collision vCollision);
	void setRender(int row, int col, Render render);
	Collision getHCollision(int row, int col);
	Collision getVCollision(int row, int col);
	Render getRender(int row, int col);
private:
	int mapIndex(int row, int col);
public:
	int getRows() { return rows; }
	int getCols() { return cols; }
};