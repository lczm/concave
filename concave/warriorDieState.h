#pragma once
#include "state.h"

class WarriorStateManager;

class WarriorDieState : public State
{
private:
    WarriorStateManager* warriorStateManager;

public:
    WarriorDieState();
    ~WarriorDieState();
    UNITSTATE update(Input* input, float frameTime);
    void initialize(WarriorStateManager* warriorStateManager);
    void enter();
    int getFrameNo();
};

#include "warriorStateManager.h"
