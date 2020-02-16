#include "animObjects.h"

AnimObjects::AnimObjects()
{}

AnimObjects::~AnimObjects()
{}

void AnimObjects::initialize(int capacity)
{
	AnimObjects::capacity = capacity;
	// Position
	AnimObjects::positionArray.resize(capacity);
	// Animation
	AnimObjects::animImageArray.resize(capacity);
	AnimObjects::stateArray.resize(capacity);
	AnimObjects::directionArray.resize(capacity);
	AnimObjects::frameNoArray.resize(capacity);
	AnimObjects::timerArray.resize(capacity);
	AnimObjects::delayArray.resize(capacity);
	// Collision
	AnimObjects::hLineISetItersArray.resize(capacity);
	AnimObjects::vLineISetItersArray.resize(capacity);
}

void AnimObjects::push(CoordF position, AnimImage* animImage, int state, int direction, int delay, Lines hLines, Lines vLines)
{
	// Position
	positionArray[size] = position;
	// Animation
	animImageArray[size] = animImage;
	stateArray[size] = state;
	directionArray[size] = direction;
	frameNoArray[size] = 0;
	timerArray[size] = 0;
	delayArray[size] = delay;
	// Collision
	LineISetIters hLineIters, vLineIters;
	for (Line line : hLines) hLineIters.push_back(hLineISet.insert(LineI{ line, size }));
	for (Line line : vLines) vLineIters.push_back(vLineISet.insert(LineI{ line, size }));
	hLineISetItersArray[size] = hLineIters;
	vLineISetItersArray[size] = vLineIters;
	size++;
}

void AnimObjects::pop(int index)
{
	size--;
	// Position
	positionArray[index] = positionArray[size];
	// Animation
	animImageArray[index] = animImageArray[size];
	stateArray[index] = stateArray[size];
	directionArray[index] = directionArray[size];
	frameNoArray[index] = frameNoArray[size];
	timerArray[index] = timerArray[size];
	delayArray[index] = delayArray[size];
	// Collision
	for (LineISetIter lineIter : hLineISetItersArray[index]) hLineISet.erase(lineIter);
	for (LineISetIter lineIter : vLineISetItersArray[index]) vLineISet.erase(lineIter);
	hLineISetItersArray[index] = hLineISetItersArray[size];
	vLineISetItersArray[index] = vLineISetItersArray[size];
}