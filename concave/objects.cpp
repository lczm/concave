#include "objects.h"

Objects::Objects()
{}

Objects::~Objects()
{}

void Objects::initialize(int capacity)
{
	Objects::capacity = capacity;
	// Position
	Objects::positionArray.resize(capacity);
	// Sprite
	Objects::spriteArray.resize(capacity);
	// Collision
	Objects::hLineISetItersArray.resize(capacity);
	Objects::vLineISetItersArray.resize(capacity);
}

void Objects::push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines)
{
	// Position
	positionArray[size] = position;
	// Sprite
	spriteArray[size] = sprite;
	// Collision
	LineISetIters hLineIters, vLineIters;
	for (Line line : hLines) hLineIters.push_back(hLineISet.insert(LineI{ line, size }).first);
	for (Line line : vLines) vLineIters.push_back(vLineISet.insert(LineI{ line, size }).first);
	hLineISetItersArray[size] = hLineIters;
	vLineISetItersArray[size] = vLineIters;
	size++;
}

void Objects::pop(int index)
{
	size--;
	// Position
	positionArray[index] = positionArray[size];
	// Sprite
	spriteArray[index] = spriteArray[index];
	// Collision
	for (LineISetIter lineIter : hLineISetItersArray[index]) hLineISet.erase(lineIter);
	for (LineISetIter lineIter : vLineISetItersArray[index]) vLineISet.erase(lineIter);
	hLineISetItersArray[index] = hLineISetItersArray[size];
	vLineISetItersArray[index] = vLineISetItersArray[size];
}