#include "players.h"

Players::Players()
{}

Players::~Players()
{}

void Players::initialize(int capacity)
{
	Players::capacity = capacity;
	Players::positionArray.resize(capacity);
	Players::destPositionArray.resize(capacity);
	Players::hLinesArray.resize(capacity);
	Players::vLinesArray.resize(capacity);
	Players::fsmArray.resize(capacity);
	Players::animImageArray.resize(capacity);
	Players::stateArray.resize(capacity);
	Players::directionArray.resize(capacity);
	Players::frameNoArray.resize(capacity);
	Players::timerArray.resize(capacity);
	Players::delayArray.resize(capacity);
	Players::healthArray.resize(capacity);
	Players::manaArray.resize(capacity);
	Players::rotationArray.resize(capacity);
	Players::dxArray.resize(capacity);
	Players::dyArray.resize(capacity);
}

void Players::push(CoordF position, Lines hLines, Lines vLines,
	State* fsm, AnimImage* animImage, int state, int health, int mana)
{
	positionArray[size] = position;
	destPositionArray[size] = position;
	hLinesArray[size] = hLines;
	vLinesArray[size] = vLines;
	fsmArray[size] = fsm;
	animImageArray[size] = animImage;
	stateArray[size] = state;
	frameNoArray[size] = 0;
	directionArray[size] = 0;
	timerArray[size] = 0;
	delayArray[size] = float(0.05);
	healthArray[size] = health;
	manaArray[size] = mana;
	rotationArray[size] = 0;
	dxArray[size] = 0;
	dyArray[size] = 0;
	size++;
}

void Players::pop(int index)
{
	size--;
	positionArray[index] = positionArray[size];
	destPositionArray[index] = destPositionArray[size];
	hLinesArray[index] = hLinesArray[size];
	hLinesArray[index] = vLinesArray[size];
	fsmArray[index] = fsmArray[size];
	animImageArray[index] = animImageArray[size];
	stateArray[index] = stateArray[size];
	frameNoArray[index] = frameNoArray[size];
	timerArray[index] = timerArray[size];
	delayArray[index] = delayArray[size];
	healthArray[index] = healthArray[size];
	manaArray[index] = manaArray[size];
	rotationArray[index] = rotationArray[size];
	dxArray[index] = dxArray[size];
	dyArray[index] = dyArray[size];
}
