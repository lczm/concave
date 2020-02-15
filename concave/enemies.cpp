#include "enemies.h"

Enemies::Enemies()
{}

Enemies::~Enemies()
{}

void Enemies::initialize(int capacity)
{
	Enemies::capacity = capacity;
	Enemies::positionArray.resize(capacity);
	Enemies::destPositionArray.resize(capacity);
	Enemies::animImageArray.resize(capacity);
	Enemies::stateArray.resize(capacity);
	Enemies::directionArray.resize(capacity);
	Enemies::frameNoArray.resize(capacity);
	Enemies::timerArray.resize(capacity);
	Enemies::delayArray.resize(capacity);
	Enemies::fsmArray.resize(capacity);
	Enemies::rotationArray.resize(capacity);
	Enemies::velocityArray.resize(capacity);
	Enemies::hLinesArray.resize(capacity);
	Enemies::vLinesArray.resize(capacity);
}

void Enemies::push(CoordF position, AnimImage* animImage, int state, FSM fsm, float rotation, float velocity, Lines hLines, Lines vLines)
{
	positionArray[size] = position;
	destPositionArray[size] = CoordF{ 0, 0 };
	animImageArray[size] = animImage;
	stateArray[size] = state;
	directionArray[size] = 0;
	frameNoArray[size] = 0;
	timerArray[size] = 0;
	delayArray[size] = 0.1;
	fsmArray[size] = fsm;
	rotationArray[size] = rotation;
	velocityArray[size] = velocity;
	hLinesArray[size] = hLines;
	vLinesArray[size] = vLines;
	size++;
}

void Enemies::pop(int index)
{
	size--;
	positionArray[index] = positionArray[size];
	destPositionArray[index] = destPositionArray[size];
	animImageArray[index] = animImageArray[size];
	stateArray[index] = stateArray[size];
	directionArray[index] = directionArray[size];
	frameNoArray[index] = frameNoArray[size];
	timerArray[index] = timerArray[size];
	delayArray[index] = delayArray[size];
	fsmArray[index] = fsmArray[size];
	rotationArray[index] = rotationArray[size];
	velocityArray[index] = velocityArray[size];
	hLinesArray[index] = hLinesArray[size];
	vLinesArray[index] = vLinesArray[size];
}