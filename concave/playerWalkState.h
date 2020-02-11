#pragma once
#include "iostream"
#include "state.h"

class PlayerWalkState : public State
{
public:
    PlayerWalkState(Input* input);
    ~PlayerWalkState();
    PLAYER_STATE update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement);
    bool equalFloat(float a, float b) { return fabs(a - b) < 0.1; }
};
