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
    State* currentState;
    WarriorAttackState* attackState;
    WarriorDieState* dieState;
    WarriorIdleState* idleState;
    WarriorWalkState* walkState;

    // Used to check current vs destination coords
    Position* destinationPositionComponent;

    // Pointers to Warrior.h 
    Position* positionComponent;
    Movement* movementComponent;

public:
    WarriorStateManager();
    ~WarriorStateManager();
    void update(Input* input, float frameTime);
    int getState();
    int getFrameNo();
    void changeState(int state);

    void initializePositionComponent(Position* positionComponent);
    void updatePositionComponent(float screenX, float screenY);
    Position* getPositionComponent();

    void updateDestinationPositionComponent(float screenX, float screenY);
    Position* getDestinationComponent();

    void initializeMovementComponent(Movement* movementComponent);
    void updateMovementComponent(float velocity);
    Movement* getMovementComponent();
};
