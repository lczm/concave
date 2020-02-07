#pragma once
#include "input.h"
#include "state.h"
#include "warriorAttackState.h"
#include "warriorIdleState.h"
using namespace std;

class WarriorStateManager
{
private:
    State* currentState;
    WarriorAttackState* attackState;
    WarriorIdleState* idleState;

public:
    WarriorStateManager();
    ~WarriorStateManager();
    void update(Input* input, float frameTime);
    int getState();
    int getFrameNo();
    void changeState(int state);
};
