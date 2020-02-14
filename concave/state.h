#pragma once
#include "iostream"
#include "constants.h"
#include "players.h"
using namespace STATE;

class Level;

// class State 
// {
// public:
//     virtual void update(Level* level, int index) = 0;
//     Movement calculateMovement(float frameTime, CoordF position, CoordF destPosition);
//     void updateFrameNo(float frameTime, int index, Players players, RenderInfo* renderInfo);
//     bool peekChangeState(float frameTime, int index, Players players, 
//         RenderInfo* renderInfo, State* newState, PLAYER state);
// };

// void updateFrameNo(float frameTime, AnimImage*& animImage, int& state, int& frameNo, float& timer,
//                     float& delay, State& fsm, State& newFsm);

struct State 
{
    virtual void operator()(Level* level, int index) = 0;
};

struct PlayerAttackState : State
{
    void operator()(Level* level, int index);
};

struct PlayerDieState : State
{
    void operator()(Level* level, int index);
};

struct PlayerIdleState : State
{
    void operator()(Level* level, int index);
};

struct PlayerWalkState : State
{
    void operator()(Level* level, int index);
};

struct PlayerGetHitState : State
{
    void operator()(Level* level, int index);
};

struct PlayerFireState : State
{
    void operator()(Level* level, int index);
};

#include "level.h"


