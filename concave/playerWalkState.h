#pragma once
#include "iostream"
#include "state.h"

class PlayerWalkState : public State
{
public:
    PLAYER_STATE update(int index, Level* level);
    bool isAtPosition(CoordF current, CoordF destination);
};
