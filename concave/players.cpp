#include "players.h"

Players::Players()
{}

Players::~Players()
{}

void Players::initialize(int capacity)
{
	Players::capacity = capacity;
	Players::positionArray.resize(capacity);
	Players::spriteArray.resize(capacity);
	Players::hLinesArray.resize(capacity);
	Players::vLinesArray.resize(capacity);
}

void Players::push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines)
{
	positionArray[size] = position;
	spriteArray[size] = sprite;
	hLinesArray[size] = hLines;
	vLinesArray[size] = vLines;
	size++;
}

void Players::pop(int index)
{
	size--;
	positionArray[index] = positionArray[size];
	spriteArray[index] = spriteArray[size];
	hLinesArray[index] = hLinesArray[size];
	hLinesArray[index] = vLinesArray[size];
}