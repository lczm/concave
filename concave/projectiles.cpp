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
	vector<set<LineI>::iterator> hLineIters, vLineIters;
	for (Line line : hLines) {
		auto lineIter = hLineSet.insert(LineI{ line, size }).first;
		hLineIters.push_back(lineIter);
	}
	//for (Line line : vLines) vLineIters.push_back(vLineSet.insert(LineI{ line, size }).first);
	positionArray[size] = position;
	spriteArray[size] = sprite;
	//hLineItersArray[size] = hLineIters;
	//vLineItersArray[size] = vLineIters;
	size++;
}

void Projectiles::pop(int index)
{
	for (set<LineI>::iterator lineIter : hLineItersArray[index]) hLineSet.erase(lineIter);
	for (set<LineI>::iterator lineIter : vLineItersArray[index]) vLineSet.erase(lineIter);
	size--;
	positionArray[index] = positionArray[size];
	spriteArray[index] = spriteArray[size];
	hLineItersArray[index] = hLineItersArray[size];
	vLineItersArray[index] = vLineItersArray[size];
}