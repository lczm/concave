#pragma once
#include "constants.h"
#include "players.h"
using namespace STATE;

class Level;
class State 
{
public:
    virtual void update(Level* level, int index) = 0;
    CoordF getMoveAmount(float frameTime, float rotation);
};

#include "level.h"


