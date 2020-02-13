#pragma once
#include "state.h"

class PlayerAttackState : public State
{
public:
    void update(Level* level, int index);
};

class PlayerDieState : public State
{
public:
    void update(Level* level, int index);
};

class PlayerIdleState : public State
{
public:
    void update(Level* level, int index);
};

class PlayerWalkState : public State
{
public:
    void update(Level* level, int index);
    bool isAtPosition(CoordF current, CoordF destination);
};

class PlayerGetHitState : public State
{
public:
    void update(Level* level, int index);
};

class PlayerFireState : public State
{
public:
    void update(Level* level, int index);
};

