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
    void update(Input* input, float frameTime);
    void initialize(WarriorStateManager* warriorStateManager);
    void enter();
    int getState();
    int getFrameNo();
};

#include "warriorStateManager.h"
