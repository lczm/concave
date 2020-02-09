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
    UNITSTATE update(Input* input, float frameTime);
    void initialize(WarriorStateManager* warriorStateManager);
    void enter();
    int getFrameNo();
};

#include "warriorStateManager.h"
