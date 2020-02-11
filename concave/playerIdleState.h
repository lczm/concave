#pragma once
#include "iostream"
#include "state.h"

class PlayerIdleState : public State
{
public:
    PlayerIdleState(Level* level);
    ~PlayerIdleState();
    PLAYER_STATE update(float frameTime, int index, Players* players);
    Movement calculateMovement(float frameTime, CoordF position, CoordF destPosition);
};
