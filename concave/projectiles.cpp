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
	Projectiles::hLineItersArray.resize(capacity);
	Projectiles::vLineItersArray.resize(capacity);
}

void Projectiles::push(CoordF position, Sprite* sprite, Lines hLines, Lines vLines)
{
	LineSetIters hLineIters, vLineIters;
	for (Line line : hLines) hLineIters.push_back(hLineSet.insert(LineI{ line, size }).first);
	for (Line line : vLines) vLineIters.push_back(vLineSet.insert(LineI{ line, size }).first);
	positionArray[size] = position;
	spriteArray[size] = sprite;
	hLineItersArray[size] = hLineIters;
	vLineItersArray[size] = vLineIters;
	size++;
}

void Projectiles::pop(int index)
{
	for (LineSetIter lineIter : hLineItersArray[index]) hLineSet.erase(lineIter);
	for (LineSetIter lineIter : vLineItersArray[index]) vLineSet.erase(lineIter);
	size--;
	positionArray[index] = positionArray[size];
	spriteArray[index] = spriteArray[size];
	hLineItersArray[index] = hLineItersArray[size];
	vLineItersArray[index] = vLineItersArray[size];
}