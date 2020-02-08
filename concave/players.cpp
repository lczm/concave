#include "players.h"

Players::Players()
{}

Players::~Players()
{
	delete[] positions;
	delete[] collisions;
	delete[] renders;
}

void Players::initialize(int capacity)
{
	Players::capacity = capacity;
	Players::positions = new CoordF[capacity];
	Players::collisions = new Collision[capacity];
	Players::renders = new Render[capacity];
}

void Players::insert(CoordF position, Collision collision, Render render)
{
	positions[size] = position;
	collisions[size] = collision;
	renders[size] = render;
	size++;
}

void Players::insert(int size, CoordF* positions, Collision* collisions, Render* renders)
{
	memcpy(Players::positions	+ Players::size, 
		positions,	size * sizeof(CoordF));
	memcpy(Players::collisions	+ Players::size, 
		collisions, size * sizeof(Collision));
	memcpy(Players::renders		+ Players::size,
		renders,	size * sizeof(Collision));
	Players::size += size;
}

void Players::pop(int index)
{
	size--;
	positions[index] = positions[size];
	collisions[index] = collisions[size];
	renders[index] = renders[size];
}

void Players::setPosition(int index, CoordF position)
{
	positions[index] = position;
}
void Players::setCollision(int index, Collision collision)
{
	collisions[index] = collision;
}
void Players::setRender(int index, Render render)
{
	renders[index] = render;
}

CoordF Players::getPosition(int index)
{
	return positions[index];
}

Collision Players::getCollision(int index)
{
	return collisions[index];
}

Render Players::getRender(int index)
{
	return renders[index];
}