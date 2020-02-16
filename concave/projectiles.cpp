#include "projectiles.h"

Projectiles::Projectiles()
{}

Projectiles::~Projectiles()
{}

void Projectiles::initialize(int capacity)
{
	Projectiles::capacity = capacity;
	// Position
	Projectiles::positionArray.resize(capacity);
	// Animation
	Projectiles::animImageArray.resize(capacity);
	Projectiles::frameNoArray.resize(capacity);
	Projectiles::timerArray.resize(capacity);
	Projectiles::delayArray.resize(capacity);
	// Movement
	Projectiles::rotationArray.resize(capacity);
	Projectiles::velocityArray.resize(capacity);
	// Collision
	Projectiles::hLineISetItersArray.resize(capacity);
	Projectiles::vLineISetItersArray.resize(capacity);
}

void Projectiles::push(CoordF position, AnimImage* animImage, Lines hLines, Lines vLines, float rotation)
{
	// Position
	positionArray[size] = position;
	// Animation
	animImageArray[size] = animImage;
	frameNoArray[size] = 0;
	timerArray[size] = 0;
	delayArray[size] = float(0.03);
	// Movement
	rotationArray[size] = rotation;
	velocityArray[size] = 3;
	// Collision
	LineISetIters hLineIters, vLineIters;
	for (Line line : hLines) hLineIters.push_back(hLineISet.insert(LineI{ line, size }).first);
	for (Line line : vLines) vLineIters.push_back(vLineISet.insert(LineI{ line, size }).first);
	hLineISetItersArray[size] = hLineIters;
	vLineISetItersArray[size] = vLineIters;
	size++;
}

void Projectiles::pop(int index)
{
	size--;
	// Position
	positionArray[index] = positionArray[size];
	// Animation
	animImageArray[index] = animImageArray[size];
	frameNoArray[index] = frameNoArray[size];
	timerArray[index] = timerArray[size];
	delayArray[index] = delayArray[size];
	// Movement
	rotationArray[index] = rotationArray[size];
	velocityArray[index] = velocityArray[size];
	// Collision
	for (LineISetIter lineIter : hLineISetItersArray[index]) hLineISet.erase(lineIter);
	for (LineISetIter lineIter : vLineISetItersArray[index]) vLineISet.erase(lineIter);
	hLineISetItersArray[index] = hLineISetItersArray[size];
	vLineISetItersArray[index] = vLineISetItersArray[size];
}