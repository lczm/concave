#pragma once
#include "iostream"
#include "state.h"

class PlayerWalkState : public State
{
public:
    PlayerWalkState();
    ~PlayerWalkState();
    PLAYER_STATE update(float frameTime, int index, Level* level);
    bool isAtPosition(CoordF* current, CoordF* destination);
};
