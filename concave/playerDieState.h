#pragma once
#include "state.h"

class PlayerDieState : public State
{
public:
    void update(Level* level, int index);
};
