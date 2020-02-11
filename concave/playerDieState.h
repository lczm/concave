#pragma once
#include "state.h"

class PlayerDieState : public State
{
public:
    PlayerDieState(Level* level);
    ~PlayerDieState();
    // PLAYER_STATE update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement);
    PLAYER_STATE update(float frameTime, int index, Players* players);
};
