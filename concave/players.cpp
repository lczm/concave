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
	Players::imageArray.resize(capacity);
	Players::hLinesArray.resize(capacity);
	Players::vLinesArray.resize(capacity);
	Players::stateArray.resize(capacity);
	Players::imageArray.resize(capacity);
	Players::imageInfoArray.resize(capacity);
	Players::movementArray.resize(capacity);
	Players::healthArray.resize(capacity);
	Players::manaArray.resize(capacity);
	// Players::positions = new CoordF[capacity];
	// Players::destinationPositions = new CoordF[capacity];
	// Players::hCollisions = new Collision[capacity];
	// Players::vCollisions = new Collision[capacity];
	// Players::renders = new RenderAnim[capacity];
	// Players::rendersInfos = new RenderInfo[capacity];
	// Players::movements = new Movement[capacity];
	// Players::healths = new Health[capacity];
	// Players::manas = new Mana[capacity];
}

void Players::push(CoordF position, AnimImage* image, RenderInfo imageInfo, 
	State* state, Lines hLines, Lines vLines)
{
	positionArray[size] = position;
	destPositionArray[size] = position;
	hLinesArray[size] = hLines;
	vLinesArray[size] = vLines;
	imageArray[size] = image;
	imageInfoArray[size] = imageInfo;
	stateArray[size] = state;
	size++;
}

void Players::pop(int index)
{
	size--;
	positionArray[index] = positionArray[size];
	destPositionArray[index] = destPositionArray[size];
	hLinesArray[index] = hLinesArray[size];
	hLinesArray[index] = vLinesArray[size];
	imageArray[index] = imageArray[size];
	imageInfoArray[index] = imageInfoArray[size];
	stateArray[index] = stateArray[size];
}

void Players::setPosition(int index, CoordF position)
{
	positionArray[index] = position;
}

void Players::setDestPosition(int index, CoordF destPosition)
{
	destPositionArray[index] = destPosition;
}

void Players::setMovement(int index, Movement movement)
{
	movementArray[index] = movement;
}

// void Players::setPosition(int index, CoordF position)
// {
// 	positions[index] = position;
// }
// 
// void Players::setDestPosition(int index, CoordF position)
// {
// 	destinationPositions[index] = position;
// }
// 
// void Players::setCollision(int index, Collision hCollision, Collision vCollision)
// {
// 	hCollisions[index] = hCollision;
// 	vCollisions[index] = vCollision;
// }
// void Players::setRender(int index, RenderAnim render)
// {
// 	renders[index] = render;
// }
// 
// CoordF Players::getPosition(int index)
// {
// 	return positions[index];
// }
// 
// CoordF Players::getDestPositions(int index)
// {
// 	return destinationPositions[index];
// }
// 
// Collision Players::getHCollision(int index)
// {
// 	return hCollisions[index];
// }
// 
// Collision Players::getVCollision(int index)
// {
// 	return vCollisions[index];
// }
// 
// RenderAnim Players::getRender(int index)
// {
// 	return renders[index];
// }
// 
// RenderInfo Players::getRenderInfo(int index)
// {
// 	return rendersInfos[index];
// }
// 
// void Players::setState(int index, State* state)
// {
// 	states[index] = state;
// }
// 
// void Players::setMovement(int index, Movement movement)
// {
//     movements[index] = movement;
//     if (movement.rotation <= 22.5) {
//         rendersInfos[index].direction = DIRECTION8::NORTH;
//     }
//     else if (movement.rotation <= 67.5) {
//         rendersInfos[index].direction = DIRECTION8::NORTH_EAST;
//     }
//     else if (movement.rotation <= 112.5) {
//         rendersInfos[index].direction = DIRECTION8::EAST;
//     }
//     else if (movement.rotation <= 157.5) {
//         rendersInfos[index].direction = DIRECTION8::SOUTH_EAST;
//     }
//     else if (movement.rotation <= 202.5) {
//         rendersInfos[index].direction = DIRECTION8::SOUTH;
//     }
//     else if (movement.rotation <= 247.5) {
//         rendersInfos[index].direction = DIRECTION8::SOUTH_WEST;
//     }
//     else if (movement.rotation <= 292.5) {
//         rendersInfos[index].direction = DIRECTION8::WEST;
//     }
//     else if (movement.rotation <= 337.5) {
//         rendersInfos[index].direction = DIRECTION8::NORTH_WEST;
//     }
//     else {
//         rendersInfos[index].direction = DIRECTION8::NORTH;
//     }
// }
// 
// Movement Players::getMovements(int index)
// {
//     return movements[index];
// }
// 
// Health Players::getHealth(int index)
// {
// 	return healths[index];
// }
// 
// Mana Players::getMana(int index)
// {
// 	return manas[index];
// }