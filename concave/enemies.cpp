#include "enemies.h"

Enemies::Enemies()
{}

Enemies::~Enemies()
{}

void Enemies::initialize(int capacity)
{
	Enemies::capacity = capacity;
	// Position
	Enemies::positionArray.resize(capacity);
	Enemies::destPositionArray.resize(capacity);
	// Animation
	Enemies::animImageArray.resize(capacity);
	Enemies::stateArray.resize(capacity);
	Enemies::directionArray.resize(capacity);
	Enemies::frameNoArray.resize(capacity);
	Enemies::timerArray.resize(capacity);
	Enemies::delayArray.resize(capacity);
	Enemies::fsmArray.resize(capacity);
	// Movement
	Enemies::rotationArray.resize(capacity);
	Enemies::velocityArray.resize(capacity);
	// Collision
	Enemies::hLineISetItersArray.resize(capacity);
	Enemies::vLineISetItersArray.resize(capacity);
	// Attributes
	Enemies::rangeArray.resize(capacity);
	Enemies::healthArray.resize(capacity);
}

void Enemies::push(CoordF position, AnimImage* animImage, int state, FSM fsm, float rotation, float velocity, Lines hLines, Lines vLines)
{
	// Position
	positionArray[size] = position;
	destPositionArray[size] = CoordF{ 0, 0 };
	// Animation
	animImageArray[size] = animImage;
	stateArray[size] = state;
	directionArray[size] = 0;
	frameNoArray[size] = 0;
	timerArray[size] = 0;
	delayArray[size] = 0.1;
	fsmArray[size] = fsm;
	// Movement
	rotationArray[size] = rotation;
	velocityArray[size] = velocity;
	// Collision
	LineISetIters hLineIters, vLineIters;
	for (Line line : hLines) hLineIters.push_back(hLineISet.insert(LineI{ line, size }));
	for (Line line : vLines) vLineIters.push_back(vLineISet.insert(LineI{ line, size }));
	hLineISetItersArray[size] = hLineIters;
	vLineISetItersArray[size] = vLineIters;
	rangeArray[size] = 0.3;
	healthArray[size] = 100;
	size++;
}

void Enemies::pop(int index)
{
	size--;
	// Position
	positionArray[index] = positionArray[size];
	destPositionArray[index] = destPositionArray[size];
	// Animation
	animImageArray[index] = animImageArray[size];
	stateArray[index] = stateArray[size];
	directionArray[index] = directionArray[size];
	frameNoArray[index] = frameNoArray[size];
	timerArray[index] = timerArray[size];
	delayArray[index] = delayArray[size];
	fsmArray[index] = fsmArray[size];
	// Movement
	rotationArray[index] = rotationArray[size];
	velocityArray[index] = velocityArray[size];
	// Collision
	// for (LineISetIter lineIter : hLineISetItersArray[index]) hLineISet.erase(lineIter);
	// for (LineISetIter lineIter : vLineISetItersArray[index]) vLineISet.erase(lineIter);
	hLineISetItersArray[index] = hLineISetItersArray[size];
	vLineISetItersArray[index] = vLineISetItersArray[size];
	rangeArray[index] = rangeArray[size];
	healthArray[index] = healthArray[size];
}