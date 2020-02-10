#include "playerAttackState.h"

PlayerAttackState::PlayerAttackState(Input* input)
{
    PlayerAttackState::input = input;
    state = PLAYER_STATE::ATTACK;
}

PlayerAttackState::~PlayerAttackState()
{
}

PLAYER_STATE PlayerAttackState::update(float frameTime, CoordF* position, CoordF* destPosition, Movement* movement)
{
    return PLAYER_STATE::ATTACK;
}
