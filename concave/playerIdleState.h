#pragma once
#include "iostream"
#include "state.h"

class PlayerIdleState : public State
{
public:
    PlayerIdleState();
    ~PlayerIdleState();
    PLAYER_STATE update(float frameTime, int index, Level* level);
};
