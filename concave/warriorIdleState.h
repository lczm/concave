#pragma once
#include "state.h"

class WarriorStateManager;

class WarriorIdleState : public State
{
private:
    WarriorStateManager* warriorStateManager;

public:
    WarriorIdleState();
    ~WarriorIdleState();
    UNITSTATE update(Input* input, float frameTime);
    void initialize(WarriorStateManager* warriorStateManager);
    void enter();
    int getFrameNo();
};

#include "warriorStateManager.h"
