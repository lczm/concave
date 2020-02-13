#pragma once
#include "state.h"

class PlayerGetHitState : public State
{
public:
    void update(Level* level, int index);
};
