#include "warriorDieState.h"

WarriorDieState::WarriorDieState()
{
    state = 1;
    frameNo = 0;
    endFrame = 21;

    timer = 0;
    delay = float(0.03);
}

WarriorDieState::~WarriorDieState()
{
}

void WarriorDieState::update(Input* input, float frameTime)
{
    updateFrameNo(frameTime);
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

int WarriorDieState::getState()
{
    return state;
}

int WarriorDieState::getFrameNo()
{
    return frameNo;
}
