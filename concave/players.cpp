#include "players.h"

Players::Players()
{}

Players::~Players()
{}

void Players::initialize(int capacity)
{
	Players::capacity = capacity;
	Players::positionArray.resize(capacity);
	Players::hLinesArray.resize(capacity);
	Players::vLinesArray.resize(capacity);
	Players::spriteArray.resize(capacity);
}

void Players::push(CoordF position, Lines hLines, Lines vLines, Sprite* sprite)
{
	positionArray[size] = position;
	hLinesArray[size] = hLines;
	vLinesArray[size] = vLines;
	spriteArray[size] = sprite;
	size++;
}

void Players::pop(int index)
{
	size--;
	positionArray[index] = positionArray[size];
	hLinesArray[index] = hLinesArray[size];
	hLinesArray[index] = vLinesArray[size];
	spriteArray[index] = spriteArray[size];
}