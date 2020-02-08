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
    // TODO : Temporary solution to check the changing of states
    if (input->isKeyDown('1')) {
        changeState(0);
        cout << "Changing state to Attack" << endl;
    }
    else if (input->isKeyDown('2')) {
        changeState(1);
        cout << "Changing state to Die" << endl;
    }
    else if (input->isKeyDown('3')) {
        changeState(2);
        cout << "Changing state to Idle" << endl;
    }
    else if (input->isKeyDown('4')) {
        changeState(3);
        cout << "Changing state to Walk" << endl;
    }
    else {
        currentState->update(input, frameTime);
    }
}

int WarriorStateManager::getState()
{
    return currentState->getState();
}

int WarriorStateManager::getFrameNo()
{
    return currentState->getFrameNo();
}

void WarriorStateManager::changeState(int state)
{
    switch (state) {
    case 0:
        currentState = attackState;
        currentState->enter();
        cout << "Changing state to Attack" << endl;
        break;
    case 1:
        currentState = dieState;
        currentState->enter();
        cout << "Changing state to Die" << endl;
        break;
    case 2:
        currentState = idleState;
        currentState->enter();
        cout << "Changing state to Idle" << endl;
        break;
    case 3:
        currentState = walkState;
        currentState->enter();
        cout << "Changing state to Walk" << endl;
        break;
    default:
        break;
    }
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

void WarriorStateManager::updateMovementComponent(float velocity)
{
    movementComponent->velocity = velocity;
}

Movement* WarriorStateManager::getMovementComponent()
{
    return movementComponent;
}

