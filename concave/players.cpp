#include "players.h"

Players::Players()
{}

Players::~Players()
{}

void Players::initialize(int capacity)
{
	Players::capacity = capacity;
	// Position
	Players::positionArray.resize(capacity);
	Players::destPositionArray.resize(capacity);
	// Animation
	Players::animImageArray.resize(capacity);
	Players::stateArray.resize(capacity);
	Players::directionArray.resize(capacity);
	Players::frameNoArray.resize(capacity);
	Players::timerArray.resize(capacity);
	Players::delayArray.resize(capacity);
	Players::fsmArray.resize(capacity);
	// Movement
	Players::rotationArray.resize(capacity);
	Players::velocityArray.resize(capacity);
	// Collision
	Players::hLinesArray.resize(capacity);
	Players::vLinesArray.resize(capacity);
	// Attributes
	Players::healthArray.resize(capacity);
	Players::maxHealthArray.resize(capacity);
	Players::manaArray.resize(capacity);
	Players::maxManaArray.resize(capacity);
}

void Players::push(CoordF position, AnimImage* animImage, int state, FSM fsm, float rotation, float velocity, Lines hLines, Lines vLines, int health, int maxHealth, int mana, int maxMana)
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
	hLinesArray[size] = hLines;
	vLinesArray[size] = vLines;
	// Attributes
	healthArray[size] = health;
	maxHealthArray[size] = maxHealth;
	manaArray[size] = mana;
	maxManaArray[size] = maxMana;
	size++;
}

//void Players::push(CoordF position, Lines hLines, Lines vLines,
//	State* fsm, AnimImage* animImage, int state, int health, int mana)
//{
//	positionArray[size] = position;
//	destPositionArray[size] = position;
//	hLinesArray[size] = hLines;
//	vLinesArray[size] = vLines;
//	fsmArray[size] = fsm;
//	animImageArray[size] = animImage;
//	stateArray[size] = state;
//	frameNoArray[size] = 0;
//	timerArray[size] = 0;
//	delayArray[size] = float(0.03);
//	healthArray[size] = health;
//	manaArray[size] = mana;
//	rotationArray[size] = 0;
//	dydxArray[size] = CoordF{ 0, 0 };
//	size++;
//}

void Players::pop(int index)
{
	size--;
	// Postion
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
	hLinesArray[index] = hLinesArray[size];
	vLinesArray[index] = vLinesArray[size];
	// Attributes
	healthArray[size] = healthArray[index];
	maxHealthArray[size] = maxHealthArray[index];
	manaArray[size] = manaArray[index];
	maxManaArray[size] = maxManaArray[index];
}
