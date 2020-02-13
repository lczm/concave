#pragma once
#include "state.h"

class PlayerFireState : public State
{
public:
    void update(Level* level, int index);
};
