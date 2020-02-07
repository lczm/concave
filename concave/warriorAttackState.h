#pragma once
#include "warrior.h"
#include "warriorState.h"

class WarriorAttackState : public WarriorState
{
private:
    int state;
    int frameNo;
    int endFrame;

    float timer;
    float delay;

public:
    WarriorAttackState();
    ~WarriorAttackState();
    void update(float frameTime);
    void enter();
    int getState();
    int getFrameNo();
};
