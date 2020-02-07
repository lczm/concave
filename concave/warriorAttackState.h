#pragma once
#include "state.h"

class WarriorStateManager;

class WarriorAttackState : public State
{
private:
    WarriorStateManager* warriorStateManager;

public:
    WarriorAttackState();
    ~WarriorAttackState();
    void update(Input* input, float frameTime);
    void initialize(WarriorStateManager* warriorStateManager);
    void enter();
    int getState();
    int getFrameNo();
};

#include "warriorStateManager.h"
