#pragma once
#include "constants.h"
#include "players.h"
using namespace STATE;

class Level;
class State 
{
public:
    virtual void update(Level* level, int index) = 0;
    Movement calculateMovement(float frameTime, CoordF position, CoordF destPosition);
    void updateFrameNo(float frameTime, int index, Players* players, RenderInfo* renderInfo);
};

#include "level.h"


