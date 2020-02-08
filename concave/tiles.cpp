#include "tiles.h"

Tiles::Tiles()
{}

Tiles::~Tiles()
{
	delete[] collisions;
	delete[] renders;
}

void Tiles::initialize(int rows, int cols)
{
	Tiles::rows = rows;
	Tiles::cols = cols;
	collisions = new Collision[rows * cols];
	renders = new Render[rows * cols];
}

void Tiles::set(int row, int col, Collision collision, Render render)
{
	int index = mapIndex(row, col);
	collisions[index] = collision;
	renders[index] = render;
}

void Tiles::setCollision(int row, int col, Collision collision)
{
	collisions[mapIndex(row, col)] = collision;
}

void Tiles::setRender(int row, int col, Render render)
{
	renders[mapIndex(row, col)] = render;
}

Collision Tiles::getCollision(int row, int col)
{
	return collisions[mapIndex(row, col)];
}

Render Tiles::getRender(int row, int col)
{
	return renders[mapIndex(row, col)];
}

int Tiles::mapIndex(int row, int col)
{
	return row * cols + col;
}