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
    void update(Input* input, float frameTime);
    void initialize(WarriorStateManager* warriorStateManager);
    void enter();
    int getState();
    int getFrameNo();
};

#include "warriorStateManager.h"
