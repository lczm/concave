#pragma once
#include "input.h"
#include "constants.h"

class State 
{
public:
    Input* input;
    PLAYER_STATE state;
    virtual PLAYER_STATE update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement) = 0;
};
