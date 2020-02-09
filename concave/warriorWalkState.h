#pragma once
#include "state.h"
#include <cmath>

class WarriorStateManager;

class WarriorWalkState : public State
{
private:
    WarriorStateManager* warriorStateManager;

public:
    WarriorWalkState();
    ~WarriorWalkState();
    UNITSTATE update(Input* input, float frameTime);
    void initialize(WarriorStateManager* warriorStateManager);
    void enter();
    int getFrameNo();

    bool equalFloat(float a, float b);
};

#include "warriorStateManager.h"
