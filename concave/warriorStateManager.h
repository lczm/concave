#pragma once
#include "input.h"
#include "state.h"
#include "component.h"
#include "warriorAttackState.h"
#include "warriorIdleState.h"
#include "warriorDieState.h"
#include "warriorWalkState.h"
using namespace std;
using namespace Component;

class WarriorStateManager
{
private:
    float gridX;
    float gridY;

    State* currentState;
    WarriorAttackState* attackState;
    WarriorDieState* dieState;
    WarriorIdleState* idleState;
    WarriorWalkState* walkState;

    Position* positionComponent;

public:
    WarriorStateManager();
    ~WarriorStateManager();
    void update(Input* input, float frameTime);
    int getState();
    int getFrameNo();
    void changeState(int state);

    void setPositionComponent(Position* positionComponent);
    void updatePositionComponent(float screenX, float screenY);
};
