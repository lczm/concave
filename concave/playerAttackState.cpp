#include "playerAttackState.h"

PlayerAttackState::PlayerAttackState(Level* level)
{
    PlayerAttackState::level = level;
    state = PLAYER_STATE::ATTACK;
}

PlayerAttackState::~PlayerAttackState()
{
}

PLAYER_STATE PlayerAttackState::update(float frameTime, int index, Players* players)
{
    return PLAYER_STATE::ATTACK;
}
