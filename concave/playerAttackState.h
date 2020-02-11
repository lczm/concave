#pragma once
#include "state.h"

class PlayerAttackState : public State
{
public:
    PlayerAttackState();
    ~PlayerAttackState();
    PLAYER_STATE update(float frameTime, int index, Level* level);
};
