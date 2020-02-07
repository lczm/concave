#include "warriorStateManager.h"

WarriorStateManager::WarriorStateManager()
{
    gridX = 0;
    gridY = 0;

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
        cout << "Changing state to attack" << endl;
    }
    else if (input->isKeyDown('2')) {
        changeState(1);
        cout << "Changing state to die" << endl;
    }
    else if (input->isKeyDown('3')) {
        changeState(2);
        cout << "Changing state to idle" << endl;
    }
    else if (input->isKeyDown('4')) {
        changeState(3);
        cout << "Changing state to walk" << endl;
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

CoordF WarriorStateManager::getGridCoords()
{
    return CoordF { gridX, gridY };
}

