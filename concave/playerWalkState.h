#pragma once
#include "state.h"

class PlayerWalkState : public State
{
public:
    void update(Level* level, int index);
    bool isAtPosition(CoordF current, CoordF destination);
};
