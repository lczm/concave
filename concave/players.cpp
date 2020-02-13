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
    if (movement.rotation <= 22.5) {
        imageInfoArray[index].direction = DIRECTION8::NORTH;
    }
    else if (movement.rotation <= 67.5) {
        imageInfoArray[index].direction = DIRECTION8::NORTH_EAST;
    }
    else if (movement.rotation <= 112.5) {
        imageInfoArray[index].direction = DIRECTION8::EAST;
    }
    else if (movement.rotation <= 157.5) {
        imageInfoArray[index].direction = DIRECTION8::SOUTH_EAST;
    }
    else if (movement.rotation <= 202.5) {
        imageInfoArray[index].direction = DIRECTION8::SOUTH;
    }
    else if (movement.rotation <= 247.5) {
        imageInfoArray[index].direction = DIRECTION8::SOUTH_WEST;
    }
    else if (movement.rotation <= 292.5) {
        imageInfoArray[index].direction = DIRECTION8::WEST;
    }
    else if (movement.rotation <= 337.5) {
        imageInfoArray[index].direction = DIRECTION8::NORTH_WEST;
    }
    else {
        imageInfoArray[index].direction = DIRECTION8::NORTH;
    }
}

void Players::setState(int index, State* state)
{
	stateArray[index] = state;
}

void Players::updateStateInfo(int index, PLAYER state)
{
	RenderInfo* renderInfo = &imageInfoArray[index];
	renderInfo->timer = 0;
	renderInfo->frameNo = 0;
	renderInfo->state = state;
}
