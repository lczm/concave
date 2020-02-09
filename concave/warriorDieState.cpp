#include "warriorDieState.h"

WarriorDieState::WarriorDieState()
{
    state = UNITSTATE::DIE;
    frameNo = 0;
    endFrame = 21;

    timer = 0;
    delay = float(0.03);
}

WarriorDieState::~WarriorDieState()
{
}

UNITSTATE WarriorDieState::update(Input* input, float frameTime)
{
    updateFrameNo(frameTime);
    return UNITSTATE::DIE;
}

void WarriorDieState::initialize(WarriorStateManager* warriorStateManager)
{
    WarriorDieState::warriorStateManager = warriorStateManager;
}

void WarriorDieState::enter()
{
    frameNo = 0;
    timer = 0;
}

int WarriorDieState::getFrameNo()
{
    return frameNo;
}
