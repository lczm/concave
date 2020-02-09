#include "warriorStateManager.h"

WarriorStateManager::WarriorStateManager()
{
    destinationPositionComponent = new Position();

    attackState = new WarriorAttackState();
    dieState = new WarriorDieState();
    idleState = new WarriorIdleState();
    walkState = new WarriorWalkState();

    attackState->initialize(this);
    dieState->initialize(this);
    idleState->initialize(this);
    walkState->initialize(this);

    // Default currentState to idleState
    currentState = idleState;
}

WarriorStateManager::~WarriorStateManager()
{
    attackState = NULL;
    dieState = NULL;
    idleState = NULL;
    walkState = NULL;

    delete attackState;
    delete dieState;
    delete idleState;
    delete walkState;
}

void WarriorStateManager::update(Input* input, float frameTime)
{
    UNITSTATE state = currentState->update(input, frameTime);
    if (currentState->state == state) {
        return;
    }

    switch (state) {
    case UNITSTATE::ATTACK:
        currentState = attackState;
        currentState->enter();
        cout << "Changing state to Attack" << endl;
        break;
    case UNITSTATE::DIE:
        currentState = dieState;
        currentState->enter();
        cout << "Changing state to Die" << endl;
        break;
    case UNITSTATE::IDLE:
        currentState = idleState;
        currentState->enter();
        cout << "Changing state to Idle" << endl;
        break;
    case UNITSTATE::WALK:
        currentState = walkState;
        currentState->enter();
        cout << "Changing state to Walk" << endl;
        break;
    }
}

int WarriorStateManager::getFrameNo()
{
    return currentState->getFrameNo();
}

int WarriorStateManager::getState()
{
    switch (currentState->state) {
    case UNITSTATE::ATTACK:
        return 0;
        break;
    case UNITSTATE::DIE:
        return 1;
        break;
    case UNITSTATE::IDLE:
        return 2;
        break;
    case UNITSTATE::WALK:
        return 3;
        break;
    }
}

void WarriorStateManager::initializeDirectionPtr(int* direction)
{
    WarriorStateManager::direction = direction;
}

void WarriorStateManager::initializePositionComponent(Position* positionComponent)
{
    WarriorStateManager::positionComponent = positionComponent;
}

void WarriorStateManager::updatePositionComponent(float screenX, float screenY)
{
    positionComponent->sx = screenX;
    positionComponent->sy = screenY;
}

Position* WarriorStateManager::getPositionComponent()
{
    return positionComponent;
}

void WarriorStateManager::updateDestinationPositionComponent(float screenX, float screenY)
{
    destinationPositionComponent->sx = screenX;
    destinationPositionComponent->sy = screenY;
}

Position* WarriorStateManager::getDestinationComponent()
{
    return destinationPositionComponent;
}

void WarriorStateManager::initializeMovementComponent(Movement* movementComponent)
{
    WarriorStateManager::movementComponent = movementComponent;
}

void WarriorStateManager::updateMovementComponentVelocity(float velocity)
{
    movementComponent->velocity = velocity;
}

void WarriorStateManager::updateMovementComponentRotation(float rotation)
{
    movementComponent->rotation = rotation;
    // When updating the rotation, check for direction updates
    if (rotation <= 22.5) {
        *direction = DIRECTION8::NORTH;
        cout << "Changing direction to North" << endl;
    }
    else if (rotation <= 67.5) {
        *direction = DIRECTION8::NORTH_EAST;
        cout << "Changing direction to North East" << endl;
    }
    else if (rotation <= 112.5) {
        *direction = DIRECTION8::EAST;
        cout << "Changing direction to East" << endl;
    }
    else if (rotation <= 157.5) {
        *direction = DIRECTION8::SOUTH_EAST;
        cout << "Changing direction to South East" << endl;
    }
    else if (rotation <= 202.5) {
        *direction = DIRECTION8::SOUTH;
        cout << "Changing direction to South" << endl;
    }
    else if (rotation <= 247.5) {
        *direction = DIRECTION8::SOUTH_WEST;
        cout << "Changing direction to South West" << endl;
    }
    else if (rotation <= 292.5) {
        *direction = DIRECTION8::WEST;
        cout << "Changing direction to West" << endl;
    }
    else if (rotation <= 337.5) {
        *direction = DIRECTION8::NORTH_WEST;
        cout << "Changing direction to North West" << endl;
    }
    else {
        *direction = DIRECTION8::NORTH;
        cout << "Changing direction to North" << endl;
    }
}

Movement* WarriorStateManager::getMovementComponent()
{
    return movementComponent;
}

