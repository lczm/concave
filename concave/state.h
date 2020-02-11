#pragma once
#include "constants.h"
#include "players.h"

class Level;
class State 
{
public:
    Level* level;
    PLAYER_STATE state;
    // virtual PLAYER_STATE update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement) = 0;
    virtual PLAYER_STATE update(float frameTime, int index, Players* players) = 0;
};
#include "level.h"
