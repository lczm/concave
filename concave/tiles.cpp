#include "tiles.h"

Tiles::Tiles()
{}

Tiles::~Tiles()
{
	delete[] hCollisions;
	delete[] vCollisions;
	delete[] renders;
}

void Tiles::initialize(int rows, int cols)
{
	Tiles::rows = rows;
	Tiles::cols = cols;
	hCollisions = new Collision[rows * cols];
	vCollisions = new Collision[rows * cols];
	renders = new Render[rows * cols];
}

void Tiles::set(int row, int col, Collision hCollision, Collision vCollision, Render render)
{
	setCollision(row, col, hCollision, vCollision);
	setRender(row, col, render);
}

void Tiles::setCollision(int row, int col, Collision hCollision, Collision vCollision)
{
	hCollisions[mapIndex(col, row)] = hCollision; // Done intentionally
	vCollisions[mapIndex(row, col)] = vCollision;
}

void Tiles::setRender(int row, int col, Render render)
{
	renders[mapIndex(row, col)] = render;
}

Collision Tiles::getHCollision(int row, int col)
{
	return hCollisions[mapIndex(col, row)]; // (Again) Done intentionally
}

Collision Tiles::getVCollision(int row, int col)
{
	return vCollisions[mapIndex(row, col)];
}

Render Tiles::getRender(int row, int col)
{
	return renders[mapIndex(row, col)];
}

int Tiles::mapIndex(int row, int col)
{
	return row * cols + col;
}