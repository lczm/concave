#pragma once
#include "iostream"
#include "state.h"

class PlayerWalkState : public State
{
public:
    PlayerWalkState(Input* input);
    ~PlayerWalkState();
    // PLAYER_STATE update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement);
    PLAYER_STATE update(float frameTime, int index, Players* players);
    bool equalFloat(float a, float b) { return fabs(a - b) < 0.01; }
};
