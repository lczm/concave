#pragma once
#include "state.h"

class PlayerGetHitState : public State
{
public:
    PLAYER_STATE update(int index, Level* level);
};
