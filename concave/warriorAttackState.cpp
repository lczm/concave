#include "warriorAttackState.h"

WarriorAttackState::WarriorAttackState()
{
    state = 0;
    frameNo = 0;
    endFrame = 16;

    timer = 0;
    delay = float(0.03);
}

WarriorAttackState::~WarriorAttackState()
{
}

void WarriorAttackState::update(Input* input, float frameTime)
{
    if (frameNo == endFrame - 1) {
        updateFrameNo(frameTime);
        warriorStateManager->changeState(UNITSTATE::IDLE);
    }
    else {
        updateFrameNo(frameTime);
    }
}

void WarriorAttackState::initialize(WarriorStateManager* warriorStateManager)
{
    WarriorAttackState::warriorStateManager = warriorStateManager;
}

void WarriorAttackState::enter()
{
    frameNo = 0;
    timer = 0;
}

int WarriorAttackState::getState()
{
    return state;
}

int WarriorAttackState::getFrameNo()
{
    return frameNo;
}