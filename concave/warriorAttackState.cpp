#include "warriorAttackState.h"

WarriorAttackState::WarriorAttackState()
{
    state = UNITSTATE::ATTACK;
    frameNo = 0;
    endFrame = 16;

    timer = 0;
    delay = float(0.03);
}

WarriorAttackState::~WarriorAttackState()
{
}

UNITSTATE WarriorAttackState::update(Input* input, float frameTime)
{
    if (frameNo == endFrame - 1) {
        updateFrameNo(frameTime);
        return UNITSTATE::IDLE;
    }
    updateFrameNo(frameTime);
    return UNITSTATE::ATTACK;
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

int WarriorAttackState::getFrameNo()
{
    return frameNo;
}