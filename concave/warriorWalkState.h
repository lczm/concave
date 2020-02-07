#pragma once
#include "state.h"

class WarriorStateManager;

class WarriorWalkState : public State
{
private:
    WarriorStateManager* warriorStateManager;

public:
    WarriorWalkState();
    ~WarriorWalkState();
    void update(Input* input, float frameTime);
    void initialize(WarriorStateManager* warriorStateManager);
    void enter();
    int getState();
    int getFrameNo();
};

#include "warriorStateManager.h"
