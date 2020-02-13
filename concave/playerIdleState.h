#pragma once
#include "iostream"
#include "state.h"

class PlayerIdleState : public State
{
public:
    PLAYER_STATE update(int index, Level* level);
};
