#include "playerDieState.h"

PlayerDieState::PlayerDieState(Input* input)
{
    PlayerDieState::input = input;
    state = PLAYER_STATE::DIE;
}

PlayerDieState::~PlayerDieState()
{
}

PLAYER_STATE PlayerDieState::update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement)
{
    return PLAYER_STATE::DIE;
}
