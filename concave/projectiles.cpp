#include "projectiles.h"

Projectiles::Projectiles()
{}

Projectiles::~Projectiles()
{}

void Projectiles::initialize(int capacity)
{
	Projectiles::capacity = capacity;
	Projectiles::positionArray.resize(capacity);
	Projectiles::spriteArray.resize(capacity);
	Projectiles::hLineISetItersArray.resize(capacity);
	Projectiles::vLineISetItersArray.resize(capacity);
}

void Projectiles::push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines)
{
	LineISetIters hLineIters, vLineIters;
	for (Line line : hLines) hLineIters.push_back(hLineISet.insert(LineI{ line, size }).first);
	for (Line line : vLines) vLineIters.push_back(vLineISet.insert(LineI{ line, size }).first);
	positionArray[size] = position;
	spriteArray[size] = sprite;
	hLineISetItersArray[size] = hLineIters;
	vLineISetItersArray[size] = vLineIters;
	size++;
}

void Projectiles::pop(int index)
{
	for (LineISetIter lineIter : hLineISetItersArray[index]) hLineISet.erase(lineIter);
	for (LineISetIter lineIter : vLineISetItersArray[index]) vLineISet.erase(lineIter);
	size--;
	positionArray[index] = positionArray[size];
	spriteArray[index] = spriteArray[size];
	hLineISetItersArray[index] = hLineISetItersArray[size];
	vLineISetItersArray[index] = vLineISetItersArray[size];
}