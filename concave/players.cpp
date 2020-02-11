#include "players.h"

Players::Players()
{}

Players::~Players()
{
	delete[] positions;
	delete[] hCollisions;
	delete[] vCollisions;
	delete[] renders;
}

void Players::initialize(int capacity)
{
	Players::capacity = capacity;
	Players::positions = new CoordF[capacity];
	Players::destinationPositions = new CoordF[capacity];
	Players::hCollisions = new Collision[capacity];
	Players::vCollisions = new Collision[capacity];
	Players::renders = new RenderAnim[capacity];
	Players::rendersInfos = new RenderInfo[capacity];
	Players::movements = new Movement[capacity];
}

void Players::push(CoordF position, Collision hCollision, Collision vCollision, 
	RenderAnim render, RenderInfo renderInfo, State* initialState)
{
	positions[size] = position;
	destinationPositions[size] = position;
	hCollisions[size] = hCollision;
	vCollisions[size] = vCollision;
	renders[size] = render;
	rendersInfos[size] = renderInfo;
	movements[size] = Movement{ 0, 0 };
	states.push_back(initialState);
	size++;
}

void Players::pop(int index)
{
	size--;
	positions[index] = positions[size];
	hCollisions[index] = hCollisions[size];
	hCollisions[index] = vCollisions[size];
	renders[index] = renders[size];
}

void Players::setPosition(int index, CoordF position)
{
	positions[index] = position;
}
void Players::setDestPosition(int index, CoordF position)
{
	destinationPositions[index] = position;
}
void Players::setCollision(int index, Collision hCollision, Collision vCollision)
{
	hCollisions[index] = hCollision;
	vCollisions[index] = vCollision;
}
void Players::setRender(int index, RenderAnim render)
{
	renders[index] = render;
}

CoordF Players::getPosition(int index)
{
	return positions[index];
}

CoordF Players::getDestPositions(int index)
{
	return destinationPositions[index];
}

Collision Players::getHCollision(int index)
{
	return hCollisions[index];
}

Collision Players::getVCollision(int index)
{
	return vCollisions[index];
}

RenderAnim Players::getRender(int index)
{
	return renders[index];
}

RenderInfo Players::getRenderInfo(int index)
{
	return rendersInfos[index];
}

void Players::setState(int index, State* state)
{
	states[index] = state;
}

void Players::setMovement(int index, Movement movement)
{
    movements[index] = movement;
}

Movement Players::getMovements(int index)
{
    return movements[index];
}
