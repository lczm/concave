#include "warriorStateManager.h"

WarriorStateManager::WarriorStateManager()
{
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
    currentState->update(input, frameTime);
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
        break;
    case 1:
        currentState = dieState;
        currentState->enter();
        break;
    case 2:
        currentState = idleState;
        currentState->enter();
        break;
    case 3:
        currentState = walkState;
        currentState->enter();
        break;
    default:
        break;
    }
}

