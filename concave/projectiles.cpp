#include "projectiles.h"

Projectiles::Projectiles()
{}

Projectiles::~Projectiles()
{}

void Projectiles::initialize(int capacity)
{
	Projectiles::velocity = 3;
	Projectiles::projSize = 1;
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
	Projectiles::hLinesArray.resize(capacity);
	Projectiles::vLinesArray.resize(capacity);
	// Size of projectiles
	Projectiles::sizeArray.resize(capacity);

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
	velocityArray[size] = Projectiles::velocity;
	// Collision
	hLinesArray[size] = hLines;
	vLinesArray[size] = vLines;
	// Size of projectiles
	sizeArray[size] = Projectiles::projSize;
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
	hLinesArray[index] = hLinesArray[size];
	vLinesArray[index] = vLinesArray[size];
	// Size of projectiles
	sizeArray[index] = sizeArray[size];
}