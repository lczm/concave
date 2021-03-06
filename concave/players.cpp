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
	Players::staticVelocityArray.resize(capacity);
	// Collision
	Players::hLineISetItersArray.resize(capacity);
	Players::vLineISetItersArray.resize(capacity);
	// Attributes
	Players::healthArray.resize(capacity);
	Players::maxHealthArray.resize(capacity);
	Players::manaArray.resize(capacity);
	Players::maxManaArray.resize(capacity);
	Players::noProjArray.resize(capacity);
	Players::damageArray.resize(capacity);
	Players::potionArray.resize(capacity);
}

void Players::push(CoordF position, AnimImage* animImage, int state, FSM fsm, float rotation, float staticVelocity, Lines hLines, Lines vLines, int health, int maxHealth, int mana, int maxMana)
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
	delayArray[size] = 0.01;
	fsmArray[size] = fsm;
	// Movement
	rotationArray[size] = rotation;
	velocityArray[size] = 0;
	staticVelocityArray[size] = staticVelocity;
	// Collision
	LineISetIters hLineIters, vLineIters;
	for (Line line : hLines) hLineIters.push_back(hLineISet.insert(LineI{ line, size }));
	for (Line line : vLines) vLineIters.push_back(vLineISet.insert(LineI{ line, size }));
	hLineISetItersArray[size] = hLineIters;
	vLineISetItersArray[size] = vLineIters;
	// Attributes
	healthArray[size] = health;
	maxHealthArray[size] = maxHealth;
	manaArray[size] = mana;
	maxManaArray[size] = maxMana;
	noProjArray[size] = 1;
	damageArray[size] = 10;
	potionArray[size] =
		vector<Potion>{
		Potion{PotionType::Health, 1},
		Potion{PotionType::Health, 1},
		Potion{PotionType::Mana, 1},
		Potion{PotionType::Mana, 1},
	};
	size++;
}

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
	staticVelocityArray[index] = staticVelocityArray[size];
	// Collision
	for (LineISetIter lineIter : hLineISetItersArray[index]) hLineISet.erase(lineIter);
	for (LineISetIter lineIter : vLineISetItersArray[index]) vLineISet.erase(lineIter);
	hLineISetItersArray[index] = hLineISetItersArray[size];
	vLineISetItersArray[index] = vLineISetItersArray[size];
	// Attributes
	healthArray[index] = healthArray[size];
	maxHealthArray[index] = maxHealthArray[size];
	manaArray[index] = manaArray[size];
	maxManaArray[index] = maxManaArray[size];
	noProjArray[index] = noProjArray[size];
	damageArray[index] = damageArray[size];
	potionArray[index] = potionArray[size];
}
