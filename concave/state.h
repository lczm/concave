#pragma once
#include "input.h"
#include "constants.h"
#include "players.h"

class State 
{
public:
    Input* input;
    PLAYER_STATE state;
    // virtual PLAYER_STATE update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement) = 0;
    virtual PLAYER_STATE update(float frameTime, int index, Players* players) = 0;
};
