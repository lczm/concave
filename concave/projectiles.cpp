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

//#include "projectiles.h"
//
//Projectiles::Projectiles()
//{}
//
//Projectiles::~Projectiles()
//{}
//
//void Projectiles::initialize(int capacity)
//{
//	Projectiles::capacity = capacity;
//	Projectiles::positionArray.resize(capacity);
//	Projectiles::hLineISetItersArray.resize(capacity);
//	Projectiles::vLineISetItersArray.resize(capacity);
//	Projectiles::animImageArray.resize(capacity);
//	Projectiles::frameNoArray.resize(capacity);
//	Projectiles::timerArray.resize(capacity);
//	Projectiles::delayArray.resize(capacity);
//	Projectiles::rotationArray.resize(capacity);
//	Projectiles::dydxArray.resize(capacity);
//}
//
//void Projectiles::push(CoordF position, AnimImage* animImage, Lines hLines, Lines vLines)
//{
//	LineISetIters hLineIters, vLineIters;
//	for (Line line : hLines) hLineIters.push_back(hLineISet.insert(LineI{ line, size }).first);
//	for (Line line : vLines) vLineIters.push_back(vLineISet.insert(LineI{ line, size }).first);
//	positionArray[size] = position;
//	hLineISetItersArray[size] = hLineIters;
//	vLineISetItersArray[size] = vLineIters;
//	animImageArray[size] = animImage;
//	frameNoArray[size] = 0;
//	timerArray[size] = 0;
//	delayArray[size] = float(0.03);
//	rotationArray[size] = 0;
//	dydxArray[size] = CoordF{ 0, 0 };
//	size++;
//}
//
//void Projectiles::pop(int index)
//{
//	for (LineISetIter lineIter : hLineISetItersArray[index]) hLineISet.erase(lineIter);
//	for (LineISetIter lineIter : vLineISetItersArray[index]) vLineISet.erase(lineIter);
//	size--;
//	positionArray[index] = positionArray[size];
//	hLineISetItersArray[index] = hLineISetItersArray[size];
//	vLineISetItersArray[index] = vLineISetItersArray[size];
//	animImageArray[index] = animImageArray[size];
//	frameNoArray[index] = frameNoArray[size];
//	timerArray[index] = timerArray[size];
//	delayArray[index] = delayArray[size];
//	rotationArray[index] = rotationArray[size];
//	dydxArray[index] = dydxArray[size];
//}