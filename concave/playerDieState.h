#pragma once
#include "state.h"

class PlayerDieState : public State
{
public:
    PLAYER_STATE update(int index, Level* level);
};
