#include "warriorStateManager.h"

WarriorStateManager::WarriorStateManager()
{
    attackState = new WarriorAttackState();
    idleState = new WarriorIdleState();

    attackState->initialize(this);
    idleState->initialize(this);

    // Default currentState to idleState
    currentState = idleState;
}

WarriorStateManager::~WarriorStateManager()
{
    attackState = NULL;
    idleState = NULL;

    delete attackState;
    delete idleState;
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
        break;
    case 2:
        currentState = idleState;
        currentState->enter();
        break;
    case 3:
        break;
    }
}

