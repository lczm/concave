#pragma once
#include "state.h"

class PlayerFireState : public State
{
public:
    PLAYER_STATE update(int index, Level* level);
};
