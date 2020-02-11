#pragma once
#include "iostream"
#include "state.h"

class PlayerIdleState : public State
{
public:
    PlayerIdleState(Input* input);
    ~PlayerIdleState();
    PLAYER_STATE update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement);
    PLAYER_STATE update(float frameTime, int index, Players* players);
};
