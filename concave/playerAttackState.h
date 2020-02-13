#pragma once
#include "state.h"

class PlayerAttackState : public State
{
public:
    void update(Level* level, int index);
};
