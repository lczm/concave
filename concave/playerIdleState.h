#pragma once
#include "state.h"

class PlayerIdleState : public State
{
public:
    void update(Level* level, int index);
};
