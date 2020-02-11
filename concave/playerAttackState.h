#pragma once
#include "state.h"

class PlayerAttackState : public State
{
public:
    PlayerAttackState(Input* input);
    ~PlayerAttackState();
    // PLAYER_STATE update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement);
    PLAYER_STATE update(float frameTime, int index, Players* players);
};
