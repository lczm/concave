#pragma once
#include "state.h"

class PlayerAttackState : public State
{
public:
    PLAYER_STATE update(int index, Level* level);
};
