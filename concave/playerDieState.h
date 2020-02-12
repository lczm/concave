#pragma once
#include "state.h"

class PlayerDieState : public State
{
public:
    PlayerDieState();
    ~PlayerDieState();
    PLAYER_STATE update(int index, Level* level);
};
