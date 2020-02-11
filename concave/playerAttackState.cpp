#include "playerAttackState.h"

PlayerAttackState::PlayerAttackState()
{
    state = PLAYER_STATE::ATTACK;
}

PlayerAttackState::~PlayerAttackState()
{
}

PLAYER_STATE PlayerAttackState::update(float frameTime, int index, Level* level)
{
    return PLAYER_STATE::ATTACK;
}

