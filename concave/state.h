#pragma once
#include "constants.h"
#include "players.h"

class Level;
class State 
{
public:
    PLAYER_STATE state;
    // virtual PLAYER_STATE update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement) = 0;
    // virtual PLAYER_STATE update(float frameTime, int index, Players* players) = 0;
    virtual PLAYER_STATE update(int index, Level* level) = 0;
    Movement calculateMovement(float frameTime, CoordF position, CoordF destPosition);
    void updateFrameNo(float frameTime, int index, Players* players, RenderInfo* renderInfo);
};
#include "level.h"
